// CableInfoSet.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "CableInfoSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCableInfoSet dialog


CCableInfoSet::CCableInfoSet(CWnd* pParent /*=NULL*/)
	: CDialog(CCableInfoSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCableInfoSet)
	m_fenjinum = 0;
	m_startaddr = _T("");
	m_endaddr = _T("");
	//}}AFX_DATA_INIT
}


void CCableInfoSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCableInfoSet)
	DDX_Control(pDX, IDC_CABLECOMBO, m_comboctl);
	DDX_Text(pDX, IDC_FENJINUM, m_fenjinum);
	DDV_MinMaxInt(pDX, m_fenjinum, 0, 999);
	DDX_Text(pDX, IDC_STARTADDR, m_startaddr);
	DDV_MaxChars(pDX, m_startaddr, 20);
	DDX_Text(pDX, IDC_ENDADDR, m_endaddr);
	DDV_MaxChars(pDX, m_endaddr, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCableInfoSet, CDialog)
	//{{AFX_MSG_MAP(CCableInfoSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCableInfoSet message handlers

BOOL CCableInfoSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    int i;
	CString str;

	if(m_flag==0)
	{
		SetWindowText("添加电缆信息");
		GetDlgItem(IDC_FENJINUM)->EnableWindow(TRUE);
		GetDlgItem(IDC_CABLECOMBO)->EnableWindow(TRUE);
		for(i=0;i<16;i++)
		{
			str.Format("%d",i+1);
            m_comboctl.AddString(str);
		}
        m_comboctl.SetCurSel(0);
	}
	else
	{
		SetWindowText("修改电缆信息");
		GetDlgItem(IDC_FENJINUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_CABLECOMBO)->EnableWindow(FALSE);
		for(i=0;i<16;i++)
		{
			str.Format("%d",i+1);
            m_comboctl.AddString(str);
		}
        m_comboctl.SetCurSel(m_cablenum-1);
        m_startaddr=m_pSet->m_startname;
        m_endaddr=m_pSet->m_endname;
	}
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCableInfoSet::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CString str;

	if(m_startaddr==""||m_endaddr=="")
	{
		MessageBox("没有输入电缆起点或终点地址,请输入!","提示信息");
		return;
	}
	if(m_flag==0)//当前为ADD
	{
		str.Format("%d",m_fenjinum*100+m_comboctl.GetCurSel()+1);
		m_pSet->m_strFilter=_T("ID =");
		m_pSet->m_strFilter+=str;
		m_pSet->Requery();
		if(m_pSet->IsEOF()&&m_pSet->IsBOF())//为空
		{
			m_pSet->AddNew();
			m_pSet->m_Id=m_fenjinum*100+m_comboctl.GetCurSel()+1;
			m_pSet->m_startname= m_startaddr;
			m_pSet->m_endname  = m_endaddr;
			m_pSet->Update();
		}
		else
		{
		   str.Format("%3.3d号分机%2.2d号电缆",m_fenjinum,m_comboctl.GetCurSel()+1);
		   MessageBox("数据库中已有"+str+"信息,请重新输入分机、电缆号!","提示信息");
		   return;
		}
	}
    else
	{
		m_pSet->Edit();
		m_pSet->m_startname= m_startaddr;
		m_pSet->m_endname  = m_endaddr;
		m_pSet->Update();
	}
    
	CDialog::OnOK();
}
