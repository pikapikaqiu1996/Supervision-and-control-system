// LinePicker.cpp : implementation file
//

#include "stdafx.h"
#include "LinePicker.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinePicker
DWORD CLinePicker::m_lineWidth[]={
	1,
	2,
	3,//Dark Red;
	4,//Dark Green;
	5,//Dark Yellow;
};
CLinePicker::CLinePicker()
{
	m_bInitialized=FALSE;
    m_nColor=RGB(0,0,0);
}

CLinePicker::~CLinePicker()
{
}


BEGIN_MESSAGE_MAP(CLinePicker, CComboBox)
	//{{AFX_MSG_MAP(CLinePicker)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinePicker message handlers

int CLinePicker::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	InitializeData();

	return 0;
}

void CLinePicker::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
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
   //     CRect rect;
//		rect.left=lpDrawItemStruct->rcItem.left;
//		rect.right=lpDrawItemStruct->rcItem.right;
//		rect.top=lpDrawItemStruct->rcItem.top;
	//	CPen newPen(PS_SOLID,lpDrawItemStruct->itemData,RGB(0,0,0));
	//	CPen* pOldPen=dc.SelectObject(&newPen);
	//	dc.MoveTo(lpDrawItemStruct->rcItem.left,lpDrawItemStruct->rcItem.top+(lpDrawItemStruct->rcItem.bottom-lpDrawItemStruct->rcItem.top)/2);
	//	dc.LineTo(lpDrawItemStruct->rcItem.right,lpDrawItemStruct->rcItem.top+(lpDrawItemStruct->rcItem.bottom-lpDrawItemStruct->rcItem.top)/2);
        RECT rc;
        rc.left=lpDrawItemStruct->rcItem.left;
        rc.right=lpDrawItemStruct->rcItem.right;
		rc.top=lpDrawItemStruct->rcItem.top+(lpDrawItemStruct->rcItem.bottom-lpDrawItemStruct->rcItem.top)/2-lpDrawItemStruct->itemData/2;
		rc.bottom=rc.top+lpDrawItemStruct->itemData;
		dc.FillSolidRect(&rc,m_nColor/*(COLORREF)lpDrawItemStruct->itemData*/);
		//	dc.FillSolidRect(&lpDrawItemStruct->rcItem,brushBlack/*(COLORREF)lpDrawItemStruct->itemData*/);
	//	dc.FrameRect(&lpDrawItemStruct->rcItem,&brushBlack);
	//	dc.SelectObject(pOldPen);

	}
	dc.SetTextColor(rgbTextColor);
	dc.SetBkColor(rgbBkColor);
	dc.Detach();	
}

void CLinePicker::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	InitializeData();
	CComboBox::PreSubclassWindow();
	SetCurSel( 0 );											// Select First Item By Default
	
}
void CLinePicker::InitializeData()
{
	int nItem;
	if(m_bInitialized)
		return;
	for(int nWidth=0;nWidth<sizeof(m_lineWidth)/sizeof(int);nWidth++)
	{
		nItem=AddString("");
		if(CB_ERRSPACE==nItem) break;
		else												// If Added Successfully
			SetItemData(nItem, m_lineWidth[nWidth] );					// Set Color RGB Value
	}
    m_bInitialized=TRUE;
}
void CLinePicker::SetLineColor(COLORREF nColor)
{
   m_nColor=nColor;
}
int CLinePicker::GetSelectedWidth()
{
	int nItem=GetCurSel();
	if(CB_ERR==nItem)
		return 1;
	return m_lineWidth[nItem];
}