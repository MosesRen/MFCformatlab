
// test5Dlg.h : ͷ�ļ�
//

#pragma once


// Ctest5Dlg �Ի���
class Ctest5Dlg : public CDialogEx
{
// ����
public:
	Ctest5Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST5_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
