#pragma once
#include "adodc1.h"


// CREWARDshuru �Ի���

class CREWARDshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CREWARDshuru)

public:
	CREWARDshuru(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CREWARDshuru();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CAdodc1 m_rewardadodc;
	CString m_rewarddengji;
	CString m_rewardid;
	CString m_rewardmiaoshu;
	CString m_rewardshijian;
	CString m_rewardstuid;
	afx_msg void OnBnClickedcharuButton1();
};
