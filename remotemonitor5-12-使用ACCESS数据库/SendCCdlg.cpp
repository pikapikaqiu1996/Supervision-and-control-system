// SendCCdlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "SendCCdlg.h"
#include "FenjiTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendCCdlg dialog


CSendCCdlg::CSendCCdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendCCdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendCCdlg)
	m_radio1 = 0;
	m_fenjinumber = 0;
	m_bprobe = FALSE;
	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
	m_edit4 = 0;
	m_edit5 = 6.0;
	m_edit7 = 0;
	//}}AFX_DATA_INIT
}


void CSendCCdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendCCdlg)
	DDX_Control(pDX, IDC_SPIN7, m_spin7);
	DDX_Control(pDX, IDC_SPIN4, m_spin4);
	DDX_Control(pDX, IDC_SPIN3, m_spin3);
	DDX_Control(pDX, IDC_SPIN2, m_spin2);
	DDX_Control(pDX, IDC_SPIN1, m_spin1);
	DDX_Control(pDX, IDC_COMBO6, m_combo6);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 0, 999);
	DDX_Check(pDX, IDC_PROBE, m_bprobe);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDV_MinMaxInt(pDX, m_edit1, 1, 99);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDV_MinMaxInt(pDX, m_edit2, 1, 30);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDV_MinMaxInt(pDX, m_edit3, 1, 9);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDV_MinMaxInt(pDX, m_edit4, 20, 255);
	DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDV_MinMaxFloat(pDX, m_edit5, 1.1f, 9.9f);
	DDX_Text(pDX, IDC_EDIT7, m_edit7);
	DDV_MinMaxInt(pDX, m_edit7, 10, 99);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendCCdlg, CDialog)
	//{{AFX_MSG_MAP(CSendCCdlg)
	ON_BN_CLICKED(IDC_PROBE, OnProbe)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendCCdlg message handlers

BOOL CSendCCdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_spin1.SetRange(1,99);
	m_spin1.SetPos(30);
	m_spin2.SetRange(1,30);
	m_spin2.SetPos(3);
	m_spin3.SetRange(1,9);
	m_spin3.SetPos(3);
	m_spin4.SetRange(20,255);
	m_spin4.SetPos(20);
	m_spin7.SetRange(10,99);
	m_spin7.SetPos(52);
    m_combo6.AddString ("单机模式");
    m_combo6.AddString ("联网模式");
    m_combo6.SetCurSel(0);
    DisplaySomeWnd();
	m_edit5=6.0;
//	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSendCCdlg::OnOK() 
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
    m_strInfo+="#";
    switch(m_radio1)
	{
	case 0:
	   if(m_bprobe==TRUE)
		   str="00";
	   else
	   {
		   table.Edit();
           table.m_ackwaittime=m_edit1;
		   table.Update();
		   str.Format("%2.2d",m_edit1);
	   }
       m_strInfo+=str;
	   break;
	case 1:
	   if(m_bprobe==TRUE)
		   str="00";
	   else
	   {
		   table.Edit();
           table.m_sensitive=m_edit2;
		   table.Update();
		   str.Format("%2.2d",m_edit2);
	   }
       m_strInfo+=str;
	   break;
	case 2:
	   if(m_bprobe==TRUE)
		   str="0";
	   else
	   {
		   table.Edit();
           table.m_callnumber=m_edit3;
		   table.Update();

		   str.Format("%d",m_edit3);
	   }
       m_strInfo+=str;
	   break;
	case 3:
	   if(m_bprobe==TRUE)
		   str="000";
	   else
	   {
		   table.Edit();
           table.m_waittime=m_edit4;
		   table.Update();
		   
		   str.Format("%3.3d",m_edit4);
	   }
       m_strInfo+=str;
	   break;
	case 4:
	   if(m_bprobe==TRUE)
		   str="00";
	   else
	   {
		   table.Edit();
           table.m_xudianchi=m_edit5;
		   table.Update();
		   str.Format("%2.2d",(int)(m_edit5*10.000001));
	   }
       m_strInfo+=str;
	   break;
	case 5:
	   if(m_bprobe==TRUE)
		   str="0";
	   else
	   {
		   table.Edit();
           table.m_mode=m_combo6.GetCurSel()+1;
		   table.Update();

		   str.Format("%d",m_combo6.GetCurSel()+1);
	   }
       m_strInfo+=str;
	   break;
	case 6:
	   if(m_bprobe==TRUE)
		   str="00";
	   else
	   {
		   table.Edit();
           table.m_zejuxisu=m_edit7;
		   table.Update();

		   str.Format("%2.2d",m_edit7);
	   }
       m_strInfo+=str;
	   break;
	default:
		   break;
	}
	table.Close();

	CDialog::OnOK();
}

void CSendCCdlg::OnProbe() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    DisplaySomeWnd();
}
void CSendCCdlg::DisplaySomeWnd()
{
    if(m_bprobe==FALSE)
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO6)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN1)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN2)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN3)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN4)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN7)->EnableWindow(FALSE);

        switch(m_radio1)
		{
		case 0:
		  GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		  GetDlgItem(IDC_SPIN1)->EnableWindow(TRUE);

          break;
		case 1:
		  GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
		  GetDlgItem(IDC_SPIN2)->EnableWindow(TRUE);

          break;
		case 2:
		  GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
		  GetDlgItem(IDC_SPIN3)->EnableWindow(TRUE);

          break;
		case 3:
		  GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
		  GetDlgItem(IDC_SPIN4)->EnableWindow(TRUE);

          break;
		case 4:
		  GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
          break;
		case 5:
		  GetDlgItem(IDC_COMBO6)->EnableWindow(TRUE);
          break;
		case 6:
		  GetDlgItem(IDC_EDIT7)->EnableWindow(TRUE);
		  GetDlgItem(IDC_SPIN7)->EnableWindow(TRUE);

          break;
        default:
			break;
		}
	}
	else
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO6)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN1)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN2)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN3)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN4)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN7)->EnableWindow(FALSE);
	}
}

void CSendCCdlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    DisplaySomeWnd();
	
}
