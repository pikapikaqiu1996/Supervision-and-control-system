// ComboColorPicker.cpp : implementation file
//

#include "stdafx.h"
#include "ComboColorPicker.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboColorPicker
COLORREF CComboColorPicker::m_rgStandardColors[]={
	RGB(0,0,0),//Black;
	RGB(255,255,255),//White;
	RGB(128,0,0),//Dark Red;
	RGB(0,128,0),//Dark Green;
	RGB(128,128,0),//Dark Yellow;
	RGB(0,0,128),//Dark Blue;
	RGB(128,0,128),//Dark Magenta;
	RGB(0,128,128),//Dark Cyan;
	RGB(192,192,192),//Dark Grey;
	RGB(128,128,128),//Dark Grey;
	RGB(255,0,0),//Red;
	RGB(0,255,0),//Green;
	RGB(255,255,0),//Yellow;
	RGB(0,0,255),//Blue;
	RGB(255,0,255),//Magenta;
	RGB(0,255,255),//Cyan;
};

CComboColorPicker::CComboColorPicker()
{
	m_bInitialized=FALSE;
}

CComboColorPicker::~CComboColorPicker()
{
}


BEGIN_MESSAGE_MAP(CComboColorPicker, CComboBox)
	//{{AFX_MSG_MAP(CComboColorPicker)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboColorPicker message handlers

int CComboColorPicker::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	InitializeData();
	return 0;
}


void CComboColorPicker::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	InitializeData();
	CComboBox::PreSubclassWindow();
	SetCurSel( 0 );											// Select First Item By Default

}

void CComboColorPicker::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CDC dc;
	CBrush brushBlack;
    brushBlack.CreateStockObject(BLACK_BRUSH);
	if(!dc.Attach(lpDrawItemStruct->hDC))
		return;
	COLORREF rgbTextColor=dc.GetTextColor();
	COLORREF rgbBkColor=dc.GetBkColor();

	if(lpDrawItemStruct->itemAction&ODA_FOCUS)
	{
		dc.DrawFocusRect(&lpDrawItemStruct->rcItem);
	}
	else if(lpDrawItemStruct->itemAction&ODA_DRAWENTIRE)
	{
		if(lpDrawItemStruct->itemState&ODS_FOCUS)
			dc.DrawFocusRect(&lpDrawItemStruct->rcItem);
		else
			dc.ExtTextOut(0,0,ETO_OPAQUE,&lpDrawItemStruct->rcItem,_T(""),0,NULL);
	}
	if(0<=(int)lpDrawItemStruct->itemID)
	{
		::InflateRect(&lpDrawItemStruct->rcItem,-2,-2);
		dc.FillSolidRect(&lpDrawItemStruct->rcItem,(COLORREF)lpDrawItemStruct->itemData);
		dc.FrameRect(&lpDrawItemStruct->rcItem,&brushBlack);
	}
	dc.SetTextColor(rgbTextColor);
	dc.SetBkColor(rgbBkColor);
	dc.Detach();
}
void CComboColorPicker::InitializeData()
{
	int nItem;
	if(m_bInitialized)
		return;
	for(int nColor=0;nColor<sizeof(m_rgStandardColors)/sizeof(COLORREF);nColor++)
	{
		nItem=AddString("");
		if(CB_ERRSPACE==nItem) break;
		else												// If Added Successfully
			SetItemData(nItem, m_rgStandardColors[nColor] );					// Set Color RGB Value
	}
    m_bInitialized=TRUE;
}
COLORREF CComboColorPicker::GetSelectedColor()
{
	int nItem=GetCurSel();
	if(CB_ERR==nItem)
		return RGB(0,0,0);
	return m_rgStandardColors[nItem];
}


