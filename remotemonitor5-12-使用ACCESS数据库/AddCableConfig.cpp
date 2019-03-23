// AddCableConfig.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "AddCableConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddCableConfig dialog


CAddCableConfig::CAddCableConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CAddCableConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddCableConfig)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAddCableConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddCableConfig)
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddCableConfig, CDialog)
	//{{AFX_MSG_MAP(CAddCableConfig)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddCableConfig message handlers

BOOL CAddCableConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int i;
	CString str;

	for(i=1;i<=16;i++)
	{
		if(!Serch(i))
		{
			str.Format("%2.2d",i);
			m_combo1.AddString(str);
		}
	}
    m_combo1.SetCurSel(0);
    m_combo1.GetLBText(0,str);
	if(atoi(str)<=8)
	{
		m_combo2.AddString("电缆撤防");
		m_combo2.AddString("电缆布防");
	}
	else
	{
       m_combo2.AddString("电缆撤防");
       m_combo2.AddString("电缆布防");
       m_combo2.AddString("温度告警");
       m_combo2.AddString("湿度告警");
       m_combo2.AddString("红外告警");
       m_combo2.AddString("门禁告警");
       m_combo2.AddString("烟雾告警");
       m_combo2.AddString("浸水告警");
       m_combo2.AddString("有害气体告警");
	}
	m_combo2.SetCurSel(0);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
BOOL CAddCableConfig::Serch(int i)
{
	BOOL bSerched=FALSE;
	for(int n=0;n<m_nTotalItem;n++)
	{
	   if(m_nArray[n]==i)
       {
          bSerched=TRUE;
          break;
	   }
	}
	return bSerched;

}
void CAddCableConfig::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString str;
//	m_cable=m_combo1.GetCurSel()+1;
	m_combo1.GetLBText(m_combo1.GetCurSel(),str);
    m_cable=atoi(str);

	if(m_cable>8)
	{
       m_combo2.ResetContent();
       m_combo2.AddString("电缆撤防");
       m_combo2.AddString("电缆布防");
       m_combo2.AddString("温度告警");
       m_combo2.AddString("湿度告警");
       m_combo2.AddString("红外告警");
       m_combo2.AddString("门禁告警");
       m_combo2.AddString("烟雾告警");
       m_combo2.AddString("浸水告警");
       m_combo2.AddString("有害气体告警");
	}
	else
	{
	   m_combo2.ResetContent();
       m_combo2.AddString("电缆撤防");
       m_combo2.AddString("电缆布防");
	}
    m_combo2.SetCurSel(0);
	UpdateData(FALSE);
}

void CAddCableConfig::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CString str;
//	m_cable=m_combo1.GetCurSel()+1;
	m_combo1.GetLBText(m_combo1.GetCurSel(),str);
    m_cable=atoi(str);
	m_type=m_combo2.GetCurSel();

	CDialog::OnOK();
}
