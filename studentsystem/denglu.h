#pragma once


// denglu �Ի���

class denglu : public CDialogEx
{
	DECLARE_DYNAMIC(denglu)

public:
	denglu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~denglu();

// �Ի�������
	enum { IDD = IDD_denglu_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickeddebgluButton3();
	CString m_edit_yonghuming;
	CString m_edit_mima;
};
