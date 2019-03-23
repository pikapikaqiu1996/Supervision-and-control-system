// SendABdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SendABdlg.h"
#include "FenjiTable.h"
#include "CenterTelTable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendABdlg dialog


CSendABdlg::CSendABdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendABdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendABdlg)
	m_fenjinumber = 0;
	//}}AFX_DATA_INIT
}


void CSendABdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendABdlg)
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendABdlg, CDialog)
	//{{AFX_MSG_MAP(CSendABdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendABdlg message handlers

BOOL CSendABdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_flag==0)
		SetWindowText("发送主动巡检指令");
	else if(m_flag==1)
		SetWindowText("下载时间");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSendABdlg::OnOK() 
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
    if(m_flag==1)
	{
		m_strInfo+="#";
		CTime t = CTime::GetCurrentTime();
		m_strInfo+=t.Format("%m#%d#%H#%M#%S");
	}
	CDialog::OnOK();
}
