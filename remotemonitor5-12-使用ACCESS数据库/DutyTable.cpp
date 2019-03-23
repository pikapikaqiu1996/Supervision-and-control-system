// DutyTable.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "DutyTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDutyTable

IMPLEMENT_DYNAMIC(CDutyTable, CRecordset)

CDutyTable::CDutyTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDutyTable)
	m_Id = 0;
	m_Name = _T("");
	m_dutyrecord = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CDutyTable::GetDefaultConnect()
{
	return _T("ODBC;DSN=remotemonitor");
}

CString CDutyTable::GetDefaultSQL()
{
	return _T("[dutytable]");
}

void CDutyTable::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDutyTable)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Date(pFX, _T("[dutytime]"), m_dutytime);
	RFX_Date(pFX, _T("[lefttime]"), m_lefttime);
	RFX_Text(pFX, _T("[dutyrecord]"), m_dutyrecord);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDutyTable diagnostics

#ifdef _DEBUG
void CDutyTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDutyTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
