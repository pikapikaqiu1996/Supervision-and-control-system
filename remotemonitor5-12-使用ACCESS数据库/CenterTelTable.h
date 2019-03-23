#if !defined(AFX_CENTERTELTABLE_H__25C8426B_18A4_4DE5_8029_8B101E345B6D__INCLUDED_)
#define AFX_CENTERTELTABLE_H__25C8426B_18A4_4DE5_8029_8B101E345B6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CenterTelTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCenterTelTable recordset

class CCenterTelTable : public CRecordset
{
public:
	CCenterTelTable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCenterTelTable)

// Field/Param Data
	//{{AFX_FIELD(CCenterTelTable, CRecordset)
	long	m_Id;
	CString	m_telephone;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCenterTelTable)
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

#endif // !defined(AFX_CENTERTELTABLE_H__25C8426B_18A4_4DE5_8029_8B101E345B6D__INCLUDED_)
