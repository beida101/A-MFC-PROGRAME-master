// chaDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "chaDlg.h"
#include "afxdialogex.h"
#include "studentsystemDlg.h"
#include "Cduobiao.h"
// chaDlg �Ի���

IMPLEMENT_DYNAMIC(chaDlg, CDialogEx)

chaDlg::chaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(chaDlg::IDD, pParent)
{

}

chaDlg::~chaDlg()
{
}

void chaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(chaDlg, CDialogEx)
	ON_BN_CLICKED(IDC_danbiao_BUTTON2, &chaDlg::OnClickedDanbiaoButton2)
//	ON_BN_CLICKED(IDC_duobiao_BUTTON1, &chaDlg::OnClickedDuobiaoButton1)
ON_BN_CLICKED(IDC_duobiao_BUTTON1, &chaDlg::OnBnClickedduobiaoButton1)
END_MESSAGE_MAP()


// chaDlg ��Ϣ�������


void chaDlg::OnClickedDanbiaoButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CstudentsystemDlg dlg;
	dlg.DoModal();
}



void chaDlg::OnBnClickedduobiaoButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Cduobiao dlg;
	dlg.DoModal();
}
