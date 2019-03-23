#if !defined(AFX_PENPROPERTIES_H__9DF4A8F3_39C2_475D_B83D_11D7F08C2411__INCLUDED_)
#define AFX_PENPROPERTIES_H__9DF4A8F3_39C2_475D_B83D_11D7F08C2411__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PenProperties.h : header file
//
#include "ComboColorPicker.h"
#include "LinePicker.h"

/////////////////////////////////////////////////////////////////////////////
// CPenProperties dialog
class CRemotemonitorView;
class CPenProperties : public CDialog
{
// Construction
public:
	CPenProperties(CWnd* pParent = NULL);   // standard constructor
    CRemotemonitorView* m_pParent;
	CComboColorPicker m_ColorComboBox;
	CComboColorPicker m_FillColorComboBox;
	CComboColorPicker m_TextColorComboBox;
	CLinePicker       m_LineWidthComboBox;
// Dialog Data
	//{{AFX_DATA(CPenProperties)
	enum { IDD = IDD_PENPROPERTIES };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPenProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPenProperties)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangePencolorcombo();
	afx_msg void OnSelchangePenwidthcombo();
	afx_msg void OnSelchangeBrushstylecombo();
	afx_msg void OnClose();
	afx_msg void OnSelchangeTextcolor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PENPROPERTIES_H__9DF4A8F3_39C2_475D_B83D_11D7F08C2411__INCLUDED_)
