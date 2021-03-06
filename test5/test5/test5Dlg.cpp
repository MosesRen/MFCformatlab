
// test5Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5.h"
#include "test5Dlg.h"
#include "afxdialogex.h"
#include <string>  
#include  <afxpriv.h>
#include "engine.h" 
#include "huidu.h"
using namespace std;
#pragma comment( lib, "libeng.lib" )  
#pragma comment( lib, "libmx.lib" )  
#pragma comment( lib, "libmat.lib" )
#pragma comment( lib, "huidu.lib" )  
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Ctest5Dlg 对话框



Ctest5Dlg::Ctest5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest5Dlg::IDD, pParent)
	, s_3(0)
	, s_4(_T(""))
	, s_5(_T(""))
	, s_1(_T(""))
	, s_2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, EDIT3, s_3);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, s_4);
	DDV_MaxChars(pDX, s_4, 100);
	DDX_Text(pDX, IDC_MFCEDITBROWSE2, s_5);
	DDV_MaxChars(pDX, s_5, 100);

}

BEGIN_MESSAGE_MAP(Ctest5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest5Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Ctest5Dlg 消息处理程序

BOOL Ctest5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest5Dlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	if (!huiduInitialize());
	/*UpdateData(TRUE);
	s_1 = s_4;
	s_2 = s_5;
	UpdateData(false);*/
	mwArray  num(1, 1, mxINT16_CLASS);
	CString strText1;
	GetDlgItemText(IDC_MFCEDITBROWSE1, strText1);
	//AfxMessageBox(strText1);  //验证是否正确
	CString strText2;
	GetDlgItemText(IDC_MFCEDITBROWSE2, strText2);
//	AfxMessageBox(strText2);  //验证是否正确
	/*int n1 = strText1.GetLength();
	int n2 = strText2.GetLength();
	int len1 = WideCharToMultiByte(CP_ACP, 0, strText1, strText1.GetLength(), NULL, 0, NULL, NULL);
	int len2 = WideCharToMultiByte(CP_ACP, 0, strText1, strText2.GetLength(), NULL, 0, NULL, NULL);
	char * a1 = new char[len1 + 1];
	char * a2 = new char[len2 + 1];
	WideCharToMultiByte(CP_ACP, 0, strText1, strText1.GetLength(),a1, len1, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, strText2, strText2.GetLength(), a2, len2, NULL, NULL);
	a1[len1 + 1] = '/0';
	a2[len2 + 1] = '/0';*/
	//UpdateData(true);
	USES_CONVERSION;
	char * a1 = T2A(strText1);
	char * a2 = T2A(strText2);
	mwArray fe1(a1);
	mwArray fe2(a2);
	try
	{
		huidu(1, num, fe1, fe2);
	}
	catch (exception &e){
		s_1 = e.what();
	}
	s_3 = num;
	UpdateData(false);

}


