// Logindlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "Logindlg.h"
#include "DutyTable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogindlg dialog
extern int nPort,nBaudrate;
extern BOOL bRight[];	// 操作权限
extern CString strCurrentUser;
extern CString strDutyTime;


CLogindlg::CLogindlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogindlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogindlg)
	m_strPassword = _T("");
	//}}AFX_DATA_INIT
    m_bAccess=FALSE;
}


void CLogindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogindlg)
	DDX_Control(pDX, IDC_USERNAME, m_usernamectl);
	DDX_Control(pDX, IDC_BAUDRATE, m_baudratectl);
	DDX_Control(pDX, IDC_PORT, m_portctl);
	DDX_Text(pDX, IDC_PWD, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogindlg, CDialog)
	//{{AFX_MSG_MAP(CLogindlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogindlg message handlers

BOOL CLogindlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int bitpsec[10]={1200,2400,4800,9600,14400,19200,38400,56000,115200,256000};
	char cs[20];

	for(int i=0;i<10;i++)
	{
        itoa(bitpsec[i],cs,10);
		m_baudratectl.AddString(cs);
	}
    m_baudratectl.SetCurSel(3);

    m_portctl.AddString("COM1");
    m_portctl.AddString("COM2");
    m_portctl.AddString("COM3");
    m_portctl.SetCurSel(0);	

    //打开数据库和职员表
    //将职员表中所有姓名加入到组合框
//	m_stafftable.m_strSort=_T("[Id]");
	if(!m_stafftable.IsOpen())
       m_stafftable.Open();
	while (!m_stafftable.IsEOF())
	{
       m_usernamectl.AddString(m_stafftable.m_Name);
	   m_stafftable.MoveNext();
	}
    m_usernamectl.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLogindlg::OnOK() 
{
	// TODO: Add extra validation here
	int bitpsec[10]={1200,2400,4800,9600,14400,19200,38400,56000,115200,256000};
	int nIndex;
	char szName[10];
	static int nRetryTimes = 0;

	UpdateData(TRUE);

	nIndex = m_usernamectl.GetCurSel();
	m_usernamectl.GetLBText(nIndex, szName);
    //到表中查找此姓名，若对应的用户密码正确，则可以运行此程序
	CString strFilter = _T("[Name] = '");
	strFilter +=  szName;
    strFilter+="'";

	m_stafftable.m_strSort=_T("[Id]");
	m_stafftable.m_strFilter = _T(strFilter);
    m_stafftable.Requery();
    
    if (m_strPassword == m_stafftable.m_Password)
	{
		m_bAccess = TRUE;
		bRight[0] = m_stafftable.m_RightA;//操作权限
		bRight[1] = m_stafftable.m_RightB;//操作权限
		bRight[2] = m_stafftable.m_RightC;//操作权限
		bRight[3] = m_stafftable.m_RightD;//操作权限

//		AccessRight = m_stafftable.m_Right;//操作权限，对于超级用户，AccessRight＝1,一般用户，为0
        CDutyTable dutytable;
        dutytable.Open();
		dutytable.AddNew();
		dutytable.m_Name=szName;
	    CTime dt=CTime::GetCurrentTime();
        dutytable.m_dutytime=dt;
		dutytable.Update();
		if(dutytable.IsOpen())
		   dutytable.Close();
		strCurrentUser=szName;
        strDutyTime=dt.Format("%Y-%m-%d %H:%M:%S");

	}
	else
		nRetryTimes++;
	
	// 如果密码不符并且次数小于3次, 可以重输
//	AccessRight=1;//暂时让其为1
//	m_bAccess=TRUE;//暂时让其为ＴＲＵＥ
	if (nRetryTimes < 3 && !m_bAccess)
	{
		AfxMessageBox("密码不符!", MB_ICONSTOP);
		return;
	}

	nIndex=m_baudratectl.GetCurSel();
	nBaudrate=bitpsec[nIndex];
	nPort=m_portctl.GetCurSel()+1;

	if (m_stafftable.IsOpen())
		m_stafftable.Close();

	CDialog::OnOK();
}

void CLogindlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	//如果数据库打开，则关闭,如果表是打开的，则关闭
	if (m_stafftable.IsOpen())
		m_stafftable.Close();

	CDialog::OnCancel();
}
