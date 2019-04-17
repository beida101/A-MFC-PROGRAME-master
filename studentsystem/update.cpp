// update.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "update.h"
#include "afxdialogex.h"
#include "column.h"
#include "columns.h"

// update �Ի���

IMPLEMENT_DYNAMIC(update, CDialogEx)

update::update(CWnd* pParent /*=NULL*/)
	: CDialogEx(update::IDD, pParent)
	, m_xingbie(_T(""))
	, m_xingming(_T(""))
	, m_xuehao(_T(""))
	, m_zhuanye(_T(""))
	, m_zhuzhi(_T(""))
	, m_banji(_T(""))
	, m_shengri(_T(""))
	, m_waihao(_T(""))
{

}

update::~update()
{
}

void update::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_update_DATAGRID1, m_datagrid);
	//  DDX_Control(pDX, IDC_ADODC1, m_adodc1);
//	DDX_Text(pDX, IDC_ningling_EDIT3, m_nianling);
	DDX_Text(pDX, IDC_xingbie_EDIT3, m_xingbie);
	//  DDX_Control(pDX, IDC_xingming_EDIT2, m_xingming);
	DDX_Text(pDX, IDC_xingming_EDIT2, m_xingming);
	DDX_Text(pDX, IDC_xuehao_EDIT1, m_xuehao);
	//DDX_Text(pDX, IDC_zhuanye_EDIT4, m_zhuanye);
	//DDX_Text(pDX, IDC_zhuzhi_EDIT5, m_zhuzhi);
	DDX_Control(pDX, IDC_ADODC1, m_adodc1);
	DDX_Text(pDX, IDC_banji_EDIT6, m_banji);
	DDX_Text(pDX, IDC_shengri_EDIT8, m_shengri);
	DDX_Text(pDX, IDC_waihao_EDIT10, m_waihao);
	DDX_Text(pDX, IDC_zhuanye_EDIT7, m_zhuanye);
	DDX_Text(pDX, IDC_zhuzhi_EDIT9, m_zhuzhi);
}


BEGIN_MESSAGE_MAP(update, CDialogEx)
	ON_BN_CLICKED(IDC_xiugai_BUTTON1, &update::OnBnClickedxiugaiButton1)
END_MESSAGE_MAP()


// update ��Ϣ�������
BEGIN_EVENTSINK_MAP(update, CDialogEx)
	ON_EVENT(update, IDC_update_DATAGRID1, DISPID_CLICK, update::OnClickUpdateDatagrid1, VTS_NONE)
END_EVENTSINK_MAP()


void update::OnClickUpdateDatagrid1()
{
	// TODO: �ڴ˴������Ϣ����������
	// TODO: �ڴ˴������Ϣ����������
	UpdateData(TRUE);
	int ColNum = 2;
	CString coVal;
	CColumns cols;
	CColumn  col;
	VARIANT v_ColNum, v_Value;
	cols = m_datagrid.get_Columns();
	v_ColNum.vt = VT_I2;

	v_ColNum.iVal = 0;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_xuehao = v_Value.bstrVal;

	//��ȡ����

	v_ColNum.iVal = 1;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_xingming = v_Value.bstrVal;

	//��ȡ�Ա�

	v_ColNum.iVal = 2;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_xingbie = v_Value.bstrVal;

	//��ȡ�༶
	v_ColNum.iVal = 3;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_banji = v_Value.bstrVal;

	//��ȡרҵ

	v_ColNum.iVal = 4;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_zhuanye = v_Value.bstrVal;

	//��ȡ����
	v_ColNum.iVal = 5;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_shengri = v_Value.bstrVal;

	//��ȡסַ

	v_ColNum.iVal = 6;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_zhuzhi = v_Value.bstrVal;

	//��ȡ���
	v_ColNum.iVal = 7;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	m_waihao = v_Value.bstrVal;


	UpdateData(FALSE);

}


void update::OnBnClickedxiugaiButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	_ConnectionPtr m_pConnection;
	::CoInitialize(NULL);             //��ʼ��OLE/COM�⻷��
	
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConn = "Provider = SQLOLEDB.1;Integrated Security = SSPI; Persist Security Info = False; Initial Catalog = ѧ����Ϣ����ϵͳ; Data Source = XURAN";
		m_pConnection->Open(strConn, "","",adModeUnknown);
		if(m_pConnection->State == adStateOpen) MessageBox("�Ѿ��ɹ����Ӹ����ݿ�");
	}
	catch(_com_error e)
	{
		::CoUninitialize();
		AfxMessageBox(e.ErrorMessage());
		return ;
	}

	_variant_t ra;
	_bstr_t strAdd = "UPDATE STUDENT SET NAME = '";
	strAdd = strAdd + m_xingming + "',SEX = '";
	strAdd = strAdd + m_xingbie + "',CLASS = '";
	strAdd = strAdd + m_banji + "',DEPARTMENT = '";
	strAdd = strAdd + m_zhuanye + "',NATIVE_PLACE = '";
	strAdd = strAdd + m_zhuzhi + "',��� = '";
	strAdd = strAdd + m_waihao + "'";
	strAdd = strAdd + " WHERE STUID = " + m_xuehao;

	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();

	m_adodc1.put_RecordSource("SELECT * FROM STUDENT"); 
	m_adodc1.Refresh();
	AfxMessageBox("�ɹ���������");
	UpdateData(FALSE);
}
