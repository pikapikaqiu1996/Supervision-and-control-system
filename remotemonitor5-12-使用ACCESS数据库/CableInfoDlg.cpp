// CableInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "CableInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCableInfoDlg dialog


CCableInfoDlg::CCableInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCableInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCableInfoDlg)
	m_cablenum = 0;
	m_fenjinum = 0;
	m_startaddr = _T("");
	m_endaddr = _T("");
	m_strstate = _T("");
	//}}AFX_DATA_INIT
}


void CCableInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCableInfoDlg)
	DDX_Text(pDX, IDC_CABLENUM, m_cablenum);
	DDV_MinMaxByte(pDX, m_cablenum, 1, 16);
	DDX_Text(pDX, IDC_FENJINUM, m_fenjinum);
	DDV_MinMaxInt(pDX, m_fenjinum, 0, 999);
	DDX_Text(pDX, IDC_STARTADDR, m_startaddr);
	DDV_MaxChars(pDX, m_startaddr, 20);
	DDX_Text(pDX, IDC_ENDADDR, m_endaddr);
	DDV_MaxChars(pDX, m_endaddr, 20);
	DDX_Text(pDX, IDC_STATE, m_strstate);
	DDV_MaxChars(pDX, m_strstate, 16);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCableInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CCableInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCableInfoDlg message handlers

BOOL CCableInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_nflag==1)
	{
	   m_startaddr=m_pSet->m_startname;
       m_endaddr=m_pSet->m_endname;
	   if(m_pSet->m_state==0)
          m_strstate="³··À";
	   else
          m_strstate="²¼·À";
	}
    else
        m_strstate="³··À";


    UpdateData(FALSE);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCableInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
    UpdateData(TRUE);	
	CDialog::OnOK();
}
