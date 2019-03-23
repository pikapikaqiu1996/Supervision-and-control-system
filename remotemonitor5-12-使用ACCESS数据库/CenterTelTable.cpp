// CenterTelTable.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "CenterTelTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCenterTelTable

IMPLEMENT_DYNAMIC(CCenterTelTable, CRecordset)

CCenterTelTable::CCenterTelTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCenterTelTable)
	m_Id = 0;
	m_telephone = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CCenterTelTable::GetDefaultConnect()
{
	return _T("ODBC;DSN=remotemonitor");
}

CString CCenterTelTable::GetDefaultSQL()
{
	return _T("[centertel]");
}

void CCenterTelTable::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCenterTelTable)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[telephone]"), m_telephone);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCenterTelTable diagnostics

#ifdef _DEBUG
void CCenterTelTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCenterTelTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
