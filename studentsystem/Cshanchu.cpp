// Cshanchu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "Cshanchu.h"
#include "afxdialogex.h"
#include "column.h"
#include "columns.h"

// Cshanchu �Ի���

IMPLEMENT_DYNAMIC(Cshanchu, CDialogEx)

Cshanchu::Cshanchu(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cshanchu::IDD, pParent)
{

}

Cshanchu::~Cshanchu()
{
}

void Cshanchu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_shanchu_ADODC1, m_shanchuadodc1);
	DDX_Control(pDX, IDC_shanchu_DATAGRID1, m_shanchudatagrid);
}


BEGIN_MESSAGE_MAP(Cshanchu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cshanchu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Cshanchu::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cshanchu ��Ϣ�������
BEGIN_EVENTSINK_MAP(Cshanchu, CDialogEx)
	ON_EVENT(Cshanchu, IDC_shanchu_DATAGRID1, DISPID_DBLCLICK, Cshanchu::OnDblclickShanchuDatagrid1, VTS_NONE)
END_EVENTSINK_MAP()


void Cshanchu::OnDblclickShanchuDatagrid1()
{
	// TODO: �ڴ˴������Ϣ����������
	int ColNum = 2;
	CString coVal;
	CColumns cols;
	CColumn  col;
	VARIANT v_ColNum, v_Value;
	cols = m_shanchudatagrid.get_Columns();
	v_ColNum.vt = VT_I2;

	//��ȡѧ��
	v_ColNum.iVal = 0;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	CString temp = (CString)v_Value.bstrVal;
	CString temp2 = "ȷ��Ҫɾ�����Ϊ " + temp + "�ļ�¼ô��";
	if(MessageBox(temp2,_T("ɾ��������ʾ"),MB_YESNO|MB_ICONSTOP)!=IDYES)
		return ;

	UpdateData(TRUE);
	_ConnectionPtr m_pConnection;
	::CoInitialize(NULL);     //��ʼ��OLE�ؼ�
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
	_bstr_t strAdd = "DELETE FROM STUDENT WHERE STUID = " + temp;
	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();
	m_shanchuadodc1.put_RecordSource("select * from STUDENT");
	m_shanchuadodc1.Refresh();
	UpdateData(FALSE);
}


void Cshanchu::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnDblclickShanchuDatagrid1();
}


void Cshanchu::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(MessageBox(_T("ȷ��Ҫɾ�����е�����ô"),_T("ɾ��������ʾ"),MB_YESNO|MB_ICONSTOP)!=IDYES)
		return ;

	UpdateData(TRUE);
	_ConnectionPtr m_pConnection;
	::CoInitialize(NULL);     //��ʼ��OLE�ؼ�
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
	_bstr_t strAdd = "DELETE FROM STUDENT";
	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();
	m_shanchuadodc1.put_RecordSource("select * from STUDENT");
	m_shanchuadodc1.Refresh();
	UpdateData(FALSE);

}
