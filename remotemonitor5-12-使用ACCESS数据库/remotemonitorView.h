// remotemonitorView.h : interface of the CRemotemonitorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REMOTEMONITORVIEW_H__82B2E32B_CB4C_4157_A95C_847EDAB6B8E0__INCLUDED_)
#define AFX_REMOTEMONITORVIEW_H__82B2E32B_CB4C_4157_A95C_847EDAB6B8E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PenProperties.h"
#include "Draw.h"
#include "CableInfoTable.h" 
#include "FenjiTable.h"     
#include "CableAlarmTable.h" 

//链路层状态
#define SYN 0x16
#define DLE 0x10
#define STX 0x02
#define ETX 0x03

#pragma pack(1)
typedef struct tagPKSTART
{
	char syn;
	char dle;
	char stx;
}PKSTART;
typedef struct tagHEADER
{
	char pktype;
	char para;
}HEADER;
typedef struct tagPKEND
{
	char dle;
	char etx;
}PKEND;
#pragma pack()

//链路层状态
#define IDLE    		        (0x01)
#define READY			        (0x02)

#define REVTIMER     	(0x01)
#define SNDTIMER     	(0x02)
#define FLASHTIMER      (0x03)
#define PROBETIMER      (0x04)
#define DISPLAYTIME     (0x05)
#define RESENDTIME      (0x06)
#define m_RevT          200
#define m_SendT         3000
#define m_FlashT   		500
#define m_ProbeT   		60000
#define m_DisplayT 		1000
#define m_ReSendT 		10000
/*enum ToolConstants
{
	ArrowTool = 0,
	PanTool = 1,
	ZoomInTool = 2,
	ZoomOutTool = 3,
};*/
class CRemotemonitorView : public CScrollView
{
protected: // create from serialization only
	CRemotemonitorView();
	DECLARE_DYNCREATE(CRemotemonitorView)

// Attributes
public:
	CRemotemonitorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemotemonitorView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	//为串口通信用
    UINT m_uRevTimer;
	UINT m_uSendTimer;
	UINT m_uFlashTimer;
	UINT m_uProbeTimer;
	UINT m_uDisplayTimer;
	UINT m_uReSendTimer;
	int  m_nLinkState;//当前链路状态IDLE,READY三种状态之一
	BOOL m_bHasAck;
    BOOL m_bBusy;
	CStringArray m_strArray;//存放要发出的信息
    PKSTART m_pkstart;
    PKEND   m_pkend;
    HEADER  m_header;
	void Process();
	void ProcessRevInfo(CString strRevInfo);
	void SetAlarmFlag(CString strNodeNum,CString strCableNum="00");
	unsigned char crc(BYTE* buffer,int Len);
	int InsertDLE(BYTE* buffer0,BYTE* buffer1,int len);
	int DeleteDLE(int nStart,int nEnd);
	BOOL SeekFrameHead(int &start);
	BOOL SeekFrameEnd(int start,int &end);
	void SendLR();
	void SendLA(int nflag);
	void SendLT();
	bool m_bAlarm;
    int m_nCounter;
	CString m_strMapPathName;
	BOOL m_bMouseDown;
    CPoint m_LastPt;
    CPenProperties* m_pPenProperties;
//	CDC m_memoryDC;
//	CBitmap m_bitmap;
//	CBitmap* m_pOldBitmap;
    BITMAP m_bmInfo;
    int m_nCurTool;
	HBITMAP m_hBitmap;
    HBITMAP m_hOldBitmap;
	HDC     m_hMemoryDC;
	HDC     m_hMemoryDC0;
	HDC     m_hMemoryDC1;
    CDrawObject* m_usrCurrentObject;
	COLORREF m_nCurrentPenColor;//图元笔颜色
	int      m_nCurrentPenWidth;
	COLORREF m_nCurrentFillColor;
	COLORREF m_nTextColor;
    int m_nMoveMode;//图元移动方式
	void ReadCfgFromIni();
	void WriteCfgToIni();
	void Viewpenproperties(BOOL bShow);
	void initMemoryDC();
	void ChangePenColor(COLORREF nColor);
    void ChangePenWidth(int nWidth);
	void ChangeFillColor(COLORREF nColor);
	void ChangeTextColor(COLORREF nColor);
    void flash();
    void InsertListItem(CString strNodeNum,
		                CString strFenjiName,
						CString strCableNum,
						CString strNodeName,
						CString strTroubleType,
						CString strDistance,
						CString strAlarmTime,
						CString strMaintenance[],
						CString strTelephone[]);
    void maptoDTMF(unsigned char* pbuff,int len);
    void maptoASC(unsigned char* pbuff,int len);
    void ChangetoArrow();
	CCableInfoTable m_cabletable;
    CFenjiTable     m_fenjitable;
    CCableAlarmTable m_cablealarmtable;


	virtual ~CRemotemonitorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRemotemonitorView)
	afx_msg void OnZoomin();
	afx_msg void OnZoomout();
	afx_msg void OnPan();
	afx_msg void OnUpdateZoomin(CCmdUI* pCmdUI);
	afx_msg void OnUpdateZoomout(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePan(CCmdUI* pCmdUI);
	afx_msg void OnArrow();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMapchange();
	afx_msg void OnDrawline();
	afx_msg void OnDrawcircle();
	afx_msg void OnUpdateDrawline(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawcircle(CCmdUI* pCmdUI);
	afx_msg void OnSelect();
	afx_msg void OnUpdateSelect(CCmdUI* pCmdUI);
	afx_msg void OnDelete();
	afx_msg void OnUpdateDelete(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSendaa();
	afx_msg void OnSendab();
	afx_msg void OnSendca();
	afx_msg void OnSendcc();
	afx_msg void OnSendcd();
	afx_msg void OnSendda();
	afx_msg void OnDeletelistitem();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnClearalarm();
	afx_msg void OnDutyrecord();
	afx_msg void OnJiaoban();
	afx_msg void OnFenjicableset();
	afx_msg void OnUserset();
	afx_msg void OnViewdutyrecord();
	afx_msg void OnViewfenjicableinfo();
	afx_msg void OnViewcablealarminfo();
	afx_msg void OnUpdateUserset(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFenjicableset(CCmdUI* pCmdUI);
	afx_msg void OnSenddc();
	afx_msg void OnSendcb();
	afx_msg void OnSetcentertel();
	afx_msg void OnUpdateClearalarm(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in remotemonitorView.cpp
inline CRemotemonitorDoc* CRemotemonitorView::GetDocument()
   { return (CRemotemonitorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMOTEMONITORVIEW_H__82B2E32B_CB4C_4157_A95C_847EDAB6B8E0__INCLUDED_)
