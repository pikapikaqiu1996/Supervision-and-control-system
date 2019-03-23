// JiaoBanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "JiaoBanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJiaoBanDlg dialog
extern BOOL bRight[];	// 操作权限
extern CString strCurrentUser;
extern CString strDutyTime;


CJiaoBanDlg::CJiaoBanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJiaoBanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJiaoBanDlg)
	m_password1 = _T("");
	//}}AFX_DATA_INIT
}


void CJiaoBanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJiaoBanDlg)
	DDX_Control(pDX, IDC_COMBO1, m_combo1ctl);
	DDX_Text(pDX, IDC_PASSWORD1, m_password1);
	DDV_MaxChars(pDX, m_password1, 6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJiaoBanDlg, CDialog)
	//{{AFX_MSG_MAP(CJiaoBanDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJiaoBanDlg message handlers

BOOL CJiaoBanDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    //打开数据库和职员表
    //将职员表中所有姓名加入到组合框
	if(!m_stafftable.IsOpen())
       m_stafftable.Open();
	while (!m_stafftable.IsEOF())
	{
       m_combo1ctl.AddString(m_stafftable.m_Name);
	   m_stafftable.MoveNext();
	}
    m_combo1ctl.SetCurSel(0);	
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
#include "DutyTable.h"
void CJiaoBanDlg::OnOK() 
{
	// TODO: Add extra validation here
	char szName[10];
	static int nRetryTimes = 0;
	CString strFilter;
	UpdateData(TRUE);

	int nIndex = m_combo1ctl.GetCurSel();
	m_combo1ctl.GetLBText(nIndex, szName);

	strFilter = _T("[Name] = '");
	strFilter +=  szName;
    strFilter+="'";

	m_stafftable.m_strSort=_T("[Id]");
	m_stafftable.m_strFilter = _T(strFilter);
    m_stafftable.Requery();

    if (m_password1 != m_stafftable.m_Password)
	{
		MessageBox("接班人与其密码不符!","提示信息");
		return;
	}
	bRight[0] = m_stafftable.m_RightA;//操作权限
	bRight[1] = m_stafftable.m_RightB;//操作权限
	bRight[2] = m_stafftable.m_RightC;//操作权限
	bRight[3] = m_stafftable.m_RightD;//操作权限

	CTime dt=CTime::GetCurrentTime();
	CDutyTable dutytable;
	strFilter = _T("[Name] = '");
	strFilter +=  strCurrentUser;
	strFilter+="'";
	strFilter+=" AND ";
//	strFilter+=_T("[dutytime] = '");
//	strFilter+=strDutyTime;
//	strFilter+="'";
	strFilter+=_T("[dutytime] = #");
	strFilter+=strDutyTime;
	strFilter+="#";

	//	dutytable.m_strSort=_T("[Id]");
	dutytable.m_strFilter = _T(strFilter);
	dutytable.Open();
	if(!dutytable.IsBOF())
	{
		dutytable.Edit();
        dutytable.m_lefttime=dt;
		dutytable.Update();
	}
	dutytable.AddNew();
	dutytable.m_Name=szName;
    dutytable.m_dutytime=dt;
	dutytable.Update();
	if(dutytable.IsOpen())
		dutytable.Close();
	strCurrentUser=szName;
	strDutyTime=dt.Format("%Y-%m-%d %H:%M:%S");
	if (m_stafftable.IsOpen())
		m_stafftable.Close();	
	CDialog::OnOK();
}

void CJiaoBanDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if (m_stafftable.IsOpen())
		m_stafftable.Close();	
	
	CDialog::OnCancel();
}
