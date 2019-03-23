// SendCDdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SendCDdlg.h"
#include "FenjiTable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendCDdlg dialog


CSendCDdlg::CSendCDdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendCDdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendCDdlg)
	m_gbk = _T("");
	m_fenjinumber = 0;
	//}}AFX_DATA_INIT
}


void CSendCDdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendCDdlg)
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Text(pDX, IDC_GBK, m_gbk);
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendCDdlg, CDialog)
	//{{AFX_MSG_MAP(CSendCDdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendCDdlg message handlers

BOOL CSendCDdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int i;
	CString str;
    for(i=0;i<=16;i++)
	{
		str.Format("%2.2d",i);
	    m_combo1.AddString(str);
	}
    m_combo1.SetCurSel(0);
    UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSendCDdlg::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	UpdateData(TRUE);
    if(m_gbk=="")
	{
		MessageBox("没有需要发送的信息!","提示信息");
		return;
	}
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
	str.Format("%2.2d", m_combo1.GetCurSel());
	m_strInfo+=str;
	m_strInfo+="#";
    m_strInfo+=m_gbk;
	CDialog::OnOK();
}
