// SetNodeNumdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SetNodeNumdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetNodeNumdlg dialog


CSetNodeNumdlg::CSetNodeNumdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetNodeNumdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetNodeNumdlg)
	m_fengjinum = 0;
	//}}AFX_DATA_INIT
}


void CSetNodeNumdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetNodeNumdlg)
	DDX_Control(pDX, IDC_CABLESTATIC, m_cablestaticctl);
	DDX_Control(pDX, IDC_CABLENUM, m_cablenumctl);
	DDX_Text(pDX, IDC_FENGJINUM, m_fengjinum);
	DDV_MinMaxInt(pDX, m_fengjinum, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetNodeNumdlg, CDialog)
	//{{AFX_MSG_MAP(CSetNodeNumdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetNodeNumdlg message handlers

BOOL CSetNodeNumdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int i;
	CString str;

	m_fengjinum=m_NodeNum/100;
	if(m_NodeNum%100==0)//分机节点时，电缆号为00
	{
		m_cablenumctl.AddString("00");
		m_cablenumctl.SetCurSel(0);
		m_cablestaticctl.EnableWindow(FALSE);
        m_cablenumctl.EnableWindow(FALSE);
	}
	else
	{
		for(i=1;i<=16;i++)
		{
          str.Format("%2.2d",i);
	      m_cablenumctl.AddString(str);
		}
        m_cablenumctl.SetCurSel(m_NodeNum%100-1);
	}
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetNodeNumdlg::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	int nIndex;

	UpdateData(TRUE);
	m_NodeNum=m_fengjinum*100;
	nIndex=m_cablenumctl.GetCurSel();
    m_cablenumctl.GetLBText(nIndex,str);
    m_NodeNum+=atoi(str);

	CDialog::OnOK();
}
