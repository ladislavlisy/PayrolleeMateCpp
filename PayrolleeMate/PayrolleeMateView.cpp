// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// PayrolleeMateView.cpp : implementation of the CPayrolleeMateView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PayrolleeMate.h"
#endif

#include "PayrolleeMateDoc.h"
#include "PayrolleeMateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPayrolleeMateView

IMPLEMENT_DYNCREATE(CPayrolleeMateView, CListView)

BEGIN_MESSAGE_MAP(CPayrolleeMateView, CListView)
	ON_WM_STYLECHANGED()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPayrolleeMateView construction/destruction

CPayrolleeMateView::CPayrolleeMateView()
{
	// TODO: add construction code here

}

CPayrolleeMateView::~CPayrolleeMateView()
{
}

BOOL CPayrolleeMateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

void CPayrolleeMateView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

void CPayrolleeMateView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPayrolleeMateView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPayrolleeMateView diagnostics

#ifdef _DEBUG
void CPayrolleeMateView::AssertValid() const
{
	CListView::AssertValid();
}

void CPayrolleeMateView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CPayrolleeMateDoc* CPayrolleeMateView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPayrolleeMateDoc)));
	return (CPayrolleeMateDoc*)m_pDocument;
}
#endif //_DEBUG


// CPayrolleeMateView message handlers
void CPayrolleeMateView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window	
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);	
}
