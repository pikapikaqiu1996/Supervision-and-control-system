// AddorChangeFenjiInfo.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "AddorChangeFenjiInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeFenjiInfo dialog


CAddorChangeFenjiInfo::CAddorChangeFenjiInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CAddorChangeFenjiInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddorChangeFenjiInfo)
	m_fenjinum = 0;
	m_fenjitel = _T("");
	m_fenjiname = _T("");
	//}}AFX_DATA_INIT
}


void CAddorChangeFenjiInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddorChangeFenjiInfo)
	DDX_Control(pDX, IDC_DELETE2, m_delete2);
	DDX_Control(pDX, IDC_DELETE1, m_delete1);
	DDX_Control(pDX, IDC_CHANGE2, m_change2);
	DDX_Control(pDX, IDC_CHANGE1, m_change1);
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


BEGIN_MESSAGE_MAP(CAddorChangeFenjiInfo, CDialog)
	//{{AFX_MSG_MAP(CAddorChangeFenjiInfo)
	ON_BN_CLICKED(IDC_ADD1, OnAdd1)
	ON_BN_CLICKED(IDC_CHANGE1, OnChange1)
	ON_BN_CLICKED(IDC_DELETE1, OnDelete1)
	ON_BN_CLICKED(IDC_ADD2, OnAdd2)
	ON_BN_CLICKED(IDC_CHANGE2, OnChange2)
	ON_BN_CLICKED(IDC_DELETE2, OnDelete2)
	ON_NOTIFY(NM_CLICK, IDC_USERINFOLIST, OnClickUserinfolist)
	ON_NOTIFY(NM_CLICK, IDC_MAINTENANCELIST, OnClickMaintenancelist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeFenjiInfo message handlers

BOOL CAddorChangeFenjiInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int i,j;
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT/*|LVS_EX_GRIDLINES|LVS_EX_TRACKSELECT*/);
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CString str;
	m_list1.InsertColumn( 0, "用  户", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 1, "电  话", LVCFMT_LEFT,100, 0 );
	m_list2.InsertColumn( 0, "维修人员", LVCFMT_LEFT,70,0);
    m_list2.InsertColumn( 1, "电  话",   LVCFMT_LEFT,100,0);

	if(m_flag==0)//加]
	{
		SetWindowText("添加分机信息");
		GetDlgItem(IDC_FENJINUM)->EnableWindow(TRUE);
	}
	else
	{
		SetWindowText("修改分机信息");
		GetDlgItem(IDC_FENJINUM)->EnableWindow(FALSE);
		m_fenjinum=m_pSet->m_Id;
		m_fenjiname=m_pSet->m_Name;
		m_fenjitel=m_pSet->m_telephone;
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
    m_change1.EnableWindow(FALSE);
    m_delete1.EnableWindow(FALSE);
    m_change2.EnableWindow(FALSE);
    m_delete2.EnableWindow(FALSE);
    UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

#include "AddorChangeUserDlg.h"
void CAddorChangeFenjiInfo::OnAdd1() 
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

void CAddorChangeFenjiInfo::OnChange1() 
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

void CAddorChangeFenjiInfo::OnDelete1() 
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
#include "AddorChangeMaintenanceDlg.h"
void CAddorChangeFenjiInfo::OnAdd2() 
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

void CAddorChangeFenjiInfo::OnChange2() 
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

void CAddorChangeFenjiInfo::OnDelete2() 
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

void CAddorChangeFenjiInfo::OnClickUserinfolist(NMHDR* pNMHDR, LRESULT* pResult) 
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

void CAddorChangeFenjiInfo::OnClickMaintenancelist(NMHDR* pNMHDR, LRESULT* pResult) 
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

void CAddorChangeFenjiInfo::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	int i;

	UpdateData(TRUE);

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

	if(m_fenjitel==""||m_fenjiname=="")
	{
		MessageBox("没有输入分机名或分机电话,请重新输入!","提示信息");
		return;
	}

	if(m_flag==0)//当前为ADD
	{
		str.Format("%d",m_fenjinum);
		m_pSet->m_strFilter=_T("ID =");
		m_pSet->m_strFilter+=str;
		m_pSet->Requery();
		if(m_pSet->IsEOF()&&m_pSet->IsBOF())//为空
		{
			m_pSet->AddNew();
			m_pSet->m_Id=m_fenjinum;
			m_pSet->m_Name=m_fenjiname;
			m_pSet->m_telephone=m_fenjitel;
			for(i=0;i<m_nuserCount;i++)
			{
				m_pSet->m_username[i]=m_username[i];
				m_pSet->m_usertel[i]=m_usertel[i];
			}
			for(i=0;i<m_nmainteCount;i++)
			{
				m_pSet->m_maintenance[i]=m_maintename[i];
				m_pSet->m_maintenancetel[i]=m_maintetel[i];
			}
			m_pSet->Update();
		}
		else
		{
		   MessageBox("数据库中已有"+str+"号分机信息,请重新输入分机号!","提示信息");
		   return;
		}
	}
	else//当前为修改
	{
          m_pSet->Edit();
//		  table.m_Id=m_numedit;
		  m_pSet->m_Name=m_fenjiname;
          m_pSet->m_telephone=m_fenjitel;
		  for(i=0;i<6;i++)
		  {
             m_pSet->m_username[i]="";
             m_pSet->m_usertel[i]="";
		  }
		  for(i=0;i<m_nuserCount;i++)
		  {
             m_pSet->m_username[i]=m_username[i];
             m_pSet->m_usertel[i]=m_usertel[i];
		  }
		  for(i=0;i<6;i++)
		  {
             m_pSet->m_maintenance[i]="";
             m_pSet->m_maintenancetel[i]="";
		  }
		  for(i=0;i<m_nmainteCount;i++)
		  {
             m_pSet->m_maintenance[i]=m_maintename[i];
             m_pSet->m_maintenancetel[i]=m_maintetel[i];
		  }
          m_pSet->Update();
	}
	CDialog::OnOK();
}
