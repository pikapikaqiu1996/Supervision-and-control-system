// remotemonitorDoc.cpp : implementation of the CRemotemonitorDoc class
//

#include "stdafx.h"
#include "remotemonitor.h"

#include "remotemonitorDoc.h"
#include "Draw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRemotemonitorDoc

IMPLEMENT_DYNCREATE(CRemotemonitorDoc, CDocument)

BEGIN_MESSAGE_MAP(CRemotemonitorDoc, CDocument)
	//{{AFX_MSG_MAP(CRemotemonitorDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemotemonitorDoc construction/destruction

CRemotemonitorDoc::CRemotemonitorDoc()
{
	// TODO: add one-time construction code here
	int i;

	for(i=m_aObjects.GetSize()-1; i>=0; i--)
	{
		delete m_aObjects[i];
	}
	m_aObjects.RemoveAll();

}

CRemotemonitorDoc::~CRemotemonitorDoc()
{
	int i;

	for(i=m_aObjects.GetSize()-1; i>=0; i--)
	{
		delete m_aObjects[i];
	}
	m_aObjects.RemoveAll();

}
void CRemotemonitorDoc::DrawObjects(CDC* pDC)
{
	int i = m_aObjects.GetSize();
	int j;

	for(j=0; j<i; j++)
	{
		CDrawObject* pObject = m_aObjects[j];
		if(pObject!=NULL)
		{
			pObject->Draw(pDC);
			if(pObject->m_bSelected)
			{//以前已经选择了，设置热点
				pObject->HotPoints(pDC);
			}
		}
	}
}

BOOL CRemotemonitorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

//	CString strTitle=ReadTitleFromIni();
   // SetTitle(strTitle);
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRemotemonitorDoc serialization

void CRemotemonitorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		m_aObjects.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		m_aObjects.Serialize(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRemotemonitorDoc diagnostics

#ifdef _DEBUG
void CRemotemonitorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRemotemonitorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRemotemonitorDoc commands
CString CRemotemonitorDoc::ReadTitleFromIni()
{
	char path_buffer[_MAX_PATH];
	char path_ini[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	CString strIniName;

	GetModuleFileName( NULL, path_buffer, _MAX_PATH );
	_splitpath( path_buffer, drive, dir, fname, ext );	
	_makepath(  path_ini, drive, dir, fname, "ini" );
    strIniName = path_ini;

	CString strTitle;
	GetPrivateProfileString("TITLE", "TITLE0","", strTitle.GetBuffer(80), 80,strIniName);
	strTitle.ReleaseBuffer();
	strTitle.TrimLeft();
	strTitle.TrimRight();
	return strTitle;
}


void CRemotemonitorDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	int i;

	for(i=m_aObjects.GetSize()-1; i>=0; i--)
	{
		delete m_aObjects[i];
	}
//	m_usrCurrentObject = NULL;
	m_aObjects.RemoveAll();//删除图元
//	Invalidate();//刷新视图
	
	CDocument::DeleteContents();
}
