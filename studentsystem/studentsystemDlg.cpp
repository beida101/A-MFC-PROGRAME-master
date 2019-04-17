
// studentsystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "studentsystem.h"
#include "studentsystemDlg.h"
#include "afxdialogex.h"
#include "datagrid1.h"
#include "CColumn.h"
#include "CColumns0.h"
#include "string"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

_ConnectionPtr m_pConnection;
_RecordsetPtr  m_pRecordsetPtr;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CstudentsystemDlg �Ի���



CstudentsystemDlg::CstudentsystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CstudentsystemDlg::IDD, pParent)
	, m_edit_shuru(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CstudentsystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_biao_COMBO1, m_combo_biao);
	//  DDX_Control(pDX, IDC_ziduan_COMBO2, m_combo_ziduan);
	DDX_Text(pDX, IDC_shuru_EDIT1, m_edit_shuru);
	DDX_Control(pDX, IDC_ADODC1, m_adodc1);
	DDX_Control(pDX, IDC_ziduan_COMBO3, m_ziduan_combo);
	DDX_Control(pDX, IDC_DATAGRID1, m_grid);
}

BEGIN_MESSAGE_MAP(CstudentsystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_chaxun_BUTTON1, &CstudentsystemDlg::OnClickedChaxunButton1)
	ON_CBN_KILLFOCUS(IDC_biao_COMBO1, &CstudentsystemDlg::OnKillfocusBiaoCombo1)
	//	ON_CBN_SELCHANGE(IDC_biao_COMBO1, &CstudentsystemDlg::OnCbnSelchangebiaoCombo1)
END_MESSAGE_MAP()


// CstudentsystemDlg ��Ϣ�������

BOOL CstudentsystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_combo_biao.SetWindowText((CString)"STUDENT");                      //��ʼ��
	m_ziduan_combo.SetWindowText((CString)"NAME");
	m_ziduan_combo.SetWindowText((CString)"SEX");
	m_ziduan_combo.SetWindowText((CString)"STUID");

	m_combo_biao.AddString("STUDENT");
	m_combo_biao.AddString("CHANGE");
	m_combo_biao.AddString("REWARD");
	m_combo_biao.AddString("PUBLISHMENT");
	m_combo_biao.AddString("DEPARTMENT");
	m_combo_biao.AddString("CLASS");


	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CstudentsystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CstudentsystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CstudentsystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CstudentsystemDlg::OnClickedChaxunButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString tempstr;
	CString strSQL = (CString)"SELECT * FROM ";
	m_combo_biao.GetWindowText(tempstr);            //��ȡcombo�˵��е�����
	strSQL += tempstr + (CString)" WHERE ";
	m_ziduan_combo.GetWindowText(tempstr);
	strSQL += tempstr + (CString)" = ";
	strSQL += (CString)"'" + m_edit_shuru + (CString)"'";
    m_adodc1.put_RecordSource(strSQL);
    m_adodc1.Refresh();
	m_grid.Refresh();
	UpdateData(FALSE);    //
}

void CstudentsystemDlg::takeupdate()
{
	UpdateData(TRUE);
	CString tempstr;
	CString strSQL = (CString)"SELECT * FROM ";
	m_combo_biao.GetWindowText(tempstr);
	strSQL += tempstr;
	m_adodc1.put_RecordSource(strSQL);
    m_adodc1.Refresh();
	m_grid.Refresh();
	UpdateData(FALSE);
}
void CstudentsystemDlg::OnKillfocusBiaoCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tableName;
	m_combo_biao.GetWindowText(tableName);
	m_ziduan_combo.ResetContent();
	::CoInitialize(NULL);             //��ʼ��OLE/COM�⻷��
	if(tableName == "STUDENT")
	{

		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("NAME");
		m_ziduan_combo.AddString("SEX");
		m_ziduan_combo.AddString("CLASS");
		takeupdate();
	}
	else if(tableName == "CHANGE")
	{
		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("CHANGE");
		takeupdate();
	//try
	//{
		//m_pConnection.CreateInstance("ADODB.Connection");
		//m_pRecordsetPtr.CreateInstance("ADODB.Recordset");
		//_bstr_t strConn = "Provider = SQLOLEDB.1;Integrated Security = SSPI; Persist Security Info = False; Initial Catalog = �γ����ʵ��; Data Source = XURAN";
		//m_pConnection->Open(strConn, "","",adModeUnknown);
		//if(m_pConnection->State == adStateOpen) MessageBox("�Ѿ��ɹ����Ӹ����ݿ�");
		//m_pRecordsetPtr->Open("SELECT * FROM students",_variant_t((IDispatch*)m_pConnection,true),adOpenStatic,adLockOptimistic,adCmdText);
		//m_grid.putref_DataSource(NULL);
		//m_grid.putref_DataSource((LPUNKNOWN)m_pRecordsetPtr);
		//m_grid.Refresh();
		//if(m_pConnection->State == adStateOpen) MessageBox("�Ѿ��ɹ����Ӹ����ݿ�");
	//}
	//catch(_com_error e)
	//{
	//	::CoUninitialize();
	//	AfxMessageBox(e.ErrorMessage());
	//	return ;
	//}
		

	} else if(tableName == "REWARD")
	{
		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("LEVELS");
		takeupdate();

	} else if(tableName == "PUBLISHMENT")
	{
		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("LEVELS");
		takeupdate();

	} else if(tableName == "DEPARTMENT")
	{
		m_ziduan_combo.AddString("ID");
		m_ziduan_combo.AddString("NAME");
		takeupdate();

	} else if(tableName == "CLASS")
	{
		m_ziduan_combo.AddString("ID");
		m_ziduan_combo.AddString("NAME");
		m_ziduan_combo.AddString("MONITOR");
		takeupdate();
	}

}
