#pragma once
#include "adodc1.h"


// Cduobiao �Ի���

class Cduobiao : public CDialogEx
{
	DECLARE_DYNAMIC(Cduobiao)

public:
	Cduobiao(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cduobiao();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_duobiaobanji;
	CString m_duobiaoxingming;
	CAdodc1 m_duobiaoadodc1;
	afx_msg void OnBnClickedxingmingRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedchaxunButton1();
};
