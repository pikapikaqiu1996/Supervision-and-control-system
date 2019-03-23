// ViewCableAlarmInfo.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "ViewCableAlarmInfo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewCableAlarmInfo dialog
extern BOOL bRight[];
extern CString strAlarmType[];
extern CString strTitleArray[];

CViewCableAlarmInfo::CViewCableAlarmInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CViewCableAlarmInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewCableAlarmInfo)
	m_edit1 = _T("");
	m_edit2 = _T("");
	m_edit3 = 0;
	//}}AFX_DATA_INIT
}


void CViewCableAlarmInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewCableAlarmInfo)
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDV_MinMaxInt(pDX, m_edit3, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewCableAlarmInfo, CDialog)
	//{{AFX_MSG_MAP(CViewCableAlarmInfo)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_EXPORT3, OnExport3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewCableAlarmInfo message handlers

BOOL CViewCableAlarmInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str;
    int i;
    GetDlgItem(IDC_MYSTATIC)->GetWindowPlacement(&m_mystaticwnd);
    GetDlgItem(IDC_EDIT1)->GetWindowPlacement(&m_editwnd[0]);
    GetDlgItem(IDC_EDIT2)->GetWindowPlacement(&m_editwnd[1]);
    GetDlgItem(IDC_EDIT3)->GetWindowPlacement(&m_editwnd[2]);
    GetDlgItem(IDC_COMBO2)->GetWindowPlacement(&m_combownd);

	WINDOWPLACEMENT wndplace;
	wndplace.rcNormalPosition.left	    = 2000;
	wndplace.rcNormalPosition.right	    = 2000;
	wndplace.rcNormalPosition.top		= 2000;
	wndplace.rcNormalPosition.bottom	= 2000;
	GetDlgItem(IDC_EDIT3)->SetWindowPlacement(&wndplace);
	GetDlgItem(IDC_COMBO2)->SetWindowPlacement(&wndplace);

	m_combo1.AddString("按时间段");
	m_combo1.AddString("按分机号");
	m_combo1.AddString("按报警类型");
    m_combo1.SetCurSel(0);

	for(i=0;i<11;i++)
       m_combo2.AddString(strAlarmType[i]);

    m_combo2.SetCurSel(0);

	CTime time=CTime::GetCurrentTime();
    m_edit1=time.Format("%Y-%m-%d");
    m_edit1+=" 00:00:00";
	m_edit2=time.Format("%Y-%m-%d %H:%M:%S");
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list1.InsertColumn( 0, "分机号", LVCFMT_LEFT,80, 0 );
	m_list1.InsertColumn( 1, "分机名", LVCFMT_LEFT,80, 0 );
	m_list1.InsertColumn( 2, "电缆号", LVCFMT_LEFT,80, 0 );
	m_list1.InsertColumn( 3, "报警类型", LVCFMT_LEFT,80, 0 );
    m_list1.InsertColumn( 4, "距  离", LVCFMT_LEFT,55, 0 );
    m_list1.InsertColumn( 5, "报警时间", LVCFMT_LEFT,180, 0 );
//    m_list1.InsertColumn( 6, "恢复时间", LVCFMT_LEFT,160, 0 );
    m_table.m_strSort=_T("[alarmtime]");
//    m_table.m_strFilter=_T("[alarmtime] Between '" + m_edit1 + "' AND '" + m_edit2+"'"); 
    m_table.m_strFilter=_T("[alarmtime] Between #" + m_edit1 + "# AND #" + m_edit2+"#"); 
	if(!m_table.IsOpen())
      m_table.Open();
    Insertlist1();
	if(!bRight[3])
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
    UpdateData(FALSE);		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CViewCableAlarmInfo::Insertlist1()
{
	int ntotalItem;
	CString str;
    CTime time;
	while(!m_table.IsEOF())
	{
		ntotalItem = m_list1.GetItemCount();
		str.Format("%3.3d",m_table.m_cablenumber/100);
		m_list1.InsertItem(ntotalItem,str);

        str=m_table.m_fenjiname;
		m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(str),0,0,0,NULL);

		str.Format("%d",m_table.m_cablenumber%100);
		m_list1.SetItem(ntotalItem,2,LVIF_TEXT,_T(str),0,0,0,NULL);

		str=strAlarmType[m_table.m_alarmtype-1];
		m_list1.SetItem(ntotalItem,3,LVIF_TEXT,_T(str),0,0,0,NULL);

        str.Format("%d",m_table.m_distant);
		m_list1.SetItem(ntotalItem,4,LVIF_TEXT,_T(str),0,0,0,NULL);

		time=m_table.m_alarmtime;
		if(time==0) str="";
//		else str=time.Format("%Y-%m-%d %H:%M:%S");
		else str=time.Format("%Y-%m-%d %H:%M");
		m_list1.SetItem(ntotalItem,5,LVIF_TEXT,_T(str),0,0,0,NULL);
//		time=m_table.m_recovertime;
//		if(time==0) str="";
//		else str=time.Format("%Y-%m-%d %H:%M:%S");
//		else str=time.Format("%Y-%m-%d %H:%M");
//		m_list1.SetItem(ntotalItem,6,LVIF_TEXT,_T(str),0,0,0,NULL);
        m_table.MoveNext();
	}
}
void CViewCableAlarmInfo::OnOK() 
{
	// TODO: Add extra validation here
    if(m_table.IsOpen())
      m_table.Close();
	
	CDialog::OnOK();
}

void CViewCableAlarmInfo::OnButton1() //查询
{
	// TODO: Add your control notification handler code here
	CString str1,str2;
	UpdateData(TRUE);
	int nIndex=m_combo1.GetCurSel();
	if(nIndex==0)//按时间查询
	{
	   if(m_edit1==""||m_edit2=="")
	   {
		   MessageBox("没有正确地输入查询条件!请重新输入","提示信息");
		   return;
	   }
       m_table.m_strSort=_T("[alarmtime]");
//       m_table.m_strFilter=_T("[alarmtime] Between '" + m_edit1 + "' AND '" + m_edit2+"'"); 
       m_table.m_strFilter=_T("[alarmtime] Between #" + m_edit1 + "# AND #" + m_edit2+"#"); 
	   if(m_table.Requery())
	   {
           m_list1.DeleteAllItems();
		   Insertlist1();
	   }
	}
	else  if(nIndex==1)//按分机号查询
	{
		if(m_edit3<0||m_edit3>999)
		{
		   MessageBox("没有正确地输入分机号!请重新输入","提示信息");
		   return;
		}
		m_table.m_strSort=_T("[alarmtime]");
		str1.Format("%d",m_edit3*100);
		str2.Format("%d",m_edit3*100+16);
        m_table.m_strFilter=_T("[cablenumber] Between " + str1 + " AND " + str2); 
		if(m_table.Requery())
		{
			m_list1.DeleteAllItems();
			Insertlist1();
		}
	}
	else//按报警类型查询
	{
		m_table.m_strSort=_T("[alarmtime]");
		str1.Format("%d",m_combo2.GetCurSel()+1);
		m_table.m_strFilter=_T("[alarmtype] = " + str1); 
		if(m_table.Requery())
		{
			m_list1.DeleteAllItems();
			Insertlist1();
		}
	}
}

void CViewCableAlarmInfo::OnButton2() //打印
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
	di.lpszDocName = strTitleArray[1];//设置标题
	
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
void CViewCableAlarmInfo::DrawGrid(CDC* pDC,int nStartY,int nLine)
{
	int i, nX1,nX2,nY1,nY2,nPerItem;

    nX1=m_perlineHeight*3;
	nX2=m_paperWidth-m_perlineHeight*3;
	for(i=0;i<=nLine;i++)
	{
	   nY1=nY2=nStartY+i*m_perlineHeight;
	   pDC->MoveTo(nX1,nY1);
	   pDC->LineTo(nX2,nY2);
	}
	nY1=nStartY;
	nY2=nStartY+nLine*m_perlineHeight;
    nPerItem=(m_paperWidth-m_perlineHeight*6)/10;
	nX1=nX2=m_perlineHeight*3;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_perlineHeight*3+nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_perlineHeight*3+3*nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_perlineHeight*3+4*nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_perlineHeight*3+6*nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_perlineHeight*3+7*nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);

/*	nX1=nX2=m_perlineHeight*3+10*nPerItem;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);
	nX1=nX2=m_paperWidth-m_perlineHeight*3;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);*/	
	nX1=nX2=m_paperWidth-m_perlineHeight*3;
	pDC->MoveTo(nX1,nY1);
	pDC->LineTo(nX2,nY2);

}

void CViewCableAlarmInfo::DrawTexttoGrid(CDC* pDC,int nStartY,int nStartRecord,int nEndRecord)
{
    CString str;
	int i,nPerItem;
    CRect rc;

    nPerItem=(m_paperWidth-m_perlineHeight*6)/10;
    nStartY+=(int)(0.1*m_perlineHeight);

    rc.top=nStartY;
	rc.bottom=nStartY+m_perlineHeight;

	rc.left=m_perlineHeight*3;
	rc.right=m_perlineHeight*3+nPerItem;
	pDC->DrawText("分机号",&rc,DT_CENTER);

	rc.left=m_perlineHeight*3+nPerItem;
	rc.right=m_perlineHeight*3+3*nPerItem;
	pDC->DrawText("分机名",&rc,DT_CENTER);


	rc.left=m_perlineHeight*3+3*nPerItem;
	rc.right=m_perlineHeight*3+4*nPerItem;
	pDC->DrawText("电缆号",&rc,DT_CENTER);

	rc.left=m_perlineHeight*3+4*nPerItem;
	rc.right=m_perlineHeight*3+6*nPerItem;
	pDC->DrawText("报警类型",&rc,DT_CENTER);

	rc.left=m_perlineHeight*3+6*nPerItem;
	rc.right=m_perlineHeight*3+7*nPerItem;
	pDC->DrawText("距离",&rc,DT_CENTER);

	rc.left=m_perlineHeight*3+7*nPerItem;
//	rc.right=m_perlineHeight*3+10*nPerItem;
	rc.right=m_paperWidth-m_perlineHeight*4;
	pDC->DrawText("报警时间",&rc,DT_CENTER);

/*	rc.left=m_perlineHeight*3+10*nPerItem;
	rc.right=m_paperWidth-m_perlineHeight*4;
	pDC->DrawText("恢复时间",&rc,DT_CENTER);
*/
	for(i=0;i<nEndRecord-nStartRecord+1;i++)
	{
		rc.top=nStartY+m_perlineHeight*(i+1);
		rc.bottom=nStartY+m_perlineHeight*(i+2);

		rc.left=m_perlineHeight*3;
		rc.right=m_perlineHeight*3+nPerItem;
		str=m_list1.GetItemText(nStartRecord-1+i, 0);
		pDC->DrawText(str,&rc,DT_CENTER);

		rc.left=m_perlineHeight*3+nPerItem;
		rc.right=m_perlineHeight*3+3*nPerItem;
		str=m_list1.GetItemText(nStartRecord-1+i, 1);
		pDC->DrawText(str,&rc,DT_CENTER);

		rc.left=m_perlineHeight*3+3*nPerItem;
		rc.right=m_perlineHeight*3+4*nPerItem;
		str=m_list1.GetItemText(nStartRecord-1+i, 2);
		pDC->DrawText(str,&rc,DT_CENTER);

		rc.left=m_perlineHeight*3+4*nPerItem;
		rc.right=m_perlineHeight*3+6*nPerItem;
		str=m_list1.GetItemText(nStartRecord-1+i, 3);
		pDC->DrawText(str,&rc,DT_CENTER);

		rc.left=m_perlineHeight*3+6*nPerItem;
		rc.right=m_perlineHeight*3+7*nPerItem;
		str=m_list1.GetItemText(nStartRecord-1+i, 4);
		pDC->DrawText(str,&rc,DT_CENTER);

		rc.left=m_perlineHeight*3+7*nPerItem;
//		rc.right=m_perlineHeight*3+10*nPerItem;
		rc.right=m_paperWidth-m_perlineHeight*3;
		str=m_list1.GetItemText(nStartRecord-1+i, 5);
		pDC->DrawText(str,&rc,DT_CENTER);

/*		rc.left=m_perlineHeight*3+10*nPerItem;
		rc.right=m_paperWidth-m_perlineHeight*3;
		str=m_list1.GetItemText(nStartRecord-1+i, 6);
		pDC->DrawText(str,&rc,DT_CENTER);
*/
	}
}

void CViewCableAlarmInfo::Print(CDC* pDC, CPrintInfo* pInfo)
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
		 pDC->DrawText(strTitleArray[1],&rc,DT_CENTER);
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
void CViewCableAlarmInfo::OnButton3() //删除
{
	// TODO: Add your control notification handler code here
	CString str1,str2;
	UpdateData(TRUE);
	if(AfxMessageBox("你真想删除当前列表中所有记录吗?",MB_YESNO|MB_ICONWARNING)==IDNO)
		return;
	if(m_combo1.GetCurSel()==0)//按时间查询
	{
	   if(m_edit1==""||m_edit2=="")
	   {
		   MessageBox("没有正确地输入查询条件!请重新输入","提示信息");
		   return;
	   }
       m_table.m_strSort=_T("[alarmtime]");
//       m_table.m_strFilter=_T("[alarmtime] Between '" + m_edit1 + "' AND '" + m_edit2+"'"); 
       m_table.m_strFilter=_T("[alarmtime] Between #" + m_edit1 + "# AND #" + m_edit2+"#"); 
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
	else if(m_combo1.GetCurSel()==1)
	{
		if(m_edit3<0||m_edit3>999)
		{
		   MessageBox("没有正确地输入分机号!请重新输入","提示信息");
		   return;
		}
		m_table.m_strSort=_T("[alarmtime]");
		str1.Format("%d",m_edit3*100);
		str2.Format("%d",m_edit3*100+16);
        m_table.m_strFilter=_T("[cablenumber] Between " + str1 + " AND " + str2); 
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
		m_table.m_strSort=_T("[alarmtime]");
		str1.Format("%d",m_combo2.GetCurSel()+1);
		m_table.m_strFilter=_T("[alarmtype] = " + str1); 
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

void CViewCableAlarmInfo::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_combo1.GetCurSel();
	if(nIndex==0)//按时间查询
	{
		CTime time=CTime::GetCurrentTime();
		m_edit1=time.Format("%Y-%m-%d");
		m_edit1+=" 00:00:00";
		m_edit2=time.Format("%Y-%m-%d %H:%M:%S");
		
		GetDlgItem(IDC_MYSTATIC)->SetWindowPlacement(&m_mystaticwnd);
		GetDlgItem(IDC_EDIT1)->SetWindowPlacement(&m_editwnd[0]);
		GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&m_editwnd[1]);

		WINDOWPLACEMENT wndplace;
		wndplace.rcNormalPosition.left	    = 2000;
		wndplace.rcNormalPosition.right	    = 2000;
		wndplace.rcNormalPosition.top		= 2000;
		wndplace.rcNormalPosition.bottom	= 2000;
		GetDlgItem(IDC_EDIT3)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_COMBO2)->SetWindowPlacement(&wndplace);

    }
	else if(nIndex==1)//按分机号查询
	{
		m_edit3=0;
		GetDlgItem(IDC_EDIT3)->SetWindowPlacement(&m_editwnd[2]);

		WINDOWPLACEMENT wndplace;
		wndplace.rcNormalPosition.left	    = 2000;
		wndplace.rcNormalPosition.right	    = 2000;
		wndplace.rcNormalPosition.top		= 2000;
		wndplace.rcNormalPosition.bottom	= 2000;
		GetDlgItem(IDC_MYSTATIC)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT1)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_COMBO2)->SetWindowPlacement(&wndplace);

	}
    else//按报警类型
	{
		m_combo2.SetCurSel(0);
		GetDlgItem(IDC_COMBO2)->SetWindowPlacement(&m_combownd);
		WINDOWPLACEMENT wndplace;
		wndplace.rcNormalPosition.left	    = 2000;
		wndplace.rcNormalPosition.right	    = 2000;
		wndplace.rcNormalPosition.top		= 2000;
		wndplace.rcNormalPosition.bottom	= 2000;
		GetDlgItem(IDC_MYSTATIC)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT1)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT3)->SetWindowPlacement(&wndplace);
	}


	UpdateData(FALSE);		
}

void CViewCableAlarmInfo::OnExport3() 
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
    		sSql="CREATE TABLE 报警信息表 (分机号 NUMBER,分机名 TEXT,电缆号 TEXT,报警类型 TEXT,距离 NUMBER,";
            sSql+="报警时间 TEXT)";
			database.ExecuteSQL(sSql);
			str="(分机号,分机名,电缆号,";
            str+="报警类型,距离,报警时间)";
            nTotalItem=m_list1.GetItemCount();
			for(i=0;i<nTotalItem;i++)
			{
				sSql="INSERT INTO 报警信息表 ";
				sSql+=str;
				sSql+=" VALUES(";

				for(j=0;j<4;j++)
				{
					sSql+="'";
					sSql+=m_list1.GetItemText(i,j);
					sSql+="',";
				}
				sSql+=m_list1.GetItemText(i,4);
				sSql+=",";
				sSql+="'";
				sSql+=m_list1.GetItemText(i,5);
				sSql+="'";
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
BOOL CViewCableAlarmInfo::bHasExcelDriver()
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
