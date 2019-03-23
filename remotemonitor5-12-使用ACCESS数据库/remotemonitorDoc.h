// remotemonitorDoc.h : interface of the CRemotemonitorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REMOTEMONITORDOC_H__CE2D88EA_5E14_444D_821B_14C3FE1C34F1__INCLUDED_)
#define AFX_REMOTEMONITORDOC_H__CE2D88EA_5E14_444D_821B_14C3FE1C34F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDrawObject;

class CRemotemonitorDoc : public CDocument
{
protected: // create from serialization only
	CRemotemonitorDoc();
	DECLARE_DYNCREATE(CRemotemonitorDoc)

// Attributes
public:
	CTypedPtrArray<CObArray, CDrawObject*> m_aObjects;
	void DrawObjects(CDC* pDC);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemotemonitorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRemotemonitorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRemotemonitorDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString ReadTitleFromIni();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMOTEMONITORDOC_H__CE2D88EA_5E14_444D_821B_14C3FE1C34F1__INCLUDED_)
