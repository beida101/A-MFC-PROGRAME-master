
// studentsystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CstudentsystemApp:
// �йش����ʵ�֣������ studentsystem.cpp
//

class CstudentsystemApp : public CWinApp
{
public:
	CstudentsystemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CstudentsystemApp theApp;