// CableAlarmTable.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "CableAlarmTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCableAlarmTable

IMPLEMENT_DYNAMIC(CCableAlarmTable, CRecordset)

CCableAlarmTable::CCableAlarmTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCableAlarmTable)
	m_Id = 0;
	m_cablenumber = 0;
	m_fenjiname = _T("");
	m_distant = 0;
	m_alarmtype = 0;
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CCableAlarmTable::GetDefaultConnect()
{
	return _T("ODBC;DSN=remotemonitor");
}

CString CCableAlarmTable::GetDefaultSQL()
{
	return _T("[cabledefault]");
}

void CCableAlarmTable::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCableAlarmTable)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Long(pFX, _T("[cablenumber]"), m_cablenumber);
	RFX_Text(pFX, _T("[fenjiname]"), m_fenjiname);
	RFX_Long(pFX, _T("[distant]"), m_distant);
	RFX_Date(pFX, _T("[alarmtime]"), m_alarmtime);
	RFX_Date(pFX, _T("[recovertime]"), m_recovertime);
	RFX_Byte(pFX, _T("[alarmtype]"), m_alarmtype);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCableAlarmTable diagnostics

#ifdef _DEBUG
void CCableAlarmTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCableAlarmTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
