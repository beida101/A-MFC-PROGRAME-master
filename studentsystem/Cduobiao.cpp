// Cduobiao.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "Cduobiao.h"
#include "afxdialogex.h"


// Cduobiao �Ի���

IMPLEMENT_DYNAMIC(Cduobiao, CDialogEx)

Cduobiao::Cduobiao(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cduobiao::IDD, pParent)
	, m_duobiaobanji(_T(""))
	, m_duobiaoxingming(_T(""))
{

}

Cduobiao::~Cduobiao()
{
}

void Cduobiao::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_banji_EDIT2, m_duobiaobanji);
	DDX_Text(pDX, IDC_xingming_EDIT1, m_duobiaoxingming);
	DDX_Control(pDX, IDC_ADODC1, m_duobiaoadodc1);
}


BEGIN_MESSAGE_MAP(Cduobiao, CDialogEx)
	ON_BN_CLICKED(IDC_xingming_RADIO1, &Cduobiao::OnBnClickedxingmingRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Cduobiao::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_chaxun_BUTTON1, &Cduobiao::OnBnClickedchaxunButton1)
END_MESSAGE_MAP()


// Cduobiao ��Ϣ�������

int selectyes = 0;
void Cduobiao::OnBnClickedxingmingRadio1()
{
	selectyes = 1;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Cduobiao::OnBnClickedRadio2()
{
	selectyes = 2;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Cduobiao::OnBnClickedchaxunButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(selectyes == 1)
	{
		CString str = "select * from Stu_view where s_name = '" + m_duobiaoxingming + "'";
		m_duobiaoadodc1.put_RecordSource(str);
		m_duobiaoadodc1.Refresh();
		UpdateData(FALSE);
	}
}
