#pragma once


// chaDlg �Ի���

class chaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(chaDlg)

public:
	chaDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~chaDlg();

// �Ի�������
	enum { IDD = IDD_chaxunzhu_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedDanbiaoButton2();
//	afx_msg void OnClickedDuobiaoButton1();
	afx_msg void OnBnClickedduobiaoButton1();
};
