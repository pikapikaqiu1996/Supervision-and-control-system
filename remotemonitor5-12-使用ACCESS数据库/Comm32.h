
#define USECOMM      // yes, we need the COMM API

#include <windows.h>
#include <commdlg.h>
#include <string.h>
#include <io.h>
#include <memory.h>

// constant definitions

#define GWL_NPTTYINFO   0
#define TTYEXTRABYTES   sizeof( LONG )
#define ASCII_XON       0x11
#define ASCII_XOFF      0x13

#define MAXPORTS        4

#define RXQUEUE         4096
#define TXQUEUE         4096

// Flow control flags

#define FC_DTRDSR       0x01
#define FC_RTSCTS       0x02
#define FC_XONXOFF      0x04

// data structures

typedef struct tagCOMMINFO
{
   HANDLE  idComDev ;
   BYTE    bPort;
   BOOL    fConnected, fXonXoff, fLocalEcho, fNewLine, fAutoWrap,
           fUseCNReceive, fDisplayErrors;
   BYTE    bByteSize, bFlowCtrl, bParity, bStopBits ;
   DWORD   dwBaudRate ;
   HANDLE      hPostEvent, hWatchThread, hWatchEvent ;
   DWORD       dwThreadID ;
   OVERLAPPED  osWrite, osRead ;
} COMMINFO, NEAR *NPCOMMINFO ;

// macros ( for easier readability )

#define GETHINST( x )  ((HINSTANCE) GetWindowLong( x, GWL_HINSTANCE ))
#define GETNPTTYINFO( x ) ((NPTTYINFO) GetWindowLong( x, GWL_NPTTYINFO ))
#define SETNPTTYINFO( x, y ) SetWindowLong( x, GWL_NPTTYINFO, (LONG) y )

#define COMDEV( x ) (x -> idComDev)
#define PORT( x )   (x -> bPort)
#define CONNECTED( x ) (x -> fConnected)
#define BYTESIZE( x ) (x -> bByteSize)
#define XONXOFF( x ) (x -> fXonXoff)
#define LOCALECHO( x ) (x -> fLocalEcho)
#define FLOWCTRL( x ) (x -> bFlowCtrl)
#define PARITY( x ) (x -> bParity)
#define STOPBITS( x ) (x -> bStopBits)
#define BAUDRATE( x ) (x -> dwBaudRate)

#define POSTEVENT( x ) (x -> hPostEvent)
#define HTHREAD( x ) (x -> hWatchThread)
#define THREADID( x ) (x -> dwThreadID)
#define WRITE_OS( x ) (x -> osWrite)
#define READ_OS( x ) (x -> osRead)

#define SET_PROP( x, y, z )  SetProp( x, MAKEINTATOM( y ), z )
#define GET_PROP( x, y )     GetProp( x, MAKEINTATOM( y ) )
#define REMOVE_PROP( x, y )  RemoveProp( x, MAKEINTATOM( y ) )


// CRT mappings to NT API

#define _fmemset   memset
#define _fmemmove  memmove

// function prototypes (private)

LRESULT NEAR CreateCommInfo(COMMINFO *,int nPort=1,int nrate = 19200) ;
BOOL NEAR DestroyCommInfo(COMMINFO *) ;
int NEAR ReadCommBlock(COMMINFO *,LPSTR, int ) ;
BOOL NEAR WriteCommBlock(COMMINFO *,LPSTR, DWORD);
BOOL NEAR OpenConnection(COMMINFO *pCommInfo,LPTHREAD_START_ROUTINE lpStartAddress);
BOOL NEAR SetupConnection(COMMINFO *) ;
BOOL NEAR CloseConnection(COMMINFO *) ;
DWORD FAR PASCAL CommWatchProc( LPSTR ) ;

