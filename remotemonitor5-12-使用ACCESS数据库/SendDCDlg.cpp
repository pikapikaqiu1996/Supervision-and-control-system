// SendDCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SendDCDlg.h"
#include "FenjiTable.h"
#include "CenterTelTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendDCDlg dialog


CSendDCDlg::CSendDCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendDCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendDCDlg)
	m_fenjinumber = 0;
	//}}AFX_DATA_INIT
}


void CSendDCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendDCDlg)
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 1, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendDCDlg, CDialog)
	//{{AFX_MSG_MAP(CSendDCDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendDCDlg message handlers

BOOL CSendDCDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSendDCDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	UpdateData(TRUE);

    CFenjiTable table;
	table.m_strSort=_T("[Id]");
	str.Format("%d",m_fenjinumber);
	table.m_strFilter=_T("[Id] = "+str);
    table.Open();
	if(table.IsBOF()&&table.IsEOF())
	{
		MessageBox("数据库中没有该分机信息!","提示信息");
		table.Close();
		return;
	}
	m_strInfo=table.m_telephone;
	table.Close();
	m_strInfo+="#";
	CCenterTelTable table1;
	table1.Open();
	m_strInfo+=table1.m_telephone;
	table1.Close();
	CDialog::OnOK();
}

