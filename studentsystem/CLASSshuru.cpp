// CLASSshuru.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "CLASSshuru.h"
#include "afxdialogex.h"


// CCLASSshuru �Ի���

IMPLEMENT_DYNAMIC(CCLASSshuru, CDialogEx)

CCLASSshuru::CCLASSshuru(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCLASSshuru::IDD, pParent)
	, m_banjibanzhang(_T(""))
	, m_banjiid(_T(""))
	, m_banjiname(_T(""))
{

}

CCLASSshuru::~CCLASSshuru()
{
}

void CCLASSshuru::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_banji_ADODC1, m_banjiadodc);
	DDX_Text(pDX, IDC_banjibanzhang_EDIT3, m_banjibanzhang);
	DDX_Text(pDX, IDC_banjiid_EDIT1, m_banjiid);
	DDX_Text(pDX, IDC_banjiname_EDIT2, m_banjiname);
}


BEGIN_MESSAGE_MAP(CCLASSshuru, CDialogEx)
	ON_BN_CLICKED(IDC_charu_BUTTON1, &CCLASSshuru::OnBnClickedcharuButton1)
END_MESSAGE_MAP()


// CCLASSshuru ��Ϣ�������


void CCLASSshuru::OnBnClickedcharuButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_ConnectionPtr m_pConnection;
	::CoInitialize(NULL);             //��ʼ��OLE/COM�⻷��
	
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConn = "Provider = SQLOLEDB.1;Integrated Security = SSPI; Persist Security Info = False; Initial Catalog = ѧ����Ϣ����ϵͳ; Data Source = XURAN";
		m_pConnection->Open(strConn, "","",adModeUnknown);
		//if(m_pConnection->State == adStateOpen) MessageBox("�Ѿ��ɹ����Ӹ����ݿ�");
	}
	catch(_com_error e)
	{
		::CoUninitialize();
		AfxMessageBox(e.ErrorMessage());
		return ;
	}

	_variant_t ra;
	_bstr_t strAdd = "INSERT INTO CLASS VALUES('";
	strAdd = strAdd + m_banjiid + "','"; 
	strAdd = strAdd + m_banjiname + "','";
	strAdd = strAdd + m_banjibanzhang + "')";

	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();

	m_banjiadodc.put_RecordSource("SELECT * FROM CLASS"); 
	m_banjiadodc.Refresh();
	UpdateData(FALSE);
}
