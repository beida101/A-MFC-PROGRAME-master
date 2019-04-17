// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "studentsystemDlg.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "insertdata.h"
#include "denglu.h"
#include "chaDlg.h"
#include "update.h"
#include "Mainshuru.h"
#include "Cshanchu.h"
// MainDlg �Ի���

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MainDlg::IDD, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &MainDlg::OnBnClickedButtonInsert)
//	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &MainDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &MainDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_shuru_BUTTON1, &MainDlg::OnBnClickedshuruButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &MainDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// MainDlg ��Ϣ�������


void MainDlg::OnBnClickedButtonInsert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CstudentsystemDlg dlg;
	//chaxunzhu dlg;
	chaDlg dlg;
	dlg.DoModal();
	
}


void MainDlg::OnBnClickedButton2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
	update dlg;
	dlg.DoModal();
}


void MainDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}





void MainDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	update dlg;
	dlg.DoModal();
}


void MainDlg::OnBnClickedshuruButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mainshuru dlag;
	dlag.DoModal();
}


void MainDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Cshanchu dlag;
	dlag.DoModal();
}
