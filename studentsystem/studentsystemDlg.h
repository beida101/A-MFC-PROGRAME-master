
// studentsystemDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "adodc1.h"
#include "datagrid1.h"


// CstudentsystemDlg �Ի���
class CstudentsystemDlg : public CDialogEx
{
// ����
public:
	CstudentsystemDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void CstudentsystemDlg::takeupdate();
// �Ի�������
	enum { IDD = IDD_STUDENTSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_biao;
	CComboBox m_ziduan_combo;
//	CComboBox m_combo_ziduan;
	CString m_edit_shuru;
	CAdodc1 m_adodc1;
	afx_msg void OnClickedChaxunButton1();
	afx_msg void OnKillfocusBiaoCombo1();
	//CComboBox m_combo_ziduan;
//	afx_msg void OnCbnSelchangebiaoCombo1();
	CDatagrid1 m_grid;
};
