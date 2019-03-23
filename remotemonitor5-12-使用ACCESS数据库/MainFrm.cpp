// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "remotemonitor.h"
#include "remotemonitordoc.h"
#include "remotemonitorView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame
extern int   m_nScale;
extern BOOL bRight[];	// 操作权限
static _TCHAR* g_szListLabel[] =
{ 
	_T("分机号"),
	_T("分机名"),
	_T("电缆号"),
	_T("节点名"),
	_T("故障类别"),
	_T("距  离"),
	_T("报警时间"),
	_T("维护人员1"),
	_T("电 话 1"),
	_T("维护人员2"),
	_T("电 话 2"),
	_T("维护人员3"),
	_T("电 话 3"),
	_T("维护人员4"),
	_T("电 话 4"),
	_T("维护人员5"),
	_T("电 话 5"),
	_T("维护人员6"),
	_T("电 话 6"),
};

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_DRAW, OnDraw)
	ON_UPDATE_COMMAND_UI(ID_DRAW, OnUpdateDraw)
	ON_COMMAND(ID_VIEW_LISTBAR, OnViewListbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LISTBAR, OnUpdateViewListbar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_LINKSTATE,
	ID_CURRENTTIME,
//	ID_INDICATOR_CAPS,
///	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bFlag=0;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	OnViewShort();
/*//在工具栏上加静态文本框
	CRect rect;
    m_wndToolBar.SetButtonInfo(4,ID_SCALESTATIC,TBBS_SEPARATOR,160);
	m_wndToolBar.GetItemRect(4,&rect);
//	rect.bottom+=50;
	if(!m_scalestatic.Create("缩放比例:100%",WS_VISIBLE|WS_TABSTOP|WS_BORDER|SS_CENTER,rect,&m_wndToolBar,IDC_MYSTATIC))
		return -1;
    m_scalestatic.ModifyStyleEx(0,WS_EX_STATICEDGE);
*/
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	//给新的窗格设置宽度、风格等
    m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(ID_LINKSTATE),ID_LINKSTATE,SBPS_NORMAL,100);
    m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(ID_CURRENTTIME),ID_CURRENTTIME,SBPS_NORMAL,120);
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


    if (!m_wndMyBar.Create(_T("监控数据"),  this,CSize(200,90),TRUE,124))
	{
		TRACE0("Failed to create mybar\n");
		return -1;
	}
	m_wndMyBar.SetBarStyle(m_wndMyBar.GetBarStyle() |
			CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	m_wndMyBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndMyBar, AFX_IDW_DOCKBAR_BOTTOM);
	ShowControlBar(&m_wndMyBar, FALSE, FALSE);

	//InitListBar
	m_wndList.Create(WS_CHILD|WS_VISIBLE|LVS_REPORT|LVS_ALIGNTOP|
			LVS_SINGLESEL|LVS_SHOWSELALWAYS,CRect(0,0,0,0),&m_wndMyBar,IDC_LISTCAR);
	m_wndList.ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	m_wndList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES/*|LVS_EX_TRACKSELECT*/);
	CString str;
//	str = g_szListLabel[0];
//	m_wndList.InsertColumn( 0, str, LVCFMT_CENTER,
//	m_wndList.GetStringWidth( str )*3, 0 );

	for(int i=0;i<19;i++)
	{
		str = g_szListLabel[i];
		m_wndList.InsertColumn( i, str, LVCFMT_CENTER,
		m_wndList.GetStringWidth( str )*3/2, i );
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    cs.style&=~FWS_PREFIXTITLE;
	cs.style&=~FWS_ADDTOTITLE;   
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnViewShort()
{
	// Set the toolbar to show only partial commmand list
	m_wndToolBar.SetButtons(NULL, 13);
	m_wndToolBar.SetButtonInfo(0, ID_FILE_NEW,TBBS_BUTTON, 0);
	m_wndToolBar.SetButtonInfo(1, ID_FILE_OPEN,TBBS_BUTTON, 1);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_SAVE,TBBS_BUTTON, 2);
	m_wndToolBar.SetButtonInfo(3, ID_SEPARATOR,TBBS_SEPARATOR, 6);

	m_wndToolBar.SetButtonInfo(4, ID_ARROW,TBBS_BUTTON, 3);
	m_wndToolBar.SetButtonInfo(5, ID_MAPCHANGE,TBBS_BUTTON, 4);
	m_wndToolBar.SetButtonInfo(6, ID_ZOOMIN,TBBS_BUTTON, 5);
	m_wndToolBar.SetButtonInfo(7, ID_ZOOMOUT,TBBS_BUTTON, 6);
	m_wndToolBar.SetButtonInfo(8, ID_PAN,TBBS_BUTTON, 7);
	m_wndToolBar.SetButtonInfo(9, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(10, ID_SCALESTATIC,TBBS_SEPARATOR, 160);
	m_wndToolBar.SetButtonInfo(11, ID_SEPARATOR,TBBS_SEPARATOR, 6);

	m_wndToolBar.SetButtonInfo(12, ID_APP_ABOUT,TBBS_BUTTON, 12);

	// invalidate the call update handlers before painting
//在工具栏上加静态文本框
	CRect rect;
//    m_wndToolBar.SetButtonInfo(4,ID_SCALESTATIC,TBBS_SEPARATOR,160);
	m_wndToolBar.GetItemRect(10,&rect);
//	rect.bottom+=50;
	CString str;
	str.Format("缩放比例:%d",m_nScale);
	str+="%";
	m_scalestatic.DestroyWindow();

	if(!m_scalestatic.Create(str,WS_VISIBLE|WS_TABSTOP|WS_BORDER|SS_CENTER,rect,&m_wndToolBar,IDC_MYSTATIC))
		return;
    m_scalestatic.ModifyStyleEx(0,WS_EX_STATICEDGE);
		OnBarCheck(FALSE);

	RecalcLayout();

//	m_wndToolBar.Invalidate();
//	AfxGetApp()->OnIdle(-1);
}



void CMainFrame::OnViewLong()
{
	// Set the toolbar to show all commmands
	m_wndToolBar.SetButtons(NULL, 18);
	m_wndToolBar.SetButtonInfo(0, ID_FILE_NEW,TBBS_BUTTON, 0);
	m_wndToolBar.SetButtonInfo(1, ID_FILE_OPEN,TBBS_BUTTON, 1);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_SAVE,TBBS_BUTTON, 2);
	m_wndToolBar.SetButtonInfo(3, ID_SEPARATOR,TBBS_SEPARATOR, 6);

	m_wndToolBar.SetButtonInfo(4, ID_ARROW,TBBS_BUTTON, 3);
	m_wndToolBar.SetButtonInfo(5, ID_MAPCHANGE,TBBS_BUTTON, 4);
	m_wndToolBar.SetButtonInfo(6, ID_ZOOMIN,TBBS_BUTTON, 5);
	m_wndToolBar.SetButtonInfo(7, ID_ZOOMOUT,TBBS_BUTTON, 6);
	m_wndToolBar.SetButtonInfo(8, ID_PAN,TBBS_BUTTON, 7);
	m_wndToolBar.SetButtonInfo(9, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(10, ID_SCALESTATIC,TBBS_SEPARATOR, 160);
	m_wndToolBar.SetButtonInfo(11, ID_SEPARATOR,TBBS_SEPARATOR, 6);

	m_wndToolBar.SetButtonInfo(12, ID_SELECT,TBBS_BUTTON, 8);
	m_wndToolBar.SetButtonInfo(13, ID_DELETE,TBBS_BUTTON, 9);
	m_wndToolBar.SetButtonInfo(14, ID_DRAWLINE,TBBS_BUTTON, 10);
	m_wndToolBar.SetButtonInfo(15, ID_DRAWCIRCLE,TBBS_BUTTON, 11);
	m_wndToolBar.SetButtonInfo(16, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(17, ID_APP_ABOUT,TBBS_BUTTON, 12);

	// invalidate then call update handlers before painting
//在工具栏上加静态文本框
	CRect rect;
//    m_wndToolBar.SetButtonInfo(4,ID_SCALESTATIC,TBBS_SEPARATOR,160);
	m_wndToolBar.GetItemRect(10,&rect);
//	rect.bottom+=50;
	CString str;
	str.Format("缩放比例:%d",m_nScale);
	str+="%";
	m_scalestatic.DestroyWindow();
	if(!m_scalestatic.Create(str,WS_VISIBLE|WS_TABSTOP|WS_BORDER|SS_CENTER,rect,&m_wndToolBar,IDC_MYSTATIC))
		return;
    m_scalestatic.ModifyStyleEx(0,WS_EX_STATICEDGE);
		OnBarCheck(TRUE);

	RecalcLayout();
}

void CMainFrame::OnDraw() 
{
	// TODO: Add your command handler code here

     CRemotemonitorView *pView = (CRemotemonitorView *)GetActiveView();


	if(!m_bFlag)
	{
		OnViewLong();
        pView->Viewpenproperties(TRUE);
	//	OnBarCheck(TRUE);
        m_bFlag=TRUE;
	}
	else
	{
		OnViewShort();
		pView->Viewpenproperties(FALSE);
		pView->ChangetoArrow();
	//	OnBarCheck(FALSE);

        m_bFlag=FALSE;
	}
}

void CMainFrame::OnUpdateDraw(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->Enable(bRight[2]);
		pCmdUI->SetCheck(m_bFlag);

}

void CMainFrame::OnViewListbar() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_wndMyBar, !m_wndMyBar.IsVisible(), FALSE);
}

void CMainFrame::OnUpdateViewListbar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_wndMyBar.IsVisible());		
}
void CMainFrame::ViewListbar() 
{
	// TODO: Add your command handler code here
	if(!m_wndMyBar.IsVisible())
	ShowControlBar(&m_wndMyBar, TRUE, FALSE);
}
void CMainFrame::ChangeTime() 
{
	// TODO: Add your message handler code here and/or call default
	COleDateTime dt;
	dt=COleDateTime::GetCurrentTime();
	CString str=dt.Format("%Y-%m-%d %H:%M:%S");
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_CURRENTTIME),str);
}
void CMainFrame::ChangeLinkState(int state)
{
	if(state==0)
	  m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_LINKSTATE),"通信链路尚未建立");
	else
	  m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_LINKSTATE),"通信链路已经建立");
}
void CMainFrame::ShowWindowMax()
{
	ShowWindow(SW_SHOWMAXIMIZED);
	UpdateWindow();
}
