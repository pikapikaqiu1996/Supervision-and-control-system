// SendAAdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SendAAdlg.h"
#include "FenjiTable.h"
#include "CableInfoTable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendAAdlg dialog


CSendAAdlg::CSendAAdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendAAdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendAAdlg)
	m_fenjinumber = 0;
	//}}AFX_DATA_INIT
}


void CSendAAdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendAAdlg)
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendAAdlg, CDialog)
	//{{AFX_MSG_MAP(CSendAAdlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendAAdlg message handlers

BOOL CSendAAdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list1.InsertColumn( 0, "电缆号", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 1, "功能配置", LVCFMT_LEFT,100, 0 );

    GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CSendAAdlg::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
    int i;
	int nState;
	UpdateData(TRUE);
	int ntotalItem = m_list1.GetItemCount();
    if(ntotalItem==0)
	{
		MessageBox("没有要发送的信息!","提示信息");
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

    CCableInfoTable table1;
	table1.m_strSort=_T("[Id]");
    table1.m_strFilter="";
    table1.Open();

	for(i=0;i<ntotalItem;i++)
	{
       m_strInfo+="#";
	   m_strInfo+=m_list1.GetItemText(i,0);
       m_strInfo+="#";
       str=m_list1.GetItemText(i,1);
       if(str=="电缆撤防")
	   {
          m_strInfo+="0";
		  nState=0;
	   }
       else if(str=="电缆布防")
	   {
          m_strInfo+="1";
		  nState=1;
	   }
       else if(str=="温度告警")
	   {
          m_strInfo+="2";
		  nState=2;
	   }
       else if(str=="湿度告警")
	   {
          m_strInfo+="3";
		  nState=3;
	   }
       else if(str=="红外告警")
	   {
          m_strInfo+="4";
		  nState=4;
	   }
       else if(str=="门禁告警")
	   {
          m_strInfo+="5";
		  nState=5;
	   }
       else if(str=="烟雾告警")
	   {
          m_strInfo+="6";
		  nState=6;
	   }
       else if(str=="浸水告警")
	   {
          m_strInfo+="7";
		  nState=7;
	   }
       else if(str=="有害气体告警")
	   {
          m_strInfo+="8";
		  nState=8;
	   }
		str.Format("%d",m_fenjinumber*100+atoi(m_list1.GetItemText(i,0)));
		table1.m_strFilter=_T("[Id] = "+str);
		table1.Requery();
	   if(!(table1.IsBOF()&&table1.IsEOF()))
	   {
		   table1.Edit();
		   table1.m_state=nState;
		   table1.Update();
	   }
	}
	table1.Close();
	CDialog::OnOK();
}
#include "AddCableConfig.h"
void CSendAAdlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str;
	int i;
	int ntotalItem = m_list1.GetItemCount();
    if(ntotalItem==16)
	{
		MessageBox("已有16项，不能再增加!","提示信息");
		return;
	}
	CAddCableConfig dlg;
	dlg.m_nTotalItem=ntotalItem;
	for(i=0;i<ntotalItem;i++)
	   dlg.m_nArray[i]=atoi(m_list1.GetItemText(i, 0));

	if(dlg.DoModal()==IDOK)
	{
//		int ntotalItem = m_list1.GetItemCount();
		str.Format("%2.2d",dlg.m_cable);
		m_list1.InsertItem(ntotalItem,str);
		switch(dlg.m_type)
		{
		case 0:
			str="电缆撤防";
			break;
		case 1:
			str="电缆布防";
			break;
		case 2:
			str="温度告警";
			break;
		case 3:
			str="湿度告警";
			break;
		case 4:
			str="红外告警";
			break;
		case 5:
			str="门禁告警";
			break;
		case 6:
			str="烟雾告警";
			break;
		case 7:
			str="浸水告警";
			break;
		case 8:
			str="有害气体告警";
			break;
		}
		m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(str),0,0,0,NULL);
	}
}

void CSendAAdlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int index;

    GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
	index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
		return;
	m_list1.DeleteItem(index);
}

void CSendAAdlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index!=-1)
       GetDlgItem(IDC_DELETE)->EnableWindow(TRUE);
	else
       GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);

	*pResult = 0;
}
