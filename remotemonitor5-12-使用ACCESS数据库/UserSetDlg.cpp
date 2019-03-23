// UserSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "UserSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserSetDlg dialog


CUserSetDlg::CUserSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserSetDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserSetDlg)
	DDX_Control(pDX, IDC_DELETE, m_delete);
	DDX_Control(pDX, IDC_CHANGE, m_change);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserSetDlg, CDialog)
	//{{AFX_MSG_MAP(CUserSetDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserSetDlg message handlers

BOOL CUserSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str;

	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_list1.InsertColumn( 0, "用户名", LVCFMT_LEFT,60, 0 );
    m_list1.InsertColumn( 1, "密码", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 2, "用户设置", LVCFMT_LEFT,70, 0 );
	m_list1.InsertColumn( 3, "分机设置", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 4, "修改拓朴图", LVCFMT_LEFT,80, 0 );
	m_list1.InsertColumn( 5, "删除记录", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 6, "职务", LVCFMT_LEFT,60, 0 );
	m_list1.InsertColumn( 7, "电话", LVCFMT_LEFT,100, 0 );
    m_list1.InsertColumn( 8, "工作部门", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 9, "住    址", LVCFMT_LEFT,100, 0 );


	m_table.m_strSort=_T("[Id]");
	if(!m_table.IsOpen())
       m_table.Open();
    InSertList1();

    m_change.EnableWindow(FALSE);
    m_delete.EnableWindow(FALSE);

	UpdateData(FALSE);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CUserSetDlg::InSertList1()
{
	int ntotalItem;
	CString str;

	while (!m_table.IsEOF())
	{
		ntotalItem = m_list1.GetItemCount();
		m_list1.InsertItem(ntotalItem,m_table.m_Name);
		m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(m_table.m_Password),0,0,0,NULL);
		if(m_table.m_RightA==0) str="否";
		else str="是";
		m_list1.SetItem(ntotalItem,2,LVIF_TEXT,_T(str),0,0,0,NULL);
		if(m_table.m_RightB==0) str="否";
		else str="是";
		m_list1.SetItem(ntotalItem,3,LVIF_TEXT,_T(str),0,0,0,NULL);
		if(m_table.m_RightC==0) str="否";
		else str="是";
		m_list1.SetItem(ntotalItem,4,LVIF_TEXT,_T(str),0,0,0,NULL);
		if(m_table.m_RightD==0) str="否";
		else str="是";
		m_list1.SetItem(ntotalItem,5,LVIF_TEXT,_T(str),0,0,0,NULL);
		m_list1.SetItem(ntotalItem,6,LVIF_TEXT,_T(m_table.m_Duty),0,0,0,NULL);
		m_list1.SetItem(ntotalItem,7,LVIF_TEXT,_T(m_table.m_Telephone),0,0,0,NULL);
		m_list1.SetItem(ntotalItem,8,LVIF_TEXT,_T(m_table.m_Department),0,0,0,NULL);
		m_list1.SetItem(ntotalItem,9,LVIF_TEXT,_T(m_table.m_Address),0,0,0,NULL);
        m_table.MoveNext();
	}
}
void CUserSetDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_table.IsOpen())
       m_table.Close();
	CDialog::OnOK();
}

void CUserSetDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index!=-1)
	{
       m_change.EnableWindow(TRUE);
       m_delete.EnableWindow(TRUE);
	}
	else
	{
       m_change.EnableWindow(FALSE);
       m_delete.EnableWindow(FALSE);
	}	
	*pResult = 0;
}
#include "AddUserdlg.h"
void CUserSetDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CAddUserdlg dlg;

	dlg.m_flag=0;
    dlg.m_pSet=&m_table;

	if(dlg.DoModal()==IDOK)
	{
       m_list1.DeleteAllItems();
       m_table.m_strSort=_T("[Id]");
       m_table.m_strFilter=_T("");
       m_table.Requery();
       InSertList1();
	}
}

void CUserSetDlg::OnChange() 
{
	// TODO: Add your control notification handler code here
	int index;
    CString str;

	index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change.EnableWindow(FALSE);
        m_delete.EnableWindow(FALSE);	
		return;
	}

	str=m_list1.GetItemText(index,0);
	m_table.m_strFilter=_T("[Name]= '");
    m_table.m_strFilter+=str;
    m_table.m_strFilter+="'";
    m_table.Requery();

	CAddUserdlg dlg;
	dlg.m_flag=1;//
    dlg.m_pSet=&m_table;
	if(dlg.DoModal()==IDOK)
	{
       m_list1.DeleteAllItems();
       m_table.m_strSort=_T("[Id]");
       m_table.m_strFilter=_T("");
       m_table.Requery();
       InSertList1();
	}
    m_change.EnableWindow(FALSE);
    m_delete.EnableWindow(FALSE);	
}

void CUserSetDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int index;
    CString str;

	index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change.EnableWindow(FALSE);
        m_delete.EnableWindow(FALSE);	
		return;
	}
	str=m_list1.GetItemText(index,0);
	m_table.m_strFilter=_T("[Name]= '");
    m_table.m_strFilter+=str;
    m_table.m_strFilter+="'";
    m_table.Requery();
    m_table.Delete();
    m_table.MoveNext();
	m_list1.DeleteItem(index);
    m_change.EnableWindow(FALSE);
    m_delete.EnableWindow(FALSE);	
}
