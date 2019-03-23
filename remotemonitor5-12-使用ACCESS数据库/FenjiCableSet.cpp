// FenjiCableSet.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "FenjiCableSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFenjiCableSet dialog


CFenjiCableSet::CFenjiCableSet(CWnd* pParent /*=NULL*/)
	: CDialog(CFenjiCableSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFenjiCableSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFenjiCableSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenjiCableSet)
	DDX_Control(pDX, IDC_DELETE2, m_delete2);
	DDX_Control(pDX, IDC_DELETE1, m_delete1);
	DDX_Control(pDX, IDC_CHANGE2, m_change2);
	DDX_Control(pDX, IDC_CHANGE1, m_change1);
	DDX_Control(pDX, IDC_CABLELIST, m_list2);
	DDX_Control(pDX, IDC_FENJILIST, m_list1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenjiCableSet, CDialog)
	//{{AFX_MSG_MAP(CFenjiCableSet)
	ON_BN_CLICKED(IDC_ADD1, OnAdd1)
	ON_BN_CLICKED(IDC_CHANGE1, OnChange1)
	ON_BN_CLICKED(IDC_DELETE1, OnDelete1)
	ON_BN_CLICKED(IDC_ADD2, OnAdd2)
	ON_BN_CLICKED(IDC_CHANGE2, OnChange2)
	ON_BN_CLICKED(IDC_DELETE2, OnDelete2)
	ON_NOTIFY(NM_CLICK, IDC_CABLELIST, OnClickCablelist)
	ON_NOTIFY(NM_CLICK, IDC_FENJILIST, OnClickFenjilist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFenjiCableSet message handlers

BOOL CFenjiCableSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str;

	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_list1.InsertColumn( 0, "分机号", LVCFMT_LEFT,60, 0 );
    m_list1.InsertColumn( 1, "分机名", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 2, "分机电话", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 3, "用户1", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 4, "用户电话1", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 5, "用户2", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 6, "用户电话2", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 7, "用户3", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 8, "用户电话3", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 9, "用户4", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 10, "用户电话4", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 11, "用户5", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 12, "用户电话5", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 13, "用户6", LVCFMT_LEFT,70, 0 );
    m_list1.InsertColumn( 14, "用户电话6", LVCFMT_LEFT,100, 0 );
	m_list1.InsertColumn( 15, "维护1", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 16, "维护电话1",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 17, "维护2", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 18, "维护电话2",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 19, "维护3", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 20, "维护电话3",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 21, "维护4", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 22, "维护电话4",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 23, "维护5", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 24, "维护电话5",   LVCFMT_LEFT,100,0);
	m_list1.InsertColumn( 25, "维护6", LVCFMT_LEFT,70,0);
    m_list1.InsertColumn( 26, "维护电话6",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 27, "无应答等待时间",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 28, "灵敏度",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 29, "循环拨打次数",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 30, "布防等待时间",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 31, "电压转折点",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 32, "本机模式",   LVCFMT_LEFT,100,0);
    m_list1.InsertColumn( 33, "测距系数",   LVCFMT_LEFT,100,0);

	m_list2.InsertColumn( 0, "分机号", LVCFMT_LEFT,60, 0 );
    m_list2.InsertColumn( 1, "电缆号", LVCFMT_LEFT,100, 0 );
    m_list2.InsertColumn( 2, "电缆起点", LVCFMT_LEFT,100, 0 );
	m_list2.InsertColumn( 3, "电缆终点", LVCFMT_LEFT,100, 0 );
    m_list2.InsertColumn( 4, "功能设置", LVCFMT_LEFT,100, 0 );


	m_table1.m_strSort=_T("[Id]");
	if(!m_table1.IsOpen())
       m_table1.Open();
    InSertList1();

	m_table2.m_strSort=_T("[Id]");
	if(!m_table2.IsOpen())
       m_table2.Open();
	InSertList2();

    m_change1.EnableWindow(FALSE);
    m_delete1.EnableWindow(FALSE);
    m_change2.EnableWindow(FALSE);
    m_delete2.EnableWindow(FALSE);

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CFenjiCableSet::InSertList2()
{
	int ntotalItem;
	CString str;
    while (!m_table2.IsEOF())
	{
		ntotalItem = m_list2.GetItemCount();
		str.Format("%3.3d",m_table2.m_Id/100);
		m_list2.InsertItem(ntotalItem,str);
		str.Format("%3.3d",m_table2.m_Id%100);
		m_list2.SetItem(ntotalItem,1,LVIF_TEXT,_T(str),0,0,0,NULL);
		m_list2.SetItem(ntotalItem,2,LVIF_TEXT,_T(m_table2.m_startname),0,0,0,NULL);
		m_list2.SetItem(ntotalItem,3,LVIF_TEXT,_T(m_table2.m_endname),0,0,0,NULL);
		if(m_table2.m_Id%100<=8)
		{
			if(m_table2.m_state==0)
				str="撤防";
			else
				str="布防";
		}
		else
		{
			switch(m_table2.m_state)
			{
			case 0:
				str="布防";
				break;
			case 1:
				str="温度告警";
				break;
			case 2:
				str="湿度告警";
				break;
			case 3:
				str="红外告警";
				break;
			case 4:
				str="门禁告警";
				break;
			case 5:
				str="烟雾告警";
				break;
			case 6:
				str="浸水告警";
				break;
			case 7:
				str="有害气体告警";
			case 8:
				str="撤防";
				break;
			default:
				break;
				
			}
		}
		m_list2.SetItem(ntotalItem,4,LVIF_TEXT,_T(str),0,0,0,NULL);
		m_table2.MoveNext();
	}
}

void CFenjiCableSet::InSertList1()
{
	int i,ntotalItem;
	CString str;

	while (!m_table1.IsEOF())
	{
		ntotalItem = m_list1.GetItemCount();
		str.Format("%3.3d",m_table1.m_Id);
		m_list1.InsertItem(ntotalItem,str);
		m_list1.SetItem(ntotalItem,1,LVIF_TEXT,_T(m_table1.m_Name),0,0,0,NULL);
		m_list1.SetItem(ntotalItem,2,LVIF_TEXT,_T(m_table1.m_telephone),0,0,0,NULL);
		for(i=0;i<6;i++)
		{
			m_list1.SetItem(ntotalItem,i*2+3,LVIF_TEXT,_T(m_table1.m_username[i]),0,0,0,NULL);
			m_list1.SetItem(ntotalItem,i*2+4,LVIF_TEXT,_T(m_table1.m_usertel[i]),0,0,0,NULL);
			m_list1.SetItem(ntotalItem,i*2+15,LVIF_TEXT,_T(m_table1.m_maintenance[i]),0,0,0,NULL);
			m_list1.SetItem(ntotalItem,i*2+16,LVIF_TEXT,_T(m_table1.m_maintenancetel[i]),0,0,0,NULL);
		}
		str.Format("%d",m_table1.m_ackwaittime);
		m_list1.SetItem(ntotalItem,27,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_sensitive);
		m_list1.SetItem(ntotalItem,28,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_callnumber);
		m_list1.SetItem(ntotalItem,29,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_waittime);
		m_list1.SetItem(ntotalItem,30,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%2.1f",m_table1.m_xudianchi);
		m_list1.SetItem(ntotalItem,31,LVIF_TEXT,_T(str),0,0,0,NULL);
		if(m_table1.m_mode==1)
		   str="单机模式";
		else 
		   str="联网模式";
		m_list1.SetItem(ntotalItem,32,LVIF_TEXT,_T(str),0,0,0,NULL);
		str.Format("%d",m_table1.m_zejuxisu);
		m_list1.SetItem(ntotalItem,33,LVIF_TEXT,_T(str),0,0,0,NULL);

        m_table1.MoveNext();
	}
}
void CFenjiCableSet::OnOK() 
{
	// TODO: Add extra validation here
	if(m_table1.IsOpen())
       m_table1.Close();
	if(m_table2.IsOpen())
       m_table2.Close();
	CDialog::OnOK();
}
#include "AddorChangeFenjiInfo.h"
void CFenjiCableSet::OnAdd1() 
{
	// TODO: Add your control notification handler code here
	CAddorChangeFenjiInfo dlg;
	dlg.m_flag=0;//加
    dlg.m_pSet=&m_table1;
	if(dlg.DoModal()==IDOK)
	{
       m_list1.DeleteAllItems();
       m_table1.m_strSort=_T("[Id]");
       m_table1.m_strFilter=_T("");
       m_table1.Requery();
       InSertList1();
	}

}

void CFenjiCableSet::OnChange1() 
{
	// TODO: Add your control notification handler code here
	int index;
    CString str;

	index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change1.EnableWindow(FALSE);
        m_delete1.EnableWindow(FALSE);	
		return;
	}

	str=m_list1.GetItemText(index,0);
	m_table1.m_strFilter=_T("[Id]= ");
    m_table1.m_strFilter+=str;
    m_table1.Requery();
	CAddorChangeFenjiInfo dlg;
	dlg.m_flag=1;//
    dlg.m_pSet=&m_table1;
	if(dlg.DoModal()==IDOK)
	{
       m_list1.DeleteAllItems();
       m_table1.m_strSort=_T("[Id]");
       m_table1.m_strFilter=_T("");
       m_table1.Requery();
       InSertList1();
	}
    m_change1.EnableWindow(FALSE);
    m_delete1.EnableWindow(FALSE);	
}

void CFenjiCableSet::OnDelete1() 
{
	// TODO: Add your control notification handler code here
	int index;
    CString str;

	index=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change1.EnableWindow(FALSE);
        m_delete1.EnableWindow(FALSE);	
		return;
	}
	str=m_list1.GetItemText(index,0);
	m_table1.m_strFilter=_T("[Id]= ");
    m_table1.m_strFilter+=str;
    m_table1.Requery();
    m_table1.Delete();
    m_table1.MoveNext();
	m_list1.DeleteItem(index);
    m_change1.EnableWindow(FALSE);
    m_delete1.EnableWindow(FALSE);		
}
#include "CableInfoSet.h"
void CFenjiCableSet::OnAdd2() 
{
	// TODO: Add your control notification handler code here
	CCableInfoSet dlg;
	dlg.m_flag=0;//加
    dlg.m_pSet=&m_table2;
	if(dlg.DoModal()==IDOK)
	{
       m_list2.DeleteAllItems();
       m_table2.m_strSort=_T("[Id]");
       m_table2.m_strFilter=_T("");
       m_table2.Requery();
       InSertList2();
	}	
}

void CFenjiCableSet::OnChange2() 
{
	// TODO: Add your control notification handler code here

	int index;
	int fenjinum,cablenum;
    CString str;

	index=m_list2.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change2.EnableWindow(FALSE);
        m_delete2.EnableWindow(FALSE);	
		return;
	}

	str=m_list2.GetItemText(index,0);
	fenjinum=atoi(str);
	str=m_list2.GetItemText(index,1);
	cablenum=atoi(str);
	str.Format("%d",fenjinum*100+cablenum);
	m_table2.m_strFilter=_T("[Id]= ");
    m_table2.m_strFilter+=str;
    m_table2.Requery();

	CCableInfoSet dlg;
	dlg.m_flag=1;
    dlg.m_pSet=&m_table2;
	dlg.m_fenjinum=fenjinum;
	dlg.m_cablenum=cablenum;
	if(dlg.DoModal()==IDOK)
	{
       m_list2.DeleteAllItems();
       m_table2.m_strSort=_T("[Id]");
       m_table2.m_strFilter=_T("");
       m_table2.Requery();
       InSertList2();
	}

    m_change2.EnableWindow(FALSE);
    m_delete2.EnableWindow(FALSE);	

}

void CFenjiCableSet::OnDelete2() 
{
	// TODO: Add your control notification handler code here
	int index,fenjinum,cablenum;
    CString str;

	index=m_list2.GetNextItem(-1,LVNI_SELECTED);
	if(index==-1)
	{
        m_change2.EnableWindow(FALSE);
        m_delete2.EnableWindow(FALSE);	
		return;
	}
	str=m_list2.GetItemText(index,0);
    fenjinum=atoi(str);
	str=m_list2.GetItemText(index,1);
    cablenum=atoi(str);
	str.Format("%d",fenjinum*100+cablenum);
	m_table2.m_strFilter=_T("[Id]= ");
    m_table2.m_strFilter+=str;
    m_table2.Requery();
    m_table2.Delete();
    m_table2.MoveNext();
	m_list2.DeleteItem(index);
    m_change2.EnableWindow(FALSE);
    m_delete2.EnableWindow(FALSE);			
}

void CFenjiCableSet::OnClickCablelist(NMHDR* pNMHDR, LRESULT* pResult) 
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

void CFenjiCableSet::OnClickFenjilist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nIndex;

	nIndex=m_list1.GetNextItem(-1,LVNI_SELECTED);
	if(nIndex!=-1)
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
