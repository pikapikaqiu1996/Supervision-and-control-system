// DutyRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "DutyRecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDutyRecordDlg dialog
extern CString strCurrentUser;
extern CString strDutyTime;


CDutyRecordDlg::CDutyRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDutyRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDutyRecordDlg)
	m_dutyrecord = _T("");
	//}}AFX_DATA_INIT
}


void CDutyRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDutyRecordDlg)
	DDX_Text(pDX, IDC_RECORD, m_dutyrecord);
	DDV_MaxChars(pDX, m_dutyrecord, 200);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDutyRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CDutyRecordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDutyRecordDlg message handlers

BOOL CDutyRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
#include "DutyTable.h"
void CDutyRecordDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	CDutyTable dutytable;
    if(m_dutyrecord!="")
	{
		CString strFilter = _T("[Name] = '");
		strFilter +=  strCurrentUser;
		strFilter+="'";
		strFilter+=" AND ";
		strFilter+=_T("[dutytime] = #");
		strFilter+=strDutyTime;
		strFilter+="#";
		dutytable.m_strFilter = _T(strFilter);
		
		dutytable.Open();
		if(!dutytable.IsBOF())//²»Îª¿Õ
		{
			dutytable.Edit();
			dutytable.m_dutyrecord=m_dutyrecord;
			dutytable.Update();
		}
		if(dutytable.IsOpen())
			dutytable.Close();		
	}
	CDialog::OnOK();
}
