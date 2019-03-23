// PenProperties.cpp : implementation file
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "remotemonitordoc.h"
#include "remotemonitorView.h"




#include "PenProperties.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPenProperties dialog


CPenProperties::CPenProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CPenProperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPenProperties)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pParent=( CRemotemonitorView *)pParent;
}


void CPenProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPenProperties)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPenProperties, CDialog)
	//{{AFX_MSG_MAP(CPenProperties)
	ON_CBN_SELCHANGE(IDC_PENCOLORCOMBO, OnSelchangePencolorcombo)
	ON_CBN_SELCHANGE(IDC_PENWIDTHCOMBO, OnSelchangePenwidthcombo)
	ON_CBN_SELCHANGE(IDC_BRUSHSTYLECOMBO, OnSelchangeBrushstylecombo)
	ON_WM_CLOSE()
	ON_CBN_SELCHANGE(IDC_TEXTCOLOR, OnSelchangeTextcolor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPenProperties message handlers

BOOL CPenProperties::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rc;
	m_pParent->GetClientRect(&rc);
    m_pParent->ClientToScreen(&rc);

	WINDOWPLACEMENT wp;
	GetWindowPlacement(&wp);
	int width,height;
    width=wp.rcNormalPosition.right-wp.rcNormalPosition.left;
    height=wp.rcNormalPosition.bottom-wp.rcNormalPosition.top;
    wp.rcNormalPosition.left=rc.right-width;
    wp.rcNormalPosition.right=wp.rcNormalPosition.left+width;
    wp.rcNormalPosition.top=rc.top;
    wp.rcNormalPosition.bottom=wp.rcNormalPosition.top+height;
	SetWindowPlacement(&wp);
	m_ColorComboBox.SubclassDlgItem(IDC_PENCOLORCOMBO,this);
    m_ColorComboBox.InitializeData();
    m_ColorComboBox.SetCurSel(10);
	m_pParent->m_nCurrentPenColor=m_ColorComboBox.GetSelectedColor();
	m_FillColorComboBox.SubclassDlgItem(IDC_BRUSHSTYLECOMBO,this);
    m_FillColorComboBox.InitializeData();
    m_FillColorComboBox.SetCurSel(12);
	m_pParent->m_nCurrentFillColor=m_FillColorComboBox.GetSelectedColor();

	m_TextColorComboBox.SubclassDlgItem(IDC_TEXTCOLOR,this);
    m_TextColorComboBox.InitializeData();
    m_TextColorComboBox.SetCurSel(13);
	m_pParent->m_nTextColor=m_TextColorComboBox.GetSelectedColor();

	m_LineWidthComboBox.SubclassDlgItem(IDC_PENWIDTHCOMBO,this);
    m_LineWidthComboBox.SetLineColor(m_ColorComboBox.GetSelectedColor());
    m_LineWidthComboBox.InitializeData();
    m_LineWidthComboBox.SetCurSel(0);
	m_pParent->m_nCurrentPenWidth=m_LineWidthComboBox.GetSelectedWidth();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPenProperties::OnSelchangePencolorcombo() 
{
	// TODO: Add your control notification handler code here
	m_pParent->ChangePenColor(m_ColorComboBox.GetSelectedColor());
    m_LineWidthComboBox.SetLineColor(m_ColorComboBox.GetSelectedColor());
    m_LineWidthComboBox.Invalidate(TRUE);
}
void CPenProperties::OnSelchangeTextcolor() 
{
	// TODO: Add your control notification handler code here
	m_pParent->ChangeTextColor(m_TextColorComboBox.GetSelectedColor());
}

void CPenProperties::OnSelchangePenwidthcombo() 
{
	// TODO: Add your control notification handler code here
	m_pParent->ChangePenWidth(m_LineWidthComboBox.GetSelectedWidth());
	
}

void CPenProperties::OnSelchangeBrushstylecombo() 
{
	// TODO: Add your control notification handler code here
	m_pParent->ChangeFillColor(m_FillColorComboBox.GetSelectedColor());
	
}

void CPenProperties::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
    delete this;		
//	CDialog::PostNcDestroy();
}

void CPenProperties::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	m_pParent->m_pPenProperties=NULL;
	DestroyWindow();
	
//	CDialog::OnClose();
}

