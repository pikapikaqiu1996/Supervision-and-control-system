// SendCBdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SendCBdlg.h"
#include "FenjiTable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendCBdlg dialog


CSendCBdlg::CSendCBdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendCBdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendCBdlg)
	m_fenjinumber = 0;
	m_newfenjinumber = 0;
	//}}AFX_DATA_INIT
}


void CSendCBdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendCBdlg)
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 0, 999);
	DDX_Text(pDX, IDC_NEWFENJINUMBER, m_newfenjinumber);
	DDV_MinMaxInt(pDX, m_newfenjinumber, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendCBdlg, CDialog)
	//{{AFX_MSG_MAP(CSendCBdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendCBdlg message handlers

void CSendCBdlg::OnOK() 
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
	str.Format("%3.3d",m_newfenjinumber);
    m_strInfo+=str;
	CDialog::OnOK();
}


