#pragma once
#include "adodc1.h"
#include "afxwin.h"


// CCHUFAshuru �Ի���

class CCHUFAshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CCHUFAshuru)

public:
	CCHUFAshuru(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCHUFAshuru();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CAdodc1 m_chufaadodc;
//	CEdit m_chufadengji;
//	CEdit m_chufaid;
//	CEdit m_chufashijian;
	CString m_chufadengji;
	CString m_chufaid;
	CString m_chufashijian;
	CString m_chufastuid;
	CString m_chufazhuangtai;
	CString m_chufamiaoshu;
	afx_msg void OnBnClickedchufacharuButton1();
};
