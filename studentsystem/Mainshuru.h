#pragma once


// Mainshuru �Ի���

class Mainshuru : public CDialogEx
{
	DECLARE_DYNAMIC(Mainshuru)

public:
	Mainshuru(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mainshuru();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedgerenButton1();
	afx_msg void OnBnClickedxuejiButton2();
	afx_msg void OnBnClickedjiangliButton3();
	afx_msg void OnBnClickedchufaButton4();
	afx_msg void OnBnClickedButton5();
};
