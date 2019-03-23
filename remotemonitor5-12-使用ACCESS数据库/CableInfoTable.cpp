// CableInfoTable.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "CableInfoTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCableInfoTable

IMPLEMENT_DYNAMIC(CCableInfoTable, CRecordset)

CCableInfoTable::CCableInfoTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCableInfoTable)
	m_Id = 0;
	m_startname = _T("");
	m_endname = _T("");
	m_state = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CCableInfoTable::GetDefaultConnect()
{
	return _T("ODBC;DSN=remotemonitor");
}

CString CCableInfoTable::GetDefaultSQL()
{
	return _T("[cableinfotable]");
}

void CCableInfoTable::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCableInfoTable)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[startname]"), m_startname);
	RFX_Text(pFX, _T("[endname]"), m_endname);
	RFX_Byte(pFX, _T("[state]"), m_state);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCableInfoTable diagnostics

#ifdef _DEBUG
void CCableInfoTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCableInfoTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
