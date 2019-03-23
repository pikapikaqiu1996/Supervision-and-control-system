#if !defined(AFX_CABLEALARMTABLE_H__69E8061F_A338_4AA0_A5F5_8F5852D549FF__INCLUDED_)
#define AFX_CABLEALARMTABLE_H__69E8061F_A338_4AA0_A5F5_8F5852D549FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CableAlarmTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCableAlarmTable recordset

class CCableAlarmTable : public CRecordset
{
public:
	CCableAlarmTable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCableAlarmTable)

// Field/Param Data
	//{{AFX_FIELD(CCableAlarmTable, CRecordset)
	long	m_Id;
	long	m_cablenumber;
	CString	m_fenjiname;
	long	m_distant;
	CTime	m_alarmtime;
	CTime	m_recovertime;
	BYTE	m_alarmtype;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCableAlarmTable)
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

#endif // !defined(AFX_CABLEALARMTABLE_H__69E8061F_A338_4AA0_A5F5_8F5852D549FF__INCLUDED_)
