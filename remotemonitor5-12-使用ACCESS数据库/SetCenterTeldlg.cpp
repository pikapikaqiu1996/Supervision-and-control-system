// SetCenterTeldlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SetCenterTeldlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetCenterTeldlg dialog


CSetCenterTeldlg::CSetCenterTeldlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetCenterTeldlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetCenterTeldlg)
	m_tel = _T("");
	//}}AFX_DATA_INIT
}


void CSetCenterTeldlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetCenterTeldlg)
	DDX_Text(pDX, IDC_TEL, m_tel);
	DDV_MaxChars(pDX, m_tel, 13);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetCenterTeldlg, CDialog)
	//{{AFX_MSG_MAP(CSetCenterTeldlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetCenterTeldlg message handlers

BOOL CSetCenterTeldlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!table.IsOpen())
	   table.Open();
    m_tel=table.m_telephone;
	UpdateData(FALSE);
	table.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetCenterTeldlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_tel=="")
	{
		MessageBox("电话号码不能为空,请重新输入!","提示信息");
		return;
	}
	if(!table.IsOpen())
	   table.Open();
	table.Edit();
    table.m_telephone=m_tel;
	table.Update();
	table.Close();
	
	CDialog::OnOK();
}


