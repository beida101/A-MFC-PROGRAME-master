// denglu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "denglu.h"
#include "afxdialogex.h"
#include "MainDlg.h"

// denglu �Ի���

IMPLEMENT_DYNAMIC(denglu, CDialogEx)

	denglu::denglu(CWnd* pParent /*=NULL*/)
	: CDialogEx(denglu::IDD, pParent)
	, m_edit_yonghuming(_T(""))
	, m_edit_mima(_T(""))
{

}

denglu::~denglu()
{
}

void denglu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_yonghuming_EDIT1, m_edit_yonghuming);
	DDX_Text(pDX, IDC_mima_EDIT2, m_edit_mima);
}


BEGIN_MESSAGE_MAP(denglu, CDialogEx)
	ON_BN_CLICKED(IDC_debglu_BUTTON3, &denglu::OnBnClickeddebgluButton3)
END_MESSAGE_MAP()


// denglu ��Ϣ�������


void denglu::OnBnClickeddebgluButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString admin = "xuran";
	CString passwd = "123456";
	int counts = 1;

	CString yonghuming = m_edit_yonghuming;
	CString mima = m_edit_mima;
	if(admin == yonghuming && passwd == mima)
	{
		MainDlg dlg;
		dlg.DoModal();
	}
	else
	{
		MessageBox("������˻������ԣ���װ�ˣ���϶���֪��");
		counts++;
	}
	if(counts == 3)
	{
		MessageBox("��½ʧ�ܳ������Σ���û��Ȩ�޵�½ϵͳ");
		return ;
	}
	UpdateData(FALSE);

}
