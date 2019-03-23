// ChangeFenjinumdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "ChangeFenjinumdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeFenjinumdlg dialog


CChangeFenjinumdlg::CChangeFenjinumdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeFenjinumdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeFenjinumdlg)
	m_newnum = 0;
	//}}AFX_DATA_INIT
}


void CChangeFenjinumdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeFenjinumdlg)
	DDX_Text(pDX, IDC_NEWFENJINUM, m_newnum);
	DDV_MinMaxInt(pDX, m_newnum, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangeFenjinumdlg, CDialog)
	//{{AFX_MSG_MAP(CChangeFenjinumdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeFenjinumdlg message handlers

BOOL CChangeFenjinumdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChangeFenjinumdlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CDialog::OnOK();
}
