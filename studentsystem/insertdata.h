#pragma once
#include "adodc1.h"


// insertdata �Ի���

class insertdata : public CDialogEx
{
	DECLARE_DYNAMIC(insertdata)

public:
	insertdata(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~insertdata();

// �Ի�������
	enum { IDD = IDD_stufilecharu_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_edit_banji;
	CString m_edit_jiguan;
	CString m_edit_name;
	CString m_edit_shengri;
	CString m_edit_xingbie;
	CString m_edit_xuehao;
	CString m_edit_zhuanye;
	afx_msg void OnClickedCharuButton1();
	CAdodc1 m_charuadodc;
	CString m_edit_waihao;
};
