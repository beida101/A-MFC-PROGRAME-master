#pragma once
#include "adodc1.h"


// CCHANGEshuru �Ի���

class CCHANGEshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CCHANGEshuru)

public:
	CCHANGEshuru(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCHANGEshuru();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_change;
	CString m_changeid;
	CString m_changemiaoshu;
	CString m_changeshijian;
	CString m_changestuid;
	afx_msg void OnBnClickedchangechashuButton1();
	CAdodc1 m_changeadodc;
};
