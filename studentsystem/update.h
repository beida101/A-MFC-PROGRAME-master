#pragma once
#include "datagrid1.h"
#include "adodc1.h"
#include "afxwin.h"


// update �Ի���

class update : public CDialogEx
{
	DECLARE_DYNAMIC(update)

public:
	update(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~update();

// �Ի�������
	enum { IDD = IDD_xiugai_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	void OnClickUpdateDatagrid1();
	CDatagrid1 m_datagrid;
//	CAdodc1 m_adodc1;
//	CString m_nianling;
	CString m_xingbie;
//	CEdit m_xingming;
	CString m_xingming;
	CString m_xuehao;
//	CString m_zhuanye;
//	CString m_zhuzhi;
	CAdodc1 m_adodc1;
	CString m_banji;
	CString m_shengri;
	CString m_waihao;
	CString m_zhuanye;
	CString m_zhuzhi;
	afx_msg void OnBnClickedxiugaiButton1();
};
