// FenjiInfoPage.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "FenjiInfoPage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CFenjiInfoPage, CPropertyPage)
IMPLEMENT_DYNCREATE(CFenjiParaPage, CPropertyPage)


/////////////////////////////////////////////////////////////////////////////
// CFenjiInfoPage property page

CFenjiInfoPage::CFenjiInfoPage() : CPropertyPage(CFenjiInfoPage::IDD)
{
	//{{AFX_DATA_INIT(CFenjiInfoPage)
	m_fenjinum = 0;
	m_fenjitel = _T("");
	m_fenjiname = _T("");
	//}}AFX_DATA_INIT
}

CFenjiInfoPage::~CFenjiInfoPage()
{
}

void CFenjiInfoPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenjiInfoPage)
	DDX_Control(pDX, IDC_DELETE2, m_delete2);
	DDX_Control(pDX, IDC_DELETE1, m_delete1);
	DDX_Control(pDX, IDC_CHANGE2, m_change2);
	DDX_Control(pDX, IDC_CHANGE1, m_change1);
	DDX_Control(pDX, IDC_ADD2, m_add2);
	DDX_Control(pDX, IDC_ADD1, m_add1);
	DDX_Control(pDX, IDC_MAINTENANCELIST, m_list2);
	DDX_Control(pDX, IDC_USERINFOLIST, m_list1);
	DDX_Text(pDX, IDC_FENJINUM, m_fenjinum);
	DDV_MinMaxInt(pDX, m_fenjinum, 0, 999);
	DDX_Text(pDX, IDC_FENJITEL, m_fenjitel);
	DDV_MaxChars(pDX, m_fenjitel, 13);
	DDX_Text(pDX, IDC_FENJINAME, m_fenjiname);
	DDV_MaxChars(pDX, m_fenjiname, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenjiInfoPage, CPropertyPage)
	//{{AFX_MSG_MAP(CFenjiInfoPage)
	ON_NOTIFY(NM_CLICK, IDC_USERINFOLIST, OnClickUserinfolist)
	ON_NOTIFY(NM_CLICK, IDC_MAINTENANCELIST, OnClickMaintenancelist)
	ON_BN_CLICKED(IDC_ADD1, OnAdd1)
	ON_BN_CLICKED(IDC_ADD2, OnAdd2)
	ON_BN_CLICKED(IDC_CHANGE1, OnChange1)
	ON_BN_CLICKED(IDC_CHANGE2, OnChange2)
	ON_BN_CLICKED(IDC_DELETE1, OnDelete1)
	ON_BN_CLICKED(IDC_DELETE2, OnDelete2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFenjiParaPage property page

CFenjiParaPage::CFenjiParaPage() : CPropertyPage(CFenjiParaPage::IDD)
{
	//{{AFX_DATA_INIT(CFenjiParaPage)
	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
	m_edit4 = 0;
	m_edit5 = 0.0f;
	m_edit6 = _T("");
	m_edit7 = 0;
	//}}AFX_DATA_INIT
}

CFenjiParaPage::~CFenjiParaPage()
{
}

void CFenjiParaPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenjiParaPage)
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDX_Text(pDX, IDC_EDIT6, m_edit6);
	DDX_Text(pDX, IDC_EDIT7, m_edit7);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenjiParaPage, CPropertyPage)
	//{{AFX_MSG_MAP(CFenjiParaPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CFenjiInfoPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	int i,j;
	if(m_nflag==1)
	{
	   m_fenjitel=m_pSet->m_telephone;
       m_fenjiname=m_pSet->m_Name;
	}
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT/*|LVS_EX_GRIDLINES|LVS_EX_TRACKSELECT*/);
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CString str;
	m_list1.InsertColumn( 0, "用  户", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 1, "电  话", LVCFMT_LEFT,100, 0 );
	m_list2.InsertColumn( 0, "维修人员", LVCFMT_LEFT,70,0);
    m_list2.InsertColumn( 1, "电  话",   LVCFMT_LEFT,100,0);
	if(m_nflag==1)
	{
		j=0;
		for(i=0;i<6;i++)
		{
			if(m_pSet->m_username[i]!=_T("")||m_pSet->m_usertel[i]!=_T(""))
			{ 
				m_list1.InsertItem(j,_T(m_pSet->m_username[i]));
				m_list1.SetItem(j,1,LVIF_TEXT,_T(m_pSet->m_usertel[i]),0,0,0,NULL);
				j++;
			}
		}
		
		j=0;
		for(i=0;i<6;i++)
		{
			if(m_pSet->m_maintenance[i]!=_T("")||m_pSet->m_maintenancetel[i]!=_T(""))
			{ 
				m_list2.InsertItem(j,_T(m_pSet->m_maintenance[i]));
				m_list2.SetItem(j,1,LVIF_TEXT,_T(m_pSet->m_maintenancetel[i]),0,0,0,NULL);
				j++;
			}
		}
	}

    m_nuserCount=m_list1.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_username[i]=m_list1.GetItemText(i,0);
       m_usertel[i]=m_list1.GetItemText(i,1);
	}
    m_nmainteCount=m_list2.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_maintename[i]=m_list2.GetItemText(i,0);
       m_maintetel[i]=m_list2.GetItemText(i,1);
	}
    m_change1.EnableWindow(FALSE);
    m_delete1.EnableWindow(FALSE);
    m_change2.EnableWindow(FALSE);
    m_delete2.EnableWindow(FALSE);
    UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CFenjiParaPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
    if(m_nflag==1)
	{
		m_edit1=(unsigned char)m_pSet->m_ackwaittime;
		m_edit2=(unsigned char)m_pSet->m_sensitive;
		m_edit3=(unsigned char)m_pSet->m_callnumber;
		m_edit4=(unsigned char)m_pSet->m_waittime;
		m_edit5=m_pSet->m_xudianchi;
		if(m_pSet->m_mode==1)
			m_edit6="单机模式";
		else
			m_edit6="联网模式";
		m_edit7=(unsigned char)m_pSet->m_zejuxisu;
	}
	else//默认值
	{
		m_edit1=30;
		m_edit2=3;
		m_edit3=3;
		m_edit4=20;
		m_edit5=6.0;
		m_edit6="单机模式";
		m_edit7=10;
	}
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFenjiInfoPage::OnClickUserinfolist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index!=-1)
	{
       m_change1.EnableWindow(TRUE);
       m_delete1.EnableWindow(TRUE);
	}
	else
	{
       m_change1.EnableWindow(FALSE);
       m_delete1.EnableWindow(FALSE);
	}
	*pResult = 0;
}

void CFenjiInfoPage::OnClickMaintenancelist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index=m_list2.GetNextItem(-1,LVNI_SELECTED);
	if(index!=-1)
	{
       m_change2.EnableWindow(TRUE);
       m_delete2.EnableWindow(TRUE);
	}
	else
	{
       m_change2.EnableWindow(FALSE);
       m_delete2.EnableWindow(FALSE);
	}
	*pResult = 0;
}
#include "AddorChangeUserDlg.h"
void CFenjiInfoPage::OnAdd1() 
{
	// TODO: Add your control notification handler code here
	int index,i;
	if(m_list1.GetItemCount()>=6)
	{
		MessageBox("已经有6个用户,不能添加!","提示信息");
		return;
	}
	CAddorChangeUserDlg dlg;
	dlg.m_username="";
	dlg.m_usertel="";
	dlg.m_nflag=0;
	if(dlg.DoModal()==IDOK)
	{
		index=m_list1.GetItemCount();
		m_list1.InsertItem(index,dlg.m_username);
		m_list1.SetItem(index,1,LVIF_TEXT,dlg.m_usertel,0,0,0,NULL);
	}
    m_nuserCount=m_list1.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_username[i]=m_list1.GetItemText(i,0);
       m_usertel[i]=m_list1.GetItemText(i,1);
	}
}
#include "AddorChangeMaintenanceDlg.h"
void CFenjiInfoPage::OnAdd2() 
{
	// TODO: Add your control notification handler code here
	int index,i;
	if(m_list2.GetItemCount()>=6)
	{
		MessageBox("已经有6个维修人员,不能添加!","提示信息");
		return;
	}
	CAddorChangeMaintenanceDlg dlg;
	dlg.m_name="";
	dlg.m_tel="";
	dlg.m_nflag=0;
	if(dlg.DoModal()==IDOK)
	{
		index=m_list2.GetItemCount();
		m_list2.InsertItem(index,dlg.m_name);
		m_list2.SetItem(index,1,LVIF_TEXT,dlg.m_tel,0,0,0,NULL);
	}
    m_nmainteCount=m_list2.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_maintename[i]=m_list2.GetItemText(i,0);
       m_maintetel[i]=m_list2.GetItemText(i,1);
	}	
}

void CFenjiInfoPage::OnChange1() 
{
	// TODO: Add your control notification handler code here
	int index,i;

	index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change1.EnableWindow(FALSE);
        m_delete1.EnableWindow(FALSE);	
		return;
	}
	CString str=m_list1.GetItemText(index,0);
	CAddorChangeUserDlg dlg;
	dlg.m_username=m_list1.GetItemText(index,0);
	dlg.m_usertel=m_list1.GetItemText(index,1);
	dlg.m_nflag=1;

	if(dlg.DoModal()==IDOK)
	{
		m_list1.SetItem(index,0,LVIF_TEXT,dlg.m_username,0,0,0,NULL);
		m_list1.SetItem(index,1,LVIF_TEXT,dlg.m_usertel,0,0,0,NULL);
	}
    m_nuserCount=m_list1.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_username[i]=m_list1.GetItemText(i,0);
       m_usertel[i]=m_list1.GetItemText(i,1);
	}
    m_change1.EnableWindow(FALSE);
    m_delete1.EnableWindow(FALSE);
}

void CFenjiInfoPage::OnChange2() 
{
	// TODO: Add your control notification handler code here
	int index,i;

	index=m_list2.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change2.EnableWindow(FALSE);
        m_delete2.EnableWindow(FALSE);	
		return;
	}
	CString str=m_list2.GetItemText(index,0);
	CAddorChangeMaintenanceDlg dlg;
	dlg.m_name=m_list2.GetItemText(index,0);
	dlg.m_tel=m_list2.GetItemText(index,1);
	dlg.m_nflag=1;

	if(dlg.DoModal()==IDOK)
	{
		m_list2.SetItem(index,0,LVIF_TEXT,dlg.m_name,0,0,0,NULL);
		m_list2.SetItem(index,1,LVIF_TEXT,dlg.m_tel,0,0,0,NULL);
	}
    m_nmainteCount=m_list2.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_maintename[i]=m_list2.GetItemText(i,0);
       m_maintetel[i]=m_list2.GetItemText(i,1);
	}
    m_change2.EnableWindow(FALSE);
    m_delete2.EnableWindow(FALSE);
}

void CFenjiInfoPage::OnDelete1() 
{
	// TODO: Add your control notification handler code here
	int index,i;

    m_change1.EnableWindow(FALSE);
    m_delete1.EnableWindow(FALSE);	
	index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
		return;
	m_list1.DeleteItem(index);
    m_nuserCount=m_list1.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_username[i]=m_list1.GetItemText(i,0);
       m_usertel[i]=m_list1.GetItemText(i,1);
	}
}

void CFenjiInfoPage::OnDelete2() 
{
	// TODO: Add your control notification handler code here
	int index,i;

    m_change2.EnableWindow(FALSE);
    m_delete2.EnableWindow(FALSE);	
	index=m_list2.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
		return;
	m_list2.DeleteItem(index);	
    m_nmainteCount=m_list2.GetItemCount();
	for(i=0;i<m_nuserCount;i++)
	{
       m_maintename[i]=m_list2.GetItemText(i,0);
       m_maintetel[i]=m_list2.GetItemText(i,1);
	}
}
