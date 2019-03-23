// AddorChangeUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "AddorChangeUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeUserDlg dialog


CAddorChangeUserDlg::CAddorChangeUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddorChangeUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddorChangeUserDlg)
	m_username = _T("");
	m_usertel = _T("");
	//}}AFX_DATA_INIT
}


void CAddorChangeUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddorChangeUserDlg)
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_usertel);
	DDV_MaxChars(pDX, m_usertel, 13);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddorChangeUserDlg, CDialog)
	//{{AFX_MSG_MAP(CAddorChangeUserDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeUserDlg message handlers

BOOL CAddorChangeUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_nflag==0)
		SetWindowText("添加用户");
	else
		SetWindowText("修改用户");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddorChangeUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_username==""&&m_usertel=="")
	{
		MessageBox("用户名和电话均为空,请重新输入!","提示信息");
	}
	CDialog::OnOK();

}
