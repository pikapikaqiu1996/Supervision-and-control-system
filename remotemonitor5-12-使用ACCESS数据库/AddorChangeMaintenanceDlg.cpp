// AddorChangeMaintenanceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "AddorChangeMaintenanceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeMaintenanceDlg dialog


CAddorChangeMaintenanceDlg::CAddorChangeMaintenanceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddorChangeMaintenanceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddorChangeMaintenanceDlg)
	m_name = _T("");
	m_tel = _T("");
	//}}AFX_DATA_INIT
}


void CAddorChangeMaintenanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddorChangeMaintenanceDlg)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 10);
	DDX_Text(pDX, IDC_TEL, m_tel);
	DDV_MaxChars(pDX, m_tel, 13);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddorChangeMaintenanceDlg, CDialog)
	//{{AFX_MSG_MAP(CAddorChangeMaintenanceDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeMaintenanceDlg message handlers

BOOL CAddorChangeMaintenanceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_nflag==0)
		SetWindowText("添加维修人员");
	else
		SetWindowText("修改维修人员");
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddorChangeMaintenanceDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_name==""&&m_tel=="")
	{
		MessageBox("维修人员名和电话均为空,请重新输入!","提示信息");
	}	
	CDialog::OnOK();
}
