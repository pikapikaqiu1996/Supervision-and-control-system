// CangeCableNumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "CangeCableNumDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCangeCableNumDlg dialog


CCangeCableNumDlg::CCangeCableNumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCangeCableNumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCangeCableNumDlg)
	m_newfenjinum = 0;
	//}}AFX_DATA_INIT
}


void CCangeCableNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCangeCableNumDlg)
	DDX_Control(pDX, IDC_CABLECOMBO, m_cablecomboctl);
	DDX_Text(pDX, IDC_NEWFENJINUM, m_newfenjinum);
	DDV_MinMaxInt(pDX, m_newfenjinum, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCangeCableNumDlg, CDialog)
	//{{AFX_MSG_MAP(CCangeCableNumDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCangeCableNumDlg message handlers

BOOL CCangeCableNumDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str;
    for(int i=0;i<16;i++)
	{
		str.Format("%d",i+1);
	    m_cablecomboctl.AddString(str);
	}
    m_cablecomboctl.SetCurSel(m_newcablenum-1);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCangeCableNumDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
    m_newcablenum=m_cablecomboctl.GetCurSel()+1;
	CDialog::OnOK();
}
