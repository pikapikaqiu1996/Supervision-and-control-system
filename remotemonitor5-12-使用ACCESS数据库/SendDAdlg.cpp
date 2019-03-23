// SendDAdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SendDAdlg.h"
#include "FenjiTable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendDAdlg dialog


CSendDAdlg::CSendDAdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendDAdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendDAdlg)
	m_fenjinumber = 0;
	//}}AFX_DATA_INIT
}


void CSendDAdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendDAdlg)
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendDAdlg, CDialog)
	//{{AFX_MSG_MAP(CSendDAdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendDAdlg message handlers

BOOL CSendDAdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	m_delctl.EnableWindow(FALSE);
 //   UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
/*
void CSendDAdlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_sendlistctl.GetCount()>=6)
	{
		MessageBox("已经有6个电话号码!不能再增加","提示信息");
		return;
	}

	if(m_strteleedit=="")
	{
		MessageBox("没有输入电话号码!","提示信息");
		return;
	}
    m_sendlistctl.AddString(m_strteleedit);	
}

void CSendDAdlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	int nIndex;
	if(m_sendlistctl.GetCurSel()==LB_ERR)
		return;
    nIndex=m_sendlistctl.GetCurSel();	
	m_sendlistctl.DeleteString(nIndex);
	m_sendlistctl.SetCurSel(-1);
	m_delctl.EnableWindow(FALSE);
}
*/
void CSendDAdlg::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	int i;
//	int ntotalItem;

	UpdateData(TRUE);
//	ntotalItem=m_sendlistctl.GetCount();
/*	if(ntotalItem==0)
	{
		MessageBox("没有要下传的电话号码!","提示信息");
		return;
	}
	*/
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
	for(i=0;i<6;i++)
	{
		if(table.m_usertel[i]!="")
		{
		   m_strInfo+="#";
		   m_strInfo+=table.m_usertel[i];
		}
	}
	table.Close();
/*	for(i=0;i<ntotalItem;i++)
	{
		m_strInfo+="#";
		m_sendlistctl.GetText(i,str);
		m_strInfo+=str;
	}
	*/
	CDialog::OnOK();
}
/*
void CSendDAdlg::OnSelchangeSendtelelist() 
{
	// TODO: Add your control notification handler code here
	if(m_sendlistctl.GetCurSel()==LB_ERR)
		return;
	m_delctl.EnableWindow(TRUE);	
}
*/
