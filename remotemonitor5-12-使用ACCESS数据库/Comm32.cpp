#include "stdafx.h"

#include "comm32.h"
#include "resource.h"

const short MAXBLOCK=1024;	// 串口每次读入数据的最大长度

unsigned char  InDataBuf[1024];		// 串口缓冲区
int            InDataLen;			// 串口缓冲区中实际数据长度
bool           bPoll=FALSE;
// global stuff
DWORD    BaudTable[] =
         {
            CBR_110, CBR_300, CBR_600, CBR_1200, CBR_2400,
            CBR_4800, CBR_9600, CBR_14400, CBR_19200, CBR_38400,
            CBR_56000, CBR_128000, CBR_256000
         };

DWORD    ParityTable[] =
         {
            NOPARITY, EVENPARITY, ODDPARITY, MARKPARITY, SPACEPARITY
         };

DWORD    StopBitsTable[] =
         {
            ONESTOPBIT, ONE5STOPBITS, TWOSTOPBITS
         };

LRESULT NEAR CreateCommInfo(COMMINFO *pCommInfo,int nPort,int nRate)
{
   // initialize Communication info structure
   COMDEV( pCommInfo )        = 0 ;
   CONNECTED( pCommInfo )     = FALSE ;
   PORT( pCommInfo )          = nPort ; // 1
   BAUDRATE( pCommInfo )      = nRate; //CBR_1200 ;
   BYTESIZE( pCommInfo )      = 8 ;
   //FLOWCTRL( npTTYInfo )      = FC_RTSCTS ;
   FLOWCTRL( pCommInfo )      = 0 ;
   PARITY( pCommInfo )        = NOPARITY ;
   STOPBITS( pCommInfo )      = ONESTOPBIT ;
   XONXOFF( pCommInfo )       = FALSE ;		// 关闭XON和XOFF
   WRITE_OS( pCommInfo ).Offset = 0 ;
   WRITE_OS( pCommInfo ).OffsetHigh = 0 ;
   READ_OS( pCommInfo ).Offset = 0 ;
   READ_OS( pCommInfo ).OffsetHigh = 0 ;
   // create I/O event used for overlapped reads / writes
   READ_OS( pCommInfo ).hEvent = CreateEvent( NULL,    // no security
                                              TRUE,    // explicit reset req
                                              FALSE,   // initial event reset
                                              NULL ) ; // no name
   if (READ_OS( pCommInfo ).hEvent == NULL)
      return ( -1 ) ;

   WRITE_OS( pCommInfo ).hEvent = CreateEvent( NULL,    // no security
                                               TRUE,    // explicit reset req
                                               FALSE,   // initial event reset
                                               NULL) ; // no name
   if (NULL == WRITE_OS( pCommInfo ).hEvent)
   {
      CloseHandle( READ_OS( pCommInfo ).hEvent ) ;
      return ( -1 ) ;
   }
   return 1; 
} 


BOOL NEAR DestroyCommInfo(COMMINFO *pCommInfo)
{
   if (NULL == pCommInfo)
      return ( FALSE ) ;

   // force connection closed (if not already closed)

   if (CONNECTED(pCommInfo))
      CloseConnection(pCommInfo) ;

   // clean up event objects

   CloseHandle( READ_OS( pCommInfo ).hEvent ) ;
   CloseHandle( WRITE_OS( pCommInfo ).hEvent ) ;
   CloseHandle( POSTEVENT( pCommInfo ) ) ;

   return ( TRUE ) ;

} // end of DestroyTTYInfo()


BOOL NEAR OpenConnection(COMMINFO *pCommInfo,LPTHREAD_START_ROUTINE lpStartAddress)
{            
   char       szPort[ 15 ] ;
   BOOL       fRetVal ;
   HCURSOR    hOldCursor, hWaitCursor ;
   HANDLE        hCommWatchThread ;
   DWORD         dwThreadID ;
   COMMTIMEOUTS  CommTimeOuts ;

   // show the hourglass cursor
   hWaitCursor = LoadCursor( NULL, IDC_WAIT ) ;
   hOldCursor = SetCursor( hWaitCursor ) ;


   if (PORT( pCommInfo ) > MAXPORTS)
      lstrcpy( szPort, "\\\\.\\TELNET" ) ;
   else
      wsprintf( szPort, "COM%d", PORT( pCommInfo ) ) ;

   // open COMM device

   if ((COMDEV( pCommInfo ) =
      CreateFile( szPort, GENERIC_READ | GENERIC_WRITE,
                  0,                    // exclusive access
                  NULL,                 // no security attrs
                  OPEN_EXISTING,
                  FILE_ATTRIBUTE_NORMAL | 
                  FILE_FLAG_OVERLAPPED, // overlapped I/O
                  NULL )) == (HANDLE) -1 )
      return ( FALSE ) ;
   else
   {
      // get any early notifications

      SetCommMask( COMDEV( pCommInfo ), EV_RXCHAR ) ;

      // setup device buffers

      SetupComm( COMDEV( pCommInfo ), 4096, 4096 ) ;

      // purge any information in the buffer

      PurgeComm( COMDEV( pCommInfo ), PURGE_TXABORT | PURGE_RXABORT |
                                      PURGE_TXCLEAR | PURGE_RXCLEAR ) ;

      // set up for overlapped I/O
	  
      CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF ;
      CommTimeOuts.ReadTotalTimeoutMultiplier = 0 ;
      CommTimeOuts.ReadTotalTimeoutConstant = 1000 ;
      CommTimeOuts.WriteTotalTimeoutMultiplier = 0 ;
      CommTimeOuts.WriteTotalTimeoutConstant = 1000 ;
      SetCommTimeouts( COMDEV( pCommInfo ), &CommTimeOuts ) ;
   }

   fRetVal = SetupConnection(pCommInfo) ;

   if (fRetVal)
   {
      CONNECTED( pCommInfo ) = TRUE ;

      // Create a secondary thread
      // to watch for an event.

      if (NULL == (hCommWatchThread =
                      CreateThread( (LPSECURITY_ATTRIBUTES) NULL,
                                    0, 
                                    lpStartAddress,//(LPTHREAD_START_ROUTINE)CommWatchProc,
                                    (LPVOID) pCommInfo,
                                    0, &dwThreadID )))
      {
         CONNECTED( pCommInfo ) = FALSE ;
         CloseHandle( COMDEV( pCommInfo ) ) ;
         fRetVal = FALSE ;
      }
      else
      {
         THREADID( pCommInfo ) = dwThreadID ;
         HTHREAD( pCommInfo ) = hCommWatchThread ;

         // assert DTR

         EscapeCommFunction( COMDEV( pCommInfo ), SETDTR ) ;
      }
   }
   else
   {
      CONNECTED( pCommInfo ) = FALSE ;
      CloseHandle( COMDEV( pCommInfo ) ) ;
   }

   // restore cursor

   SetCursor( hOldCursor ) ;
 /*  CString str;
   COleDateTime dt=COleDateTime::GetCurrentTime();
   CFile file;
   file.Open("commlog.txt",CFile::modeNoTruncate|CFile::modeCreate|CFile::modeWrite);
   file.SeekToEnd();
   str="串口打开时间";
   str+=dt.Format("%Y-%m-%d %H:%M:%S");
	LPTSTR p;
	p=str.GetBuffer(1024); 
	file.Write(p,str.GetLength());
	str.ReleaseBuffer();

   file.Close();*/
   return ( fRetVal ) ;

} // end of OpenConnection()


BOOL NEAR SetupConnection(COMMINFO *pCommInfo)
{
   BOOL       fRetVal ;
   BYTE       bSet ;
   DCB        dcb ;

   if (NULL == pCommInfo)
      return ( FALSE ) ;

   dcb.DCBlength = sizeof( DCB ) ;

   GetCommState( COMDEV( pCommInfo ), &dcb ) ;

   dcb.BaudRate = BAUDRATE( pCommInfo ) ;
   dcb.ByteSize = BYTESIZE( pCommInfo ) ;
   dcb.Parity = PARITY( pCommInfo ) ;
   dcb.StopBits = STOPBITS( pCommInfo ) ;

   // setup hardware flow control

   bSet = (BYTE) ((FLOWCTRL( pCommInfo ) & FC_DTRDSR) != 0) ;
   dcb.fOutxDsrFlow = bSet ;
   if (bSet)
      dcb.fDtrControl = DTR_CONTROL_HANDSHAKE ;
   else
      dcb.fDtrControl = DTR_CONTROL_ENABLE ;

   bSet = (BYTE) ((FLOWCTRL( pCommInfo ) & FC_RTSCTS) != 0) ;
	dcb.fOutxCtsFlow = bSet ;
   if (bSet)
      dcb.fRtsControl = RTS_CONTROL_HANDSHAKE ;
   else
      dcb.fRtsControl = RTS_CONTROL_ENABLE ;

   // setup software flow control

   bSet = (BYTE) ((FLOWCTRL( pCommInfo ) & FC_XONXOFF) != 0) ;

   dcb.fInX = dcb.fOutX = bSet ;
   dcb.XonChar = ASCII_XON ;
   dcb.XoffChar = ASCII_XOFF ;
   dcb.XonLim = 100 ;
   dcb.XoffLim = 100 ;

   // other various settings

   dcb.fBinary = TRUE ;
   dcb.fParity = TRUE ;

   fRetVal = SetCommState( COMDEV( pCommInfo ), &dcb ) ;

   return ( fRetVal ) ;

} // end of SetupConnection()


BOOL NEAR CloseConnection( COMMINFO *pCommInfo )
{
   // set connected flag to FALSE

   CONNECTED( pCommInfo ) = FALSE ;

   // disable event notification and wait for thread
   // to halt

   SetCommMask( COMDEV( pCommInfo ), 0 ) ;

   // block until thread has been halted

   while(THREADID(pCommInfo) != 0);

   // kill the focus

   // drop DTR

   EscapeCommFunction( COMDEV( pCommInfo ), CLRDTR ) ;

   // purge any outstanding reads/writes and close device handle

   PurgeComm( COMDEV( pCommInfo ), PURGE_TXABORT | PURGE_RXABORT |
                                   PURGE_TXCLEAR | PURGE_RXCLEAR ) ;
   CloseHandle( COMDEV( pCommInfo ) ) ;
/*   CString str;
   COleDateTime dt=COleDateTime::GetCurrentTime();
   CFile file;
   file.Open("commlog.txt",CFile::modeNoTruncate|CFile::modeCreate|CFile::modeWrite);
   file.SeekToEnd();
   str="串口关闭时间";
   str+=dt.Format("%Y-%m-%d %H:%M:%S");
	LPTSTR p;
	p=str.GetBuffer(1024); 
	file.Write(p,str.GetLength());
	str.ReleaseBuffer();

   file.Close();*/
   return ( TRUE ) ;

} // end of CloseConnection()


int NEAR ReadCommBlock(COMMINFO *pCommInfo,LPSTR lpszBlock, int nMaxLength )
{
	BOOL       fReadStat;
	COMSTAT    ComStat;
	DWORD      dwErrorFlags;
	DWORD      dwLength;
	DWORD      dwError;
//	char       szError[ 10 ];

	// only try to read number of bytes in queue 
	ClearCommError( COMDEV( pCommInfo ), &dwErrorFlags, &ComStat ) ;
	dwLength = min( (DWORD) nMaxLength, ComStat.cbInQue );

	if (dwLength > 0)
	{
		fReadStat = ReadFile( COMDEV( pCommInfo ), lpszBlock,
		                    dwLength, &dwLength, &READ_OS( pCommInfo ) ) ;
		if (!fReadStat)
		{
			if (GetLastError() == ERROR_IO_PENDING)
			{
				while(!GetOverlappedResult( COMDEV( pCommInfo ), 
					&READ_OS( pCommInfo ), &dwLength, TRUE ))
				{
					dwError = GetLastError();
					if(dwError == ERROR_IO_INCOMPLETE)
						// normal result if not finished
						continue;
					else
					{
						ClearCommError( COMDEV( pCommInfo ), &dwErrorFlags, &ComStat ) ;
						break;
					}
						
				}
					
			}
			else
			{
			    dwLength = 0 ;
				ClearCommError( COMDEV(pCommInfo ), &dwErrorFlags, &ComStat ) ;
			}
		}
	}
/*	if(dwLength>0)
	{
		CString str;
		COleDateTime dt=COleDateTime::GetCurrentTime();
		CFile file;
		file.Open("commlog.txt",CFile::modeNoTruncate|CFile::modeCreate|CFile::modeWrite);
		file.SeekToEnd();
		str="读数据时间";
		str+=dt.Format("%Y-%m-%d %H:%M:%S");
		str+="数据内容是:";
		LPTSTR p;
        p=str.GetBuffer(1024); 
		file.Write(p,str.GetLength());
        str.ReleaseBuffer();
		file.Write(lpszBlock,dwLength);
		file.Close();   
	}
*/
    return ( dwLength ) ;

} // end of ReadCommBlock()


BOOL NEAR WriteCommBlock(COMMINFO *pCommInfo,LPSTR lpByte , DWORD dwBytesToWrite)
{
	BOOL        fWriteStat ;
	DWORD       dwBytesWritten ;
	DWORD       dwErrorFlags;
	DWORD   	dwError;
	COMSTAT     ComStat;

	fWriteStat = WriteFile( COMDEV( pCommInfo ), lpByte, dwBytesToWrite,
	                       &dwBytesWritten, &WRITE_OS( pCommInfo ) ) ;
	if (!fWriteStat)
	{
		if(GetLastError() == ERROR_IO_PENDING)
		{
			while(!GetOverlappedResult( COMDEV( pCommInfo ),
				&WRITE_OS( pCommInfo ), &dwBytesWritten, TRUE ))
			{
				dwError = GetLastError();
				if(dwError == ERROR_IO_INCOMPLETE)
					continue;
				else
				{
					ClearCommError( COMDEV( pCommInfo ), &dwErrorFlags, &ComStat ) ;
					break;
				}
			}
		}
		else
		{						 	
			ClearCommError( COMDEV( pCommInfo ), &dwErrorFlags, &ComStat ) ;
			return ( FALSE );
		}
	}

/*	CString str;
	COleDateTime dt=COleDateTime::GetCurrentTime();
	CFile file;
	file.Open("commlog.txt",CFile::modeNoTruncate|CFile::modeCreate|CFile::modeWrite);
	file.SeekToEnd();
	str="写数据时间";
	str+=dt.Format("%Y-%m-%d %H:%M:%S");
	str+="数据内容是:";
	LPTSTR p;
	p=str.GetBuffer(1024); 
	file.Write(p,str.GetLength());
	str.ReleaseBuffer();
	file.Write(lpByte,dwBytesToWrite);
	file.Close(); */ 
	return ( TRUE ) ;

} // end of WriteCommBlock()

DWORD FAR PASCAL CommWatchProc( LPSTR lpData )
{
   DWORD      dwEvtMask ;
   COMMINFO   *pCommInfo = (COMMINFO*) lpData ;
   OVERLAPPED os ;
   int        nLength;

   memset( &os, 0, sizeof( OVERLAPPED ) ) ;

   // create I/O event used for overlapped read

   os.hEvent = CreateEvent( NULL,    // no security
                            TRUE,    // explicit reset req
                            FALSE,   // initial event reset
                            NULL) ;  // no name
   if (os.hEvent == NULL)
   {
      MessageBox( NULL, "Failed to create event for thread!", "TTY Error!",
                  MB_ICONEXCLAMATION | MB_OK ) ;
      return ( FALSE ) ;
   }

   if (!SetCommMask( COMDEV( pCommInfo ), EV_RXCHAR ))
      return ( FALSE ) ;

   while ( CONNECTED( pCommInfo ) )
   {
		dwEvtMask = 0 ;

		WaitCommEvent( COMDEV( pCommInfo ), &dwEvtMask, NULL );

		if ((dwEvtMask & EV_RXCHAR) == EV_RXCHAR)
		{

		   while(bPoll);
		   bPoll=TRUE;
		   do
		   {	
				if(nLength = ReadCommBlock(pCommInfo,(LPSTR)(&InDataBuf[InDataLen]),MAXBLOCK))
					InDataLen+=nLength;
		   }
		   while ( nLength > 0 );

		   bPoll=FALSE;
		}
   }// get rid of event handle

   CloseHandle( os.hEvent );
   // clear information in structure (kind of a "we're done flag")
   THREADID( pCommInfo ) = 0;
   HTHREAD( pCommInfo ) = NULL ;

   return( TRUE );
}// end of CommWatchProc()
