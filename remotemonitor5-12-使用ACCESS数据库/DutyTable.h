#if !defined(AFX_DUTYTABLE_H__C0141964_7EAB_485E_BA73_FD3A3A02B55F__INCLUDED_)
#define AFX_DUTYTABLE_H__C0141964_7EAB_485E_BA73_FD3A3A02B55F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DutyTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDutyTable recordset

class CDutyTable : public CRecordset
{
public:
	CDutyTable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDutyTable)

// Field/Param Data
	//{{AFX_FIELD(CDutyTable, CRecordset)
	long	m_Id;
	CString	m_Name;
	CTime	m_dutytime;
	CTime	m_lefttime;
	CString	m_dutyrecord;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDutyTable)
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

#endif // !defined(AFX_DUTYTABLE_H__C0141964_7EAB_485E_BA73_FD3A3A02B55F__INCLUDED_)
