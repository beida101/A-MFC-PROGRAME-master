#pragma once
#include "adodc1.h"


// CCLASSshuru �Ի���

class CCLASSshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CCLASSshuru)

public:
	CCLASSshuru(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCLASSshuru();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CAdodc1 m_banjiadodc;
	CString m_banjibanzhang;
	CString m_banjiid;
	CString m_banjiname;
	afx_msg void OnBnClickedcharuButton1();
};
