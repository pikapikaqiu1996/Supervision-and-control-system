// StaffTable.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "StaffTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaffTable

IMPLEMENT_DYNAMIC(CStaffTable, CRecordset)

CStaffTable::CStaffTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStaffTable)
	m_Id = 0;
	m_Name = _T("");
	m_Password = _T("");
	m_RightA = FALSE;
	m_RightB = FALSE;
	m_RightC = FALSE;
	m_RightD = FALSE;
	m_Duty = _T("");
	m_Telephone = _T("");
	m_Department = _T("");
	m_Address = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CStaffTable::GetDefaultConnect()
{
	return _T("ODBC;DSN=remotemonitor");
}

CString CStaffTable::GetDefaultSQL()
{
	return _T("[stafftable]");
}

void CStaffTable::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStaffTable)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[Password]"), m_Password);
	RFX_Bool(pFX, _T("[RightA]"), m_RightA);
	RFX_Bool(pFX, _T("[RightB]"), m_RightB);
	RFX_Bool(pFX, _T("[RightC]"), m_RightC);
	RFX_Bool(pFX, _T("[RightD]"), m_RightD);
	RFX_Text(pFX, _T("[Duty]"), m_Duty);
	RFX_Text(pFX, _T("[Telephone]"), m_Telephone);
	RFX_Text(pFX, _T("[Department]"), m_Department);
	RFX_Text(pFX, _T("[Address]"), m_Address);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStaffTable diagnostics

#ifdef _DEBUG
void CStaffTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStaffTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
