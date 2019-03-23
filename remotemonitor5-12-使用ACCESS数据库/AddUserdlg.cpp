// AddUserdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "AddUserdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddUserdlg dialog

CAddUserdlg::CAddUserdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddUserdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddUserdlg)
	m_name = _T("");
	m_pwd = _T("");
	m_duty = _T("");
	m_tel = _T("");
	m_department = _T("");
	m_address = _T("");
	m_righta = FALSE;
	m_rightb = FALSE;
	m_rightc = FALSE;
	m_rightd = FALSE;
	//}}AFX_DATA_INIT
}


void CAddUserdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddUserdlg)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 10);
	DDX_Text(pDX, IDC_PWD, m_pwd);
	DDV_MaxChars(pDX, m_pwd, 6);
	DDX_Text(pDX, IDC_DUTY, m_duty);
	DDV_MaxChars(pDX, m_duty, 10);
	DDX_Text(pDX, IDC_TEL, m_tel);
	DDV_MaxChars(pDX, m_tel, 13);
	DDX_Text(pDX, IDC_DEPARTMENT, m_department);
	DDV_MaxChars(pDX, m_department, 20);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDV_MaxChars(pDX, m_address, 20);
	DDX_Check(pDX, IDC_RIGHTA, m_righta);
	DDX_Check(pDX, IDC_RIGHTB, m_rightb);
	DDX_Check(pDX, IDC_RIGHTC, m_rightc);
	DDX_Check(pDX, IDC_RIGHTD, m_rightd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddUserdlg, CDialog)
	//{{AFX_MSG_MAP(CAddUserdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddUserdlg message handlers

BOOL CAddUserdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_flag==0)//加
	{
		SetWindowText("添加用户信息");
		GetDlgItem(IDC_NAME)->EnableWindow(TRUE);
	}
	else
	{
		SetWindowText("修改用户信息");
		GetDlgItem(IDC_NAME)->EnableWindow(FALSE);
		m_name=m_pSet->m_Name;
		m_pwd=m_pSet->m_Password;
		m_duty=m_pSet->m_Duty;
		m_tel=m_pSet->m_Telephone;
		m_department=m_pSet->m_Department;
		m_address=m_pSet->m_Address;
        m_righta=m_pSet->m_RightA;
        m_rightb=m_pSet->m_RightB;
        m_rightc=m_pSet->m_RightC;
        m_rightd=m_pSet->m_RightD;
	}
    UpdateData(FALSE);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddUserdlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_name=="")
	{
		MessageBox("没有输入姓名,请输入!","提示信息");
		return;
	}
	if(m_pwd=="")
	{
		MessageBox("没有输入密码,请输入!","提示信息");
		return;
	}
	if(m_flag==0)
	{
       m_pSet->AddNew();
	   m_pSet->m_Name= m_name;
	   m_pSet->m_Password= m_pwd;
	   m_pSet->m_Duty= m_duty;
	   m_pSet->m_Telephone= m_tel;
	   m_pSet->m_Department= m_department;
	   m_pSet->m_Address= m_address;
       m_pSet->m_RightA= m_righta;
       m_pSet->m_RightB= m_rightb;
       m_pSet->m_RightC= m_rightc;
       m_pSet->m_RightD= m_rightd;
	   m_pSet->Update();
	}
	else
	{
       m_pSet->Edit();
//	   m_pSet->m_Name= m_name;
	   m_pSet->m_Password= m_pwd;
	   m_pSet->m_Duty= m_duty;
	   m_pSet->m_Telephone= m_tel;
	   m_pSet->m_Department= m_department;
	   m_pSet->m_Address= m_address;
       m_pSet->m_RightA= m_righta;
       m_pSet->m_RightB= m_rightb;
       m_pSet->m_RightC= m_rightc;
       m_pSet->m_RightD= m_rightd;
	   m_pSet->Update();
	}
	CDialog::OnOK();
}
