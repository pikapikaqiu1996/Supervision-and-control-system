#if !defined(AFX_FENJITABLE_H__1AB5D027_8B18_4338_BD61_5C0C9533D2D6__INCLUDED_)
#define AFX_FENJITABLE_H__1AB5D027_8B18_4338_BD61_5C0C9533D2D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FenjiTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFenjiTable recordset

class CFenjiTable : public CRecordset
{
public:
	CFenjiTable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFenjiTable)

// Field/Param Data
	//{{AFX_FIELD(CFenjiTable, CRecordset)
	long	m_Id;
	CString	m_Name;
	CString	m_telephone;
/*	CString	m_username1;
	CString	m_usertel1;
	CString	m_username2;
	CString	m_usertel2;
	CString	m_username3;
	CString	m_usertel3;
	CString	m_username4;
	CString	m_usertel4;
	CString	m_username5;
	CString	m_usertel5;
	CString	m_username6;
	CString	m_usertel6;
*/
	CString	m_username[6];
	CString	m_usertel[6];

/*	CString	m_maintenance1;
	CString	m_maintenancetel1;
	CString	m_maintenance2;
	CString	m_maintenancetel2;
	CString	m_maintenance3;
	CString	m_maintenancetel3;
	CString	m_maintenance4;
	CString	m_maintenancetel4;
	CString	m_maintenance5;
	CString	m_maintenancetel5;
	CString	m_maintenance6;
	CString	m_maintenancetel6;
*/
	CString	m_maintenance[6];
	CString	m_maintenancetel[6];
	BYTE	m_ackwaittime;
	BYTE	m_sensitive;
	BYTE	m_callnumber;
	BYTE	m_waittime;
	float	m_xudianchi;
	BYTE	m_mode;
	BYTE	m_zejuxisu;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFenjiTable)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FENJITABLE_H__1AB5D027_8B18_4338_BD61_5C0C9533D2D6__INCLUDED_)
