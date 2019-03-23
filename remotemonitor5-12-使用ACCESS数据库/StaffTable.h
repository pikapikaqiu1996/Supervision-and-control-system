#if !defined(AFX_STAFFTABLE_H__8519F9DF_7388_45D3_B021_DCF5C317CB79__INCLUDED_)
#define AFX_STAFFTABLE_H__8519F9DF_7388_45D3_B021_DCF5C317CB79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StaffTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStaffTable recordset

class CStaffTable : public CRecordset
{
public:
	CStaffTable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStaffTable)

// Field/Param Data
	//{{AFX_FIELD(CStaffTable, CRecordset)
	long	m_Id;
	CString	m_Name;
	CString	m_Password;
	BOOL	m_RightA;
	BOOL	m_RightB;
	BOOL	m_RightC;
	BOOL	m_RightD;
	CString	m_Duty;
	CString	m_Telephone;
	CString	m_Department;
	CString	m_Address;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaffTable)
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

#endif // !defined(AFX_STAFFTABLE_H__8519F9DF_7388_45D3_B021_DCF5C317CB79__INCLUDED_)
