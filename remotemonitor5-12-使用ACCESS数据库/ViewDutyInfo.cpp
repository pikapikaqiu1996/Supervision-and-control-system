// ViewDutyInfo.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "ViewDutyInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewDutyInfo dialog
extern CString strTitleArray[];

extern BOOL bRight[];
CViewDutyInfo::CViewDutyInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CViewDutyInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewDutyInfo)
	m_edit1 = _T("");
	m_edit2 = _T("");
	//}}AFX_DATA_INIT
}


void CViewDutyInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewDutyInfo)
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_MODECOMBO, m_modectl);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewDutyInfo, CDialog)
	//{{AFX_MSG_MAP(CViewDutyInfo)
	ON_CBN_SELCHANGE(IDC_MODECOMBO, OnSelchangeModecombo)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_EXPORT4, OnExport4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewDutyInfo message handlers

BOOL CViewDutyInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    int ntotalItem;
	CString str;

    GetDlgItem(IDC_MYSTATIC)->GetWindowPlacement(&m_mystaticwnd);
    GetDlgItem(IDC_EDIT2)->GetWindowPlacement(&m_edit2wnd);

	m_modectl.AddString("按时间段");
	m_modectl.AddString("按用户名");
    m_modectl.SetCurSel(0);

	CTime time=CTime::GetCurrentTime();
    m_edit1=time.Format("%Y-%m-%d");
    m_edit1+=" 00:00:00";
	m_edit2=time.Format("%Y-%m-%d %H:%M:%S");
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list1.InsertColumn( 0, "用户名", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 1, "接班时间", LVCFMT_LEFT,150, 0 );
    m_list1.InsertColumn( 2, "交班时间", LVCFMT_LEFT,150, 0 );
	m_list1.InsertColumn( 3, "值班记录", LVCFMT_LEFT,200, 0 );
    m_table.m_strSort=_T("[dutytime]");
	
	m_table.m_strFilter=_T("[dutytime] Between #" + m_edit1 + "# AND #" + m_edit2+"#"); 
//	m_table.m_strFilter=_T("[dutytime] Between '" + m_edit1 + "' AND '" + m_edit2+"'"); 
    if(!m_table.IsOpen())
      m_table.Open();
	while(!m_table.IsEOF())
	{
		ntotalItem = m_list1.GetItemCount();
		m_list1.InsertItem(ntotalItem,m_table.m_Name);
		time=m_table.m_dutytime;
		if(time==0) str="";
		else str=time.Format("%Y-%m-%d %H:%M:%S");
		m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(str),0,0,0,NULL);
		time=m_table.m_lefttime;
		if(time==0) str="";
		else str=time.Format("%Y-%m-%d %H:%M:%S");
		m_list1.SetItem(ntotalItem,2,LVIF_TEXT,_T(str),0,0,0,NULL);
		m_list1.SetItem(ntotalItem,3,LVIF_TEXT,_T(m_table.m_dutyrecord),0,0,0,NULL);
        m_table.MoveNext();
	}
	if(!bRight[3])
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
    UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CViewDutyInfo::OnOK() 
{
	// TODO: Add extra validation here
    if(m_table.IsOpen())
      m_table.Close();
	
	CDialog::OnOK();
}

void CViewDutyInfo::OnSelchangeModecombo() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_modectl.GetCurSel();
	if(nIndex==0)//按时间查询
	{
		CTime time=CTime::GetCurrentTime();
		m_edit1=time.Format("%Y-%m-%d");
		m_edit1+=" 00:00:00";
		m_edit2=time.Format("%Y-%m-%d %H:%M:%S");
		
		GetDlgItem(IDC_MYSTATIC)->SetWindowPlacement(&m_mystaticwnd);
		GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&m_edit2wnd);
    }
	else//按用户名查询
	{
		m_edit1="";
		WINDOWPLACEMENT wndplace;
		wndplace.rcNormalPosition.left	    = 2000;
		wndplace.rcNormalPosition.right	    = 2000;
		wndplace.rcNormalPosition.top		= 2000;
		wndplace.rcNormalPosition.bottom	= 2000;
		GetDlgItem(IDC_MYSTATIC)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&wndplace);
	}
	UpdateData(FALSE);
}

void CViewDutyInfo::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(AfxMessageBox("你真想删除当前列表中所有记录吗?",MB_YESNO|MB_ICONWARNING)==IDNO)
		return;
	if(m_modectl.GetCurSel()==0)//按时间查询
	{
	   if(m_edit1==""||m_edit2=="")
	   {
		   MessageBox("没有正确地输入查询条件!请重新输入","提示信息");
		   return;
	   }
       m_table.m_strSort=_T("[dutytime]");
 //      m_table.m_strFilter=_T("[dutytime] Between '" + m_edit1 + "' AND '" + m_edit2+"'"); 
	   m_table.m_strFilter=_T("[dutytime] Between #" + m_edit1 + "# AND #" + m_edit2+"#"); 

       if(m_table.Requery())
	   {
           m_list1.DeleteAllItems();
		   while(!m_table.IsEOF())
		   {
               m_table.Delete();
			   m_table.MoveNext();
		   }
	   }
	}
	else
	{
		if(m_edit1=="")
		{
			MessageBox("没有正确地输入查询条件!请重新输入","提示信息");
			return;
		}
		m_table.m_strSort=_T("[dutytime]");
		m_table.m_strFilter=_T("[Name] = '" + m_edit1 + "'"); 
		if(m_table.Requery())
		{
           m_list1.DeleteAllItems();
		   while(!m_table.IsEOF())
		   {
               m_table.Delete();
			   m_table.MoveNext();
		   }
		}
	}
}

void CViewDutyInfo::OnButton2() //打印
{
	// TODO: Add your control notification handler code here
    int numPages;
	int nTotalRecord=m_list1.GetItemCount();
    if(nTotalRecord==0)
	{
		MessageBox("当前无可打印的记录","提示信息",MB_OK);
		return;
	}
	CDC dc;
	CPrintDialog printDlg(FALSE);
	//利用CPrintDialog 生成打印机设备环境
	if (printDlg.DoModal() == IDCANCEL) // Get printer settings from user 让用户选择打印纸张等
		return;
	dc.Attach(printDlg.GetPrinterDC()); // Attach a printer DC 让HANDLE连接到dc上
	dc.m_bPrinting = TRUE;
	
	TEXTMETRIC textMetric;
	dc.GetTextMetrics(&textMetric);
    m_perCharHeight=(int)(textMetric.tmHeight*1.2);
	m_perlineHeight=(int)((textMetric.tmHeight+textMetric.tmExternalLeading)*1.2);
	m_paperHeight  =dc.GetDeviceCaps(VERTRES);
	m_paperWidth   =dc.GetDeviceCaps(HORZRES), 
	m_linesPerPage=m_paperHeight/m_perlineHeight;
	
	DOCINFO di; // Initialise print document details DOCINFO中有相关的打印信息
	::ZeroMemory (&di, sizeof (DOCINFO));
	di.cbSize = sizeof (DOCINFO);
	di.lpszDocName = strTitleArray[0];//设置标题
	
	BOOL bPrintingOK = dc.StartDoc(&di); // Begin a new print job 开始打印
	
	// Get the printing extents and store in the m_rectDraw field of a 
	// CPrintInfo object
	CPrintInfo Info;//
	Info.m_rectDraw.SetRect(0,0, m_paperWidth,m_paperHeight);//设置范围
	
	if(nTotalRecord<=m_linesPerPage-11)//上下各留4行，标题2行，标题1行
		numPages=1;
	else
	{
		numPages=(nTotalRecord-(m_linesPerPage-11))/(m_linesPerPage-9)+1;
		if((nTotalRecord-(m_linesPerPage-11))%(m_linesPerPage-9)!=0)
			numPages+=1;
	}
	Info.SetMinPage(1);
	Info.SetMaxPage(numPages);

	for (UINT page = Info.GetMinPage(); page<=Info.GetMaxPage()&& bPrintingOK;page++)
	{
		Info.m_nCurPage = page;
	    Print(&dc, &Info); // Call your "Print page" function
	    bPrintingOK = (dc.EndPage() > 0); // end page
	}
//	OnEndPrinting(&dc, &Info); // 结束打印
	
	if (bPrintingOK)
		dc.EndDoc(); // end a print job
	else
		dc.AbortDoc(); // abort job.
	
	dc.Detach(); // detach the printer DC
}
void CViewDutyInfo::DrawGrid(CDC* pDC,int nStartY,int nLine)
{
	int i, nX1,nX2,nY1,nY2,nPerItem;

    nX1=m_perlineHeight*4;
	nX2=m_paperWidth-m_perlineHeight*4;
	for(i=0;i<=nLine;i++)
	{
	   nY1=nY2=nStartY+i*m_perlineHeight;
	   pDC->MoveTo(nX1,nY1);
	   pDC->LineTo(nX2,nY2);
	}
	nY1=nStartY;
	nY2=nStartY+nLine*m_perlineHeight;
    nPerItem=(m_paperWidth-m_perlineHeight*8)/5;
	nX1=nX2=m_perlineHeight*4;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_perlineHeight*4+nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_perlineHeight*4+3*nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_paperWidth-m_perlineHeight*4;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
}

void CViewDutyInfo::DrawTexttoGrid(CDC* pDC,int nStartY,int nStartRecord,int nEndRecord)
{
    CString str;
	int i,nPerItem;
    CRect rc;

    nPerItem=(m_paperWidth-m_perlineHeight*8)/5;
    nStartY+=(int)(0.1*m_perlineHeight);

    rc.top=nStartY;
	rc.bottom=nStartY+m_perlineHeight;

	rc.left=m_perlineHeight*4;
	rc.right=m_perlineHeight*4+nPerItem;
	pDC->DrawText("用户名",&rc,DT_CENTER);

	rc.left=m_perlineHeight*4+nPerItem;
	rc.right=m_perlineHeight*4+3*nPerItem;
	pDC->DrawText("接班时间",&rc,DT_CENTER);

	rc.left=m_perlineHeight*4+3*nPerItem;
	rc.right=m_paperWidth-m_perlineHeight*4;
	pDC->DrawText("交班时间",&rc,DT_CENTER);

	for(i=0;i<nEndRecord-nStartRecord+1;i++)
	{
		rc.top=nStartY+m_perlineHeight*(i+1);
		rc.bottom=nStartY+m_perlineHeight*(i+2);

		rc.left=m_perlineHeight*4;
		rc.right=m_perlineHeight*4+nPerItem;
		str=m_list1.GetItemText(nStartRecord-1+i, 0);
		pDC->DrawText(str,&rc,DT_CENTER);

		rc.left=m_perlineHeight*4+nPerItem;
		rc.right=m_perlineHeight*4+3*nPerItem;
		str=m_list1.GetItemText(nStartRecord-1+i, 1); 
		pDC->DrawText(str,&rc,DT_CENTER);

		rc.left=m_perlineHeight*4+3*nPerItem;
		rc.right=m_paperWidth-m_perlineHeight*4;
		str=m_list1.GetItemText(nStartRecord-1+i, 2); 
		pDC->DrawText(str,&rc,DT_CENTER);

	}
}

void CViewDutyInfo::Print(CDC* pDC, CPrintInfo* pInfo)
{
	//4676*6744
	CFont  newFont;
	CRect rc;
	CFont* pOldFont;
    CString str;

	 pDC->StartPage();
     if(pInfo->m_nCurPage==1)
	 {
		 //打印标题
		 newFont.CreateFont(m_perCharHeight*2,0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH&FF_SWISS,"宋体");
		 pOldFont=(CFont*)pDC->SelectObject(&newFont);
		 rc=pInfo->m_rectDraw;
		 rc.top=m_perlineHeight*4;
		 rc.bottom=m_perlineHeight*6;
		 pDC->DrawText(strTitleArray[0],&rc,DT_CENTER);
		 pDC->SelectObject(pOldFont);
		 newFont.DeleteObject();
	 }
     if(pInfo->m_nCurPage==1)
	 {
		 m_nStartRecord=1;
		 m_nEndRecord=m_linesPerPage-11;
		 if(m_nEndRecord>m_list1.GetItemCount())
            m_nEndRecord=m_list1.GetItemCount();
		 DrawGrid(pDC,m_perlineHeight*6,m_nEndRecord-m_nStartRecord+1+1);
		 DrawTexttoGrid(pDC,m_perlineHeight*6,m_nStartRecord,m_nEndRecord);
	 }
     else
	 {
		 m_nStartRecord=m_linesPerPage-11+(pInfo->m_nCurPage-2)*(m_linesPerPage-9)+1;
		 m_nEndRecord=m_nStartRecord+m_linesPerPage-9;
		 if(m_nEndRecord>m_list1.GetItemCount())
            m_nEndRecord=m_list1.GetItemCount();
		 DrawGrid(pDC,m_perlineHeight*4,m_nEndRecord-m_nStartRecord+1+1);
		 DrawTexttoGrid(pDC,m_perlineHeight*4,m_nStartRecord,m_nEndRecord);
	 }
	//打印页码
	newFont.CreateFont((int)(m_perCharHeight*0.7),0,0,0,FW_NORMAL,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH&FF_SWISS,"宋体");
	pOldFont=(CFont*)pDC->SelectObject(&newFont);
	str.Format("-第%d页-",pInfo->m_nCurPage);
	pDC->TextOut(m_paperWidth-m_perlineHeight*6,(m_paperHeight-m_perlineHeight*4),str);
	pDC->SelectObject(pOldFont);
	newFont.DeleteObject();

}
void CViewDutyInfo::OnButton1() //查询
{
	// TODO: Add your control notification handler code here
	CString str;
	int ntotalItem;
	CTime time;

	UpdateData(TRUE);
	if(m_modectl.GetCurSel()==0)//按时间查询
	{
	   if(m_edit1==""||m_edit2=="")
	   {
		   MessageBox("没有正确地输入查询条件!请重新输入","提示信息");
		   return;
	   }
       m_table.m_strSort=_T("[dutytime]");
     //  m_table.m_strFilter=_T("[dutytime] Between '" + m_edit1 + "' AND '" + m_edit2+"'"); 
	   m_table.m_strFilter=_T("[dutytime] Between #" + m_edit1 + "# AND #" + m_edit2+"#"); 

       if(m_table.Requery())
	   {
           m_list1.DeleteAllItems();
		   while(!m_table.IsEOF())
		   {
			   ntotalItem = m_list1.GetItemCount();
			   m_list1.InsertItem(ntotalItem,m_table.m_Name);
			   time=m_table.m_dutytime;
		       if(time==0) str="";
		       else str=time.Format("%Y-%m-%d %H:%M:%S");
		       m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(str),0,0,0,NULL);
		       time=m_table.m_lefttime;
		       if(time==0) str="";
		       else str=time.Format("%Y-%m-%d %H:%M:%S");
			   m_list1.SetItem(ntotalItem,2,LVIF_TEXT,_T(str),0,0,0,NULL);
			   m_list1.SetItem(ntotalItem,3,LVIF_TEXT,_T(m_table.m_dutyrecord),0,0,0,NULL);
			   m_table.MoveNext();
		   }
	   }
	}
	else
	{
		if(m_edit1=="")
		{
			MessageBox("没有正确地输入查询条件!请重新输入","提示信息");
			return;
		}
		m_table.m_strSort=_T("[dutytime]");
		m_table.m_strFilter=_T("[Name] = '" + m_edit1 + "'"); 
		if(m_table.Requery())
		{
			m_list1.DeleteAllItems();
			while(!m_table.IsEOF())
			{
				ntotalItem = m_list1.GetItemCount();
				m_list1.InsertItem(ntotalItem,m_table.m_Name);
				time=m_table.m_dutytime;
				if(time==0)  str="";
				else str=time.Format("%Y-%m-%d %H:%M:%S");
				m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(str),0,0,0,NULL);
				time=m_table.m_lefttime;
				if(time==0)  str="";
                else str=time.Format("%Y-%m-%d %H:%M:%S");
				m_list1.SetItem(ntotalItem,2,LVIF_TEXT,_T(str),0,0,0,NULL);
				m_list1.SetItem(ntotalItem,3,LVIF_TEXT,_T(m_table.m_dutyrecord),0,0,0,NULL);
				m_table.MoveNext();
			}
		}
	}	
}

void CViewDutyInfo::OnExport4() 
{
	// TODO: Add your control notification handler code here
	if(!bHasExcelDriver())
	{
		MessageBox("没有安装Microsoft Excel Driver!","提示信息");
		return;
	}
	CString strPathname;

    CFileDialog filesavebox(FALSE,"xls",/*"default.xls"*/NULL,OFN_HIDEREADONLY/*|OFN_OVERWRITEPROMPT*/,"Excel文件(*.xls)|*.xls|",NULL);	
	if(filesavebox.DoModal()!=IDOK) return;
	strPathname=filesavebox.GetPathName();
	CDatabase database;
	CString   sDriver="Microsoft Excel Driver (*.xls)";
	CString sSql;
	CString str;
	int i,nTotalItem,j;
	TRY
	{
		sSql.Format("DRIVER={%s};DSN=;FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver,strPathname,strPathname);
		if(database.OpenEx(sSql,CDatabase::noOdbcDialog))
		{
    		sSql="CREATE TABLE 值班记录表 (用户名 TEXT,接班时间 TEXT,交班时间 TEXT,值班记录 TEXT)";
			database.ExecuteSQL(sSql);
			str="(用户名,接班时间,交班时间,值班记录)";
            nTotalItem=m_list1.GetItemCount();
			for(i=0;i<nTotalItem;i++)
			{
				sSql="INSERT INTO 值班记录表 ";
				sSql+=str;
				sSql+=" VALUES(";
				for(j=0;j<4;j++)
				{
					sSql+="'";
					sSql+=m_list1.GetItemText(i,j);
					if(j<3)
					  sSql+="',";
					else
					  sSql+="'";
				}
				sSql+=")";
				database.ExecuteSQL(sSql);
			}
		}
        database.Close();
	}
	CATCH_ALL(e)
	{
		
		TRACE0("%s","不能对表重新写入!");
	}
	END_CATCH_ALL;				
}
BOOL CViewDutyInfo::bHasExcelDriver()
{
    char szBuf[2001];
	WORD cbBufMax=2000;
	WORD cbBufOut;
	char* pszBuf=szBuf;
	CString sDriver;
	if(!SQLGetInstalledDrivers(szBuf,cbBufMax,&cbBufOut)) return FALSE;
	do
	{
		if(strstr(pszBuf,"Excel")!=0)
		   return TRUE;
		pszBuf=strchr(pszBuf,'\0')+1;
	}
	while(pszBuf[0]!='\0');
	return FALSE;
}
