// FenjiTable.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "FenjiTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFenjiTable

IMPLEMENT_DYNAMIC(CFenjiTable, CRecordset)

CFenjiTable::CFenjiTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CFenjiTable)
	m_Id = 0;
	m_Name = _T("");
	m_telephone = _T("");
/*	m_username1 = _T("");
	m_usertel1 = _T("");
	m_username2 = _T("");
	m_usertel2 = _T("");
	m_username3 = _T("");
	m_usertel3 = _T("");
	m_username4 = _T("");
	m_usertel4 = _T("");
	m_username5 = _T("");
	m_usertel5 = _T("");
	m_username6 = _T("");
	m_useryel6 = _T("");
	m_maintenance1 = _T("");
	m_maintenancetel1 = _T("");
	m_maintenance2 = _T("");
	m_maintenancetel2 = _T("");
	m_maintenance3 = _T("");
	m_maintenancetel3 = _T("");
	m_maintenance4 = _T("");
	m_maintenancetel4 = _T("");
	m_maintenance5 = _T("");
	m_maintenancetel5 = _T("");
	m_maintenance6 = _T("");
	m_maintenancetel6 = _T("");
	*/
	for(int i=0;i<6;i++)
	{  
       m_username[i]=_T("");
       m_usertel[i]=_T("");
       m_maintenance[i]=_T("");
       m_maintenancetel[i]=_T("");
	}
	m_ackwaittime = 0;
	m_sensitive = 0;
	m_callnumber = 0;
	m_waittime = 0;
	m_xudianchi = 0.0f;
	m_mode = 0;
	m_zejuxisu = 0;
	m_nFields = 34;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CFenjiTable::GetDefaultConnect()
{
	return _T("ODBC;DSN=remotemonitor");
}

CString CFenjiTable::GetDefaultSQL()
{
	return _T("[fenjiinfotable]");
}

void CFenjiTable::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CFenjiTable)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[telephone]"), m_telephone);
/*	RFX_Text(pFX, _T("[username1]"), m_username1);
	RFX_Text(pFX, _T("[usertel1]"), m_usertel1);
	RFX_Text(pFX, _T("[username2]"), m_username2);
	RFX_Text(pFX, _T("[usertel2]"), m_usertel2);
	RFX_Text(pFX, _T("[username3]"), m_username3);
	RFX_Text(pFX, _T("[usertel3]"), m_usertel3);
	RFX_Text(pFX, _T("[username4]"), m_username4);
	RFX_Text(pFX, _T("[usertel4]"), m_usertel4);
	RFX_Text(pFX, _T("[username5]"), m_username5);
	RFX_Text(pFX, _T("[usertel5]"), m_usertel5);
	RFX_Text(pFX, _T("[username6]"), m_username6);
	RFX_Text(pFX, _T("[usertel6]"), m_usertel6);
	RFX_Text(pFX, _T("[maintenance1]"), m_maintenance1);
	RFX_Text(pFX, _T("[maintenancetel1]"), m_maintenancetel1);
	RFX_Text(pFX, _T("[maintenance2]"), m_maintenance2);
	RFX_Text(pFX, _T("[maintenancetel2]"), m_maintenancetel2);
	RFX_Text(pFX, _T("[maintenance3]"), m_maintenance3);
	RFX_Text(pFX, _T("[maintenancetel3]"), m_maintenancetel3);
	RFX_Text(pFX, _T("[maintenance4]"), m_maintenance4);
	RFX_Text(pFX, _T("[maintenancetel4]"), m_maintenancetel4);
	RFX_Text(pFX, _T("[maintenance5]"), m_maintenance5);
	RFX_Text(pFX, _T("[maintenancetel5]"), m_maintenancetel5);
	RFX_Text(pFX, _T("[maintenance6]"), m_maintenance6);
	RFX_Text(pFX, _T("[maintenancetel6]"), m_maintenancetel6);
*/
	RFX_Text(pFX, _T("[username1]"), m_username[0]);
	RFX_Text(pFX, _T("[usertel1]"), m_usertel[0]);
	RFX_Text(pFX, _T("[username2]"), m_username[1]);
	RFX_Text(pFX, _T("[usertel2]"), m_usertel[1]);
	RFX_Text(pFX, _T("[username3]"), m_username[2]);
	RFX_Text(pFX, _T("[usertel3]"), m_usertel[2]);
	RFX_Text(pFX, _T("[username4]"), m_username[3]);
	RFX_Text(pFX, _T("[usertel4]"), m_usertel[3]);
	RFX_Text(pFX, _T("[username5]"), m_username[4]);
	RFX_Text(pFX, _T("[usertel5]"), m_usertel[4]);
	RFX_Text(pFX, _T("[username6]"), m_username[5]);
	RFX_Text(pFX, _T("[usertel6]"), m_usertel[5]);
	RFX_Text(pFX, _T("[maintenance1]"), m_maintenance[0]);
	RFX_Text(pFX, _T("[maintenancetel1]"), m_maintenancetel[0]);
	RFX_Text(pFX, _T("[maintenance2]"), m_maintenance[1]);
	RFX_Text(pFX, _T("[maintenancetel2]"), m_maintenancetel[1]);
	RFX_Text(pFX, _T("[maintenance3]"), m_maintenance[2]);
	RFX_Text(pFX, _T("[maintenancetel3]"), m_maintenancetel[2]);
	RFX_Text(pFX, _T("[maintenance4]"), m_maintenance[3]);
	RFX_Text(pFX, _T("[maintenancetel4]"), m_maintenancetel[3]);
	RFX_Text(pFX, _T("[maintenance5]"), m_maintenance[4]);
	RFX_Text(pFX, _T("[maintenancetel5]"), m_maintenancetel[4]);
	RFX_Text(pFX, _T("[maintenance6]"), m_maintenance[5]);
	RFX_Text(pFX, _T("[maintenancetel6]"), m_maintenancetel[5]);

	RFX_Byte(pFX, _T("[ackwaittime]"), m_ackwaittime);
	RFX_Byte(pFX, _T("[sensitive]"), m_sensitive);
	RFX_Byte(pFX, _T("[callnumber]"), m_callnumber);
	RFX_Byte(pFX, _T("[waittime]"), m_waittime);
	RFX_Single(pFX, _T("[xudianchi]"), m_xudianchi);
	RFX_Byte(pFX, _T("[mode]"), m_mode);
	RFX_Byte(pFX, _T("[zejuxisu]"), m_zejuxisu);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CFenjiTable diagnostics

#ifdef _DEBUG
void CFenjiTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFenjiTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
