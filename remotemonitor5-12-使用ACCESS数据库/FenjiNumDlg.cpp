// FenjiNumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "FenjiNumDlg.h"
#include "Draw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFenjiNumDlg dialog


CFenjiNumDlg::CFenjiNumDlg(CDrawObject* usrCurrentObject,CWnd* pParent /*=NULL*/)
	: CDialog(CFenjiNumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFenjiNumDlg)
	m_numedit = 0;
	//}}AFX_DATA_INIT
	m_pusrCurrentObject=(CDrawObject*)usrCurrentObject;
}


void CFenjiNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenjiNumDlg)
	DDX_Control(pDX, IDC_NUMEDIT, m_numeditctl);
	DDX_Control(pDX, IDC_CHANGEFENJINUM, m_changenumctl);
	DDX_Text(pDX, IDC_NUMEDIT, m_numedit);
	DDV_MinMaxInt(pDX, m_numedit, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenjiNumDlg, CDialog)
	//{{AFX_MSG_MAP(CFenjiNumDlg)
	ON_BN_CLICKED(IDC_CHANGEFENJINUM, OnChangefenjinum)
	ON_BN_CLICKED(IDC_DISPLAYFENJIINFO, OnDisplayfenjiinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFenjiNumDlg message handlers

BOOL CFenjiNumDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_numedit=m_pusrCurrentObject->GetMark()/100;

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFenjiNumDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
#include "ChangeFenjinumdlg.h"
void CFenjiNumDlg::OnChangefenjinum() 
{
	// TODO: Add your control notification handler code here
    CChangeFenjinumdlg dlg;
	dlg.m_newnum=m_numedit;
	if(dlg.DoModal()==IDOK)
	{
       m_numedit=dlg.m_newnum;
	   UpdateData(FALSE);
       m_pusrCurrentObject->SetMark(m_numedit*100);
	}
}
#include "FenjiTable.h"
#include "FenjiPropertySheet.h"
void CFenjiNumDlg::OnDisplayfenjiinfo() 
{
	// TODO: Add your control notification handler code here
	CString strFilter;
	CString strfenjinum;
	CFenjiTable table;
	int i;
	int nflag;
//	table.m_strSort=_T("[Id]");
    strFilter=_T("[Id] = ");
	strfenjinum.Format("%d",m_numedit);
    strFilter+=strfenjinum;
	table.m_strFilter = _T(strFilter);
    if(!table.IsOpen())
        table.Open();
	if(table.IsBOF()&&table.IsEOF())
	{
		MessageBox("数据库中没有该分机信息,请录入!","提示信息",MB_OK);
		nflag=0;
	}
	else
		nflag=1;
    CFenjiPropertySheet propSheet(nflag,&table,m_numedit,_T("分机信息"));
	if(propSheet.DoModal()==IDOK)
	{
       if(nflag==0)
	   {
          table.AddNew();
		  table.m_Id=m_numedit;
		  table.m_Name=propSheet.m_Page1.m_fenjiname;
          table.m_telephone=propSheet.m_Page1.m_fenjitel;
		  for(i=0;i<propSheet.m_Page1.m_nuserCount;i++)
		  {
             table.m_username[i]=propSheet.m_Page1.m_username[i];
             table.m_usertel[i]=propSheet.m_Page1.m_usertel[i];
		  }
		  for(i=0;i<propSheet.m_Page1.m_nmainteCount;i++)
		  {
             table.m_maintenance[i]=propSheet.m_Page1.m_maintename[i];
             table.m_maintenancetel[i]=propSheet.m_Page1.m_maintetel[i];
		  }
          table.Update();
	   }
       else
	   {
          table.Edit();
//		  table.m_Id=m_numedit;
		  table.m_Name=propSheet.m_Page1.m_fenjiname;
          table.m_telephone=propSheet.m_Page1.m_fenjitel;
		  for(i=0;i<6;i++)
		  {
             table.m_username[i]="";
             table.m_usertel[i]="";
		  }
		  for(i=0;i<propSheet.m_Page1.m_nuserCount;i++)
		  {
             table.m_username[i]=propSheet.m_Page1.m_username[i];
             table.m_usertel[i]=propSheet.m_Page1.m_usertel[i];
		  }
		  for(i=0;i<6;i++)
		  {
             table.m_maintenance[i]="";
             table.m_maintenancetel[i]="";
		  }
		  for(i=0;i<propSheet.m_Page1.m_nmainteCount;i++)
		  {
             table.m_maintenance[i]=propSheet.m_Page1.m_maintename[i];
             table.m_maintenancetel[i]=propSheet.m_Page1.m_maintetel[i];
		  }
          table.Update();
	   }
	}
    table.Close();
}
