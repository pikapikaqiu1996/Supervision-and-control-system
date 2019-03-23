// ViewFenjiCableInfo.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "ViewFenjiCableInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewFenjiCableInfo dialog


CViewFenjiCableInfo::CViewFenjiCableInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CViewFenjiCableInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewFenjiCableInfo)
	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
	m_edit4 = 0;
	//}}AFX_DATA_INIT
}


void CViewFenjiCableInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewFenjiCableInfo)
	DDX_Control(pDX, IDC_MODE2, m_mode2);
	DDX_Control(pDX, IDC_MODE1, m_mode1);
	DDX_Control(pDX, IDC_CABLELIST, m_list2);
	DDX_Control(pDX, IDC_FENJILIST, m_list1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDV_MinMaxInt(pDX, m_edit1, 0, 999);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDV_MinMaxInt(pDX, m_edit2, 0, 999);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDV_MinMaxInt(pDX, m_edit3, 0, 999);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDV_MinMaxInt(pDX, m_edit4, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewFenjiCableInfo, CDialog)
	//{{AFX_MSG_MAP(CViewFenjiCableInfo)
	ON_BN_CLICKED(IDC_PROBE1, OnProbe1)
	ON_BN_CLICKED(IDC_PROBE2, OnProbe2)
	ON_CBN_SELCHANGE(IDC_MODE1, OnSelchangeMode1)
	ON_CBN_SELCHANGE(IDC_MODE2, OnSelchangeMode2)
	ON_BN_CLICKED(IDC_EXPORT1, OnExport1)
	ON_BN_CLICKED(IDC_EXPORT2, OnExport2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewFenjiCableInfo message handlers

BOOL CViewFenjiCableInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str;

    GetDlgItem(IDC_MYSTATIC1)->GetWindowPlacement(&m_mystaticwnd[0]);
    GetDlgItem(IDC_MYSTATIC2)->GetWindowPlacement(&m_mystaticwnd[1]);
    GetDlgItem(IDC_MYSTATIC3)->GetWindowPlacement(&m_mystaticwnd[2]);
    GetDlgItem(IDC_MYSTATIC4)->GetWindowPlacement(&m_mystaticwnd[3]);
    GetDlgItem(IDC_EDIT1)->GetWindowPlacement(&m_editwnd[0]);
    GetDlgItem(IDC_EDIT2)->GetWindowPlacement(&m_editwnd[1]);
    GetDlgItem(IDC_EDIT3)->GetWindowPlacement(&m_editwnd[2]);
    GetDlgItem(IDC_EDIT4)->GetWindowPlacement(&m_editwnd[3]);

	WINDOWPLACEMENT wndplace;
	wndplace.rcNormalPosition.left	    = 2000;
	wndplace.rcNormalPosition.right	    = 2000;
	wndplace.rcNormalPosition.top		= 2000;
	wndplace.rcNormalPosition.bottom	= 2000;
    GetDlgItem(IDC_MYSTATIC1)->SetWindowPlacement(&wndplace);
    GetDlgItem(IDC_MYSTATIC2)->SetWindowPlacement(&wndplace);
    GetDlgItem(IDC_MYSTATIC3)->SetWindowPlacement(&wndplace);
    GetDlgItem(IDC_MYSTATIC4)->SetWindowPlacement(&wndplace);
    GetDlgItem(IDC_EDIT1)->SetWindowPlacement(&wndplace);
    GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&wndplace);
    GetDlgItem(IDC_EDIT3)->SetWindowPlacement(&wndplace);
    GetDlgItem(IDC_EDIT4)->SetWindowPlacement(&wndplace);

	m_mode1.AddString("全部记录");
	m_mode1.AddString("按分机号");
    m_mode1.SetCurSel(0);
	m_mode2.AddString("全部记录");
	m_mode2.AddString("按分机号");
    m_mode2.SetCurSel(0);
    GetDlgItem(IDC_PROBE1)->EnableWindow(FALSE);
    GetDlgItem(IDC_PROBE2)->EnableWindow(FALSE);

	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_list1.InsertColumn( 0, "分机号", LVCFMT_LEFT,60, 0 );
    m_list1.InsertColumn( 1, "分机名", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 2, "分机电话", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 3, "用户1", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 4, "用户电话1", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 5, "用户2", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 6, "用户电话2", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 7, "用户3", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 8, "用户电话3", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 9, "用户4", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 10, "用户电话4", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 11, "用户5", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 12, "用户电话5", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 13, "用户6", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 14, "用户电话6", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 15, "维护1", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 16, "维护电话1",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 17, "维护2", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 18, "维护电话2",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 19, "维护3", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 20, "维护电话3",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 21, "维护4", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 22, "维护电话4",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 23, "维护5", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 24, "维护电话5",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 25, "维护6", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 26, "维护电话6",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 27, "无应答等待时间",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 28, "灵敏度",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 29, "循环拨打次数",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 30, "布防等待时间",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 31, "电压转折点",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 32, "本机模式",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 33, "测距系数",   LVCFMT_LEFT,100,0);

	m_list2.InsertColumn( 0, "分机号", LVCFMT_LEFT,60, 0 );
    m_list2.InsertColumn( 1, "电缆号", LVCFMT_LEFT,60, 0 );
    m_list2.InsertColumn( 2, "电缆起点", LVCFMT_LEFT,100, 0 );
	m_list2.InsertColumn( 3, "电缆终点", LVCFMT_LEFT,100, 0 );
    m_list2.InsertColumn( 4, "功能设置", LVCFMT_LEFT,100, 0 );


	m_table1.m_strSort=_T("[Id]");
	if(!m_table1.IsOpen())
       m_table1.Open();
    InSertList1();

	m_table2.m_strSort=_T("[Id]");
	if(!m_table2.IsOpen())
       m_table2.Open();
	InSertList2();

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CViewFenjiCableInfo::InSertList1()
{
	int i,ntotalItem;
	CString str;

	while (!m_table1.IsEOF())
	{
		ntotalItem = m_list1.GetItemCount();
		str.Format("%3.3d",m_table1.m_Id);
		m_list1.InsertItem(ntotalItem,str);
		m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(m_table1.m_Name),0,0,0,NULL);
		m_list1.SetItem(ntotalItem,2,LVIF_TEXT,_T(m_table1.m_telephone),0,0,0,NULL);
		for(i=0;i<6;i++)
		{
			m_list1.SetItem(ntotalItem,i*2+3,LVIF_TEXT,_T(m_table1.m_username[i]),0,0,0,NULL);
			m_list1.SetItem(ntotalItem,i*2+4,LVIF_TEXT,_T(m_table1.m_usertel[i]),0,0,0,NULL);
			m_list1.SetItem(ntotalItem,i*2+15,LVIF_TEXT,_T(m_table1.m_maintenance[i]),0,0,0,NULL);
			m_list1.SetItem(ntotalItem,i*2+16,LVIF_TEXT,_T(m_table1.m_maintenancetel[i]),0,0,0,NULL);
		}
		str.Format("%d",m_table1.m_ackwaittime);
		m_list1.SetItem(ntotalItem,27,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_sensitive);
		m_list1.SetItem(ntotalItem,28,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_callnumber);
		m_list1.SetItem(ntotalItem,29,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_waittime);
		m_list1.SetItem(ntotalItem,30,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%2.1f",m_table1.m_xudianchi);
		m_list1.SetItem(ntotalItem,31,LVIF_TEXT,_T(str),0,0,0,NULL);
		if(m_table1.m_mode==1)
		   str="单机模式";
		else 
		   str="联网模式";
		m_list1.SetItem(ntotalItem,32,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_zejuxisu);
		m_list1.SetItem(ntotalItem,33,LVIF_TEXT,_T(str),0,0,0,NULL);

        m_table1.MoveNext();
	}
}
void CViewFenjiCableInfo::InSertList2()
{
	int ntotalItem;
	CString str;
    while (!m_table2.IsEOF())
	{
		ntotalItem = m_list2.GetItemCount();
		str.Format("%3.3d",m_table2.m_Id/100);
		m_list2.InsertItem(ntotalItem,str);
		str.Format("%3.3d",m_table2.m_Id%100);
		m_list2.SetItem(ntotalItem,1,LVIF_TEXT,_T(str),0,0,0,NULL);
		m_list2.SetItem(ntotalItem,2,LVIF_TEXT,_T(m_table2.m_startname),0,0,0,NULL);
		m_list2.SetItem(ntotalItem,3,LVIF_TEXT,_T(m_table2.m_endname),0,0,0,NULL);
		if(m_table2.m_Id%100<=8)
		{
			if(m_table2.m_state==0)
				str="撤防";
			else
				str="布防";
		}
		else
		{
			switch(m_table2.m_state)
			{
			case 0:
				str="电缆防盗";
				break;
			case 1:
				str="温度告警";
				break;
			case 2:
				str="湿度告警";
				break;
			case 3:
				str="红外告警";
				break;
			case 4:
				str="门禁告警";
				break;
			case 5:
				str="烟雾告警";
				break;
			case 6:
				str="浸水告警";
				break;
			case 7:
				str="有害气体告警";
			case 8:
				str="撤防";
				break;
			default:
				break;
				
			}
		}
		m_list2.SetItem(ntotalItem,4,LVIF_TEXT,_T(str),0,0,0,NULL);
		m_table2.MoveNext();
	}
}
void CViewFenjiCableInfo::OnOK() 
{
	// TODO: Add extra validation here
	if(m_table1.IsOpen())
       m_table1.Close();
	if(m_table2.IsOpen())
       m_table2.Close();
	CDialog::OnOK();
}

void CViewFenjiCableInfo::OnProbe1() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_mode1.GetCurSel();
    CString str1,str2;
	UpdateData(TRUE);
	if(nIndex==0)//全部记录
		return;
	else//按分机号查询
	{
		if(m_edit1>m_edit2)
		{
			int temp=m_edit1;
			m_edit1=m_edit2;
			m_edit2=temp;
		}
        m_table1.m_strSort=_T("[Id]");
		str1.Format("%d",m_edit1);
		str2.Format("%d",m_edit2);
        m_table1.m_strFilter=_T("[Id] Between " + str1 + " AND " + str2); 
		if(m_table1.Requery())
		{
			m_list1.DeleteAllItems();
			InSertList1();
		}
	}
    UpdateData(FALSE);		
}
void CViewFenjiCableInfo::OnProbe2() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_mode2.GetCurSel();
    CString str1,str2;
	UpdateData(TRUE);
	if(nIndex==0)//全部记录
		return;
	else//按分机号查询
	{
		if(m_edit3>m_edit4)
		{
			int temp=m_edit3;
			m_edit3=m_edit4;
			m_edit4=temp;
		}
        m_table2.m_strSort=_T("[Id]");
		str1.Format("%d",m_edit3*100);
		str2.Format("%d",m_edit4*100+16);
        m_table2.m_strFilter=_T("[Id] Between " + str1 + " AND " + str2); 
		if(m_table2.Requery())
		{
			m_list2.DeleteAllItems();
			InSertList2();
		}
	}
    UpdateData(FALSE);			
}


void CViewFenjiCableInfo::OnSelchangeMode1() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_mode1.GetCurSel();
	if(nIndex==0)//全部记录
	{
        GetDlgItem(IDC_PROBE1)->EnableWindow(FALSE);
		WINDOWPLACEMENT wndplace;
		wndplace.rcNormalPosition.left	    = 2000;
		wndplace.rcNormalPosition.right	    = 2000;
		wndplace.rcNormalPosition.top		= 2000;
		wndplace.rcNormalPosition.bottom	= 2000;
		GetDlgItem(IDC_MYSTATIC1)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_MYSTATIC2)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT1)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&wndplace);

		m_table1.m_strSort=_T("[Id]");
        m_table1.m_strFilter=_T(""); 
        m_table1.Requery();
        m_list1.DeleteAllItems();
	    InSertList1();	
    }
	else//按分机号查询
	{
        GetDlgItem(IDC_PROBE1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MYSTATIC1)->SetWindowPlacement(&m_mystaticwnd[0]);
		GetDlgItem(IDC_MYSTATIC2)->SetWindowPlacement(&m_mystaticwnd[1]);
		GetDlgItem(IDC_EDIT1)->SetWindowPlacement(&m_editwnd[0]);
		GetDlgItem(IDC_EDIT2)->SetWindowPlacement(&m_editwnd[1]);
        m_edit1=0;
		m_edit2=100;
	}
	UpdateData(FALSE);	
}

void CViewFenjiCableInfo::OnSelchangeMode2() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_mode2.GetCurSel();
	if(nIndex==0)//全部记录
	{
        GetDlgItem(IDC_PROBE2)->EnableWindow(FALSE);
		WINDOWPLACEMENT wndplace;
		wndplace.rcNormalPosition.left	    = 2000;
		wndplace.rcNormalPosition.right	    = 2000;
		wndplace.rcNormalPosition.top		= 2000;
		wndplace.rcNormalPosition.bottom	= 2000;
		GetDlgItem(IDC_MYSTATIC3)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_MYSTATIC4)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT3)->SetWindowPlacement(&wndplace);
		GetDlgItem(IDC_EDIT4)->SetWindowPlacement(&wndplace);

		m_table2.m_strSort=_T("[Id]");
        m_table2.m_strFilter=_T(""); 
        m_table2.Requery();
        m_list2.DeleteAllItems();
	    InSertList2();	
    }
	else//按分机号查询
	{
        GetDlgItem(IDC_PROBE2)->EnableWindow(TRUE);
		GetDlgItem(IDC_MYSTATIC3)->SetWindowPlacement(&m_mystaticwnd[2]);
		GetDlgItem(IDC_MYSTATIC4)->SetWindowPlacement(&m_mystaticwnd[3]);
		GetDlgItem(IDC_EDIT3)->SetWindowPlacement(&m_editwnd[2]);
		GetDlgItem(IDC_EDIT4)->SetWindowPlacement(&m_editwnd[3]);
        m_edit3=0;
		m_edit4=10;
	}
	UpdateData(FALSE);		
}

void CViewFenjiCableInfo::OnExport1() 
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
			//创建表结构
			//		sSql="DROP TABLE 分机信息表";
			//     database.ExecuteSQL(sSql);
			sSql="CREATE TABLE 分机信息表 (分机号 TEXT,分机名 TEXT,分机电话 TEXT,";
            sSql+="用户1 TEXT,用户电话1 TEXT,用户2 TEXT,用户电话2 TEXT,用户3 TEXT,用户电话3 TEXT,";
            sSql+="用户4 TEXT,用户电话4 TEXT,用户5 TEXT,用户电话5 TEXT,用户6 TEXT,用户电话6 TEXT,";
            sSql+="维护1 TEXT,维护电话1 TEXT,维护2 TEXT,维护电话2 TEXT,维护3 TEXT,维护电话3 TEXT,";
            sSql+="维护4 TEXT,维护电话4 TEXT,维护5 TEXT,维护电话5 TEXT,维护6 TEXT,维护电话6 TEXT,";
            sSql+="无应答等待时间 NUMBER,灵敏度 NUMBER,循环拨打次数 NUMBER,布防等待时间 NUMBER,电压转折点 NUMBER,本机模式 TEXT,测距系数 NUMBER)";
			database.ExecuteSQL(sSql);
	//		sSql="CREATE TABLE 分机信息表 (Name TEXT,Age NUMBER)";
	//		database.ExecuteSQL(sSql);
			str="(分机号,分机名,分机电话,";
            str+="用户1,用户电话1,用户2,用户电话2,用户3,用户电话3,";
            str+="用户4,用户电话4,用户5,用户电话5,用户6,用户电话6,";
            str+="维护1,维护电话1,维护2,维护电话2,维护3,维护电话3,";
            str+="维护4,维护电话4,维护5,维护电话5,维护6,维护电话6,";
            str+="无应答等待时间,灵敏度,循环拨打次数,布防等待时间,电压转折点,本机模式,测距系数)";
            nTotalItem=m_list1.GetItemCount();
			for(i=0;i<nTotalItem;i++)
			{
				sSql="INSERT INTO 分机信息表 ";
				sSql+=str;
				sSql+=" VALUES(";
				for(j=0;j<27;j++)
				{
					sSql+="'";
					sSql+=m_list1.GetItemText(i,j);
					sSql+="',";
				}
				for(j=0;j<5;j++)
				{
					sSql+=m_list1.GetItemText(i,j+27);
					sSql+=",";
				}
				sSql+="'";
				sSql+=m_list1.GetItemText(i,32);
				sSql+="',";
				sSql+=m_list1.GetItemText(i,33);
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

void CViewFenjiCableInfo::OnExport2() 
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
     		sSql="CREATE TABLE 电缆信息表 (分机号 TEXT,电缆号 TEXT,电缆起点 TEXT,";
            sSql+="电缆终点 TEXT,功能设置 TEXT)";
			database.ExecuteSQL(sSql);
			str="(分机号,电缆号,电缆起点,";
            str+="电缆终点,功能设置)";
            nTotalItem=m_list2.GetItemCount();
			for(i=0;i<nTotalItem;i++)
			{
				sSql="INSERT INTO 电缆信息表 ";
				sSql+=str;
				sSql+=" VALUES(";
				for(j=0;j<5;j++)
				{
					sSql+="'";
					sSql+=m_list2.GetItemText(i,j);
					sSql+="'";
					if(j<4)
					  sSql+=",";
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
BOOL CViewFenjiCableInfo::bHasExcelDriver()
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
