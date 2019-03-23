#if !defined(AFX_CABLEINFOTABLE_H__9BD3DEDA_43A4_4227_8D58_ED9F5F8B32FA__INCLUDED_)
#define AFX_CABLEINFOTABLE_H__9BD3DEDA_43A4_4227_8D58_ED9F5F8B32FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CableInfoTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCableInfoTable recordset

class CCableInfoTable : public CRecordset
{
public:
	CCableInfoTable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCableInfoTable)

// Field/Param Data
	//{{AFX_FIELD(CCableInfoTable, CRecordset)
	long	m_Id;
	CString	m_startname;
	CString	m_endname;
	BYTE	m_state;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCableInfoTable)
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

#endif // !defined(AFX_CABLEINFOTABLE_H__9BD3DEDA_43A4_4227_8D58_ED9F5F8B32FA__INCLUDED_)
