// CableNumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "CableNumDlg.h"
#include "Draw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCableNumDlg dialog


CCableNumDlg::CCableNumDlg(CDrawObject* usrCurrentObject,CWnd* pParent /*=NULL*/)
	: CDialog(CCableNumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCableNumDlg)
	m_cablenumber = 0;
	m_fenjinumber = 0;
	//}}AFX_DATA_INIT
	m_pusrCurrentObject=(CDrawObject*)usrCurrentObject;
}


void CCableNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCableNumDlg)
	DDX_Text(pDX, IDC_CABLENUMBER, m_cablenumber);
	DDV_MinMaxByte(pDX, m_cablenumber, 1, 16);
	DDX_Text(pDX, IDC_FENJINUMBER, m_fenjinumber);
	DDV_MinMaxInt(pDX, m_fenjinumber, 0, 999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCableNumDlg, CDialog)
	//{{AFX_MSG_MAP(CCableNumDlg)
	ON_BN_CLICKED(IDC_CHANGECABLENUM, OnChangecablenum)
	ON_BN_CLICKED(IDC_DISPLAYCABLEINFO, OnDisplaycableinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCableNumDlg message handlers

BOOL CCableNumDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_fenjinumber=m_pusrCurrentObject->GetMark()/100;
    m_cablenumber=m_pusrCurrentObject->GetMark()%100;
    UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCableNumDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
#include "CangeCableNumDlg.h"
void CCableNumDlg::OnChangecablenum() 
{
	// TODO: Add your control notification handler code here
    CCangeCableNumDlg CableNumdlg;
	CableNumdlg.m_newfenjinum=m_fenjinumber;
	CableNumdlg.m_newcablenum=m_cablenumber;
	if(CableNumdlg.DoModal()==IDOK)
	{
       m_fenjinumber=CableNumdlg.m_newfenjinum;
       m_cablenumber=CableNumdlg.m_newcablenum;
	   UpdateData(FALSE);
       m_pusrCurrentObject->SetMark(m_fenjinumber*100+m_cablenumber);
	}	
}
#include "CableInfoTable.h"
#include "CableInfoDlg.h"
void CCableNumDlg::OnDisplaycableinfo() 
{
	// TODO: Add your control notification handler code here
	CString strFilter;
	CString strcablenum;
	CCableInfoTable table;
	int nflag;
//	table.m_strSort=_T("[Id]");
    strFilter=_T("[Id] = ");
	strcablenum.Format("%d",m_fenjinumber*100+m_cablenumber);
    strFilter+=strcablenum;
	table.m_strFilter = _T(strFilter);
    if(!table.IsOpen())
        table.Open();
	if(table.IsBOF()&&table.IsEOF())
	{
		MessageBox("数据库中没有该电缆信息,请录入!","提示信息",MB_OK);
		nflag=0;
	}
	else
		nflag=1;
    CCableInfoDlg InfoDlg;
    InfoDlg.m_nflag=nflag;
    InfoDlg.m_fenjinum=m_fenjinumber;
    InfoDlg.m_cablenum=m_cablenumber;
    InfoDlg.m_pSet=&table;
	if(InfoDlg.DoModal()==IDOK)
	{
       if(nflag==0)
	   {
          table.AddNew();
		  table.m_Id=m_fenjinumber*100+m_cablenumber;
		  table.m_startname=InfoDlg.m_startaddr;
          table.m_endname=InfoDlg.m_endaddr;
          table.Update();
	   }
       else
	   {
          table.Edit();
//		  table.m_Id=m_numedit;
		  table.m_startname=InfoDlg.m_startaddr;
          table.m_endname=InfoDlg.m_endaddr;
          table.Update();
	   }
	}
    table.Close();	
}
