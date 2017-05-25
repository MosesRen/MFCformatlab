
// test5Dlg.h : 头文件
//

#pragma once


// Ctest5Dlg 对话框
class Ctest5Dlg : public CDialogEx
{
// 构造
public:
	Ctest5Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST5_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit2();
//	CString s_1;
//	CString s_2;
	int s_3;
	afx_msg void OnEnChangeMfceditbrowse1();
	CString s_4;
	CString s_5;
	afx_msg void OnEnChangeMfceditbrowse2();
	CString s_1;
	CString s_2;
};
