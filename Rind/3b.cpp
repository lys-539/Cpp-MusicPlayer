/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///                                                           ///
///                   ��������ʦ���ң�����                    ///
///                                                           ///
///          �����������Ļ�Ҫ����Ŀ�ַ�������Ϊ             ///
///                        UNICODE                            ///
///                      ������������                         ///
///                                                           ///
///                   ��������ʦ���ң�����                    ///
///                                                           ///
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#include <windows.h> 
#include <string>
#include <wchar.h>
#include <iostream>
#include <tchar.h>
#include <ShlObj.h>
#include <io.h>
#include <digitalv.h>
#include <fstream>                 // ֧���ļ����ʵ����

#define OK 1
#define ERROR 0
#define ElemType string
typedef int Status;
#define LIST_INIT_SIZE 10000     //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10          //���Ա�洢�ռ�ķ�������
#pragma comment(lib,"winmm.lib")
using namespace std;

#pragma comment(linker, "/subsystem:windows")

//��Ƕͼ������
void MyIconExtract()
{
	char IconData[894] = {
		0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, 0x10, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x68, 0x03,
		0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00,
		0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC4, 0x0E,
		0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x8A,
		0x99, 0x86, 0x8A, 0x99, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA,
		0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9,
		0xD6, 0xFA, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x86, 0x8A,
		0x99, 0x86, 0x8A, 0x99, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA,
		0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xB9,
		0xD6, 0xFA, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x53, 0x56,
		0x63, 0x53, 0x56, 0x63, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5,
		0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xA6, 0xCA, 0xF5, 0xA6, 0xCA, 0xF5, 0xA5, 0xA5, 0xA5, 0xA5,
		0xA5, 0xA5, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56,
		0x63, 0x53, 0x56, 0x63, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5,
		0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0xA6, 0xCA, 0xF5, 0xA6, 0xCA, 0xF5, 0xA5, 0xA5, 0xA5, 0xA5,
		0xA5, 0xA5, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x86, 0x8A,
		0x99, 0x86, 0x8A, 0x99, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70,
		0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x70, 0x70, 0x70, 0x70,
		0x70, 0x70, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x86, 0x8A,
		0x99, 0x86, 0x8A, 0x99, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70,
		0xB9, 0xD6, 0xFA, 0xB9, 0xD6, 0xFA, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x70, 0x70, 0x70, 0x70,
		0x70, 0x70, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x53, 0x56,
		0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63,
		0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x53, 0x56, 0x63, 0x53,
		0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x53, 0x56,
		0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63,
		0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x53, 0x56, 0x63, 0x53,
		0x56, 0x63, 0x53, 0x56, 0x63, 0x53, 0x56, 0x63, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x86, 0x8A,
		0x99, 0x86, 0x8A, 0x99, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8,
		0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x99, 0xB7, 0xE8, 0x99,
		0xB7, 0xE8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0x86, 0x8A,
		0x99, 0x86, 0x8A, 0x99, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8, 0x99, 0xB7, 0xE8,
		0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x99, 0xB7, 0xE8, 0x99,
		0xB7, 0xE8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0x90, 0x95,
		0xA8, 0x90, 0x95, 0xA8, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8,
		0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0xAB, 0xB3, 0xCD, 0xAB,
		0xB3, 0xCD, 0xB8, 0xC3, 0xDE, 0xB8, 0xC3, 0xDE, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x90, 0x95,
		0xA8, 0x90, 0x95, 0xA8, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8,
		0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0xAB, 0xB3, 0xCD, 0xAB,
		0xB3, 0xCD, 0xB8, 0xC3, 0xDE, 0xB8, 0xC3, 0xDE, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x90, 0x95,
		0xA8, 0x90, 0x95, 0xA8, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9,
		0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0xB8, 0xC3, 0xDE, 0xB8, 0xC3, 0xDE, 0xB8, 0xC3, 0xDE, 0xB8,
		0xC3, 0xDE, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95,
		0xA8, 0x90, 0x95, 0xA8, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9,
		0xAB, 0xB3, 0xCD, 0xAB, 0xB3, 0xCD, 0xB8, 0xC3, 0xDE, 0xB8, 0xC3, 0xDE, 0xB8, 0xC3, 0xDE, 0xB8,
		0xC3, 0xDE, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95,
		0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8,
		0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x86, 0x8A, 0x99, 0x86,
		0x8A, 0x99, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95,
		0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8,
		0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x9B, 0xA1, 0xB9, 0x9B, 0xA1, 0xB9, 0x86, 0x8A, 0x99, 0x86,
		0x8A, 0x99, 0x86, 0x8A, 0x99, 0x86, 0x8A, 0x99, 0x90, 0x95, 0xA8, 0x90, 0x95, 0xA8, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	ofstream infile("LuisIcon.ico", ios::out | ios::binary);
	infile.write(IconData, 894);
	infile.close();
}

//�����ַ�����ʽת��(���������ظ���
string UTF8_To_string(const string& str)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];//һ��Ҫ��1����Ȼ�����β��
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = pBuf;

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;
}
string wstring2string(wstring wstr)
{
	string result;
	//��ȡ��������С��������ռ䣬��������С�°��ֽڼ����  
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	//���ֽڱ���ת���ɶ��ֽڱ���  
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	//ɾ��������������ֵ  
	result.append(buffer);
	delete[] buffer;
	return result;
}
wstring string2wstring(string str)
{
	wstring result;
	//��ȡ��������С��������ռ䣬��������С���ַ�����  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//���ֽڱ���ת���ɿ��ֽڱ���  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //����ַ�����β  
	//ɾ��������������ֵ  
	result.append(buffer);
	delete[] buffer;
	return result;
}
wstring mmsecond2str(int time1, int time2)
{
	int a1 = time1 / 1000;
	int a2 = time2 / 1000;
	int c1 = a1 / 60;
	int c2 = a2 / 60;
	int b1 = a1 % 60;
	int b2 = a2 % 60;
	wstring s = L":", ss = L"/", bb1 = L"", bb2 = L"";
	if (b1 < 10)
	{
		bb1 = L"0";
	}
	if (b2 < 10)
	{
		bb2 = L"0";
	}
	return (to_wstring(c1) + s + bb1 + to_wstring(b1)+ ss + to_wstring(c2) + s + bb2 + to_wstring(b2));
}
string TCHAR2STRING(TCHAR* STR)
{
	int iLen = WideCharToMultiByte(CP_ACP, 0, STR, -1, NULL, 0, NULL, NULL);
	char* chRtn = new char[iLen * sizeof(char)];
	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);
	std::string str(chRtn);
	delete chRtn;
	return str;
}
LPCWSTR stringToLPCWSTR(string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}
wchar_t* char2wchar(const char* cchar)
{
	wchar_t* m_wchar;
	int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
	m_wchar[len] = '\0';
	return m_wchar;
}

//����û�Ĺ���ʵ������
typedef struct {
	ElemType* elem;       //�洢�ռ��ַ        
	int length;           //��ǰ����        
	int listsize;         //��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;
Status InitList_Sq(SqList& L)
{  // ����һ���յ����Ա�L(�㷨2.3)
	//  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	L.elem = new ElemType[LIST_INIT_SIZE];
	if (!L.elem) return ERROR;        // �洢����ʧ��
	L.length = 0;                  // �ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
	return OK;
} // InitList_Sq
Status ListInsert_Sq(SqList& L, int i, ElemType e)
{  // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e(�㷨2.4)
   // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
	if (i < 1 || i > L.length + 1) return ERROR;  // iֵ���Ϸ�
	if (L.length >= L.listsize) return ERROR;  // ��ǰ�洢�ռ�����
	for (int j = L.length; j > i; j--)      // Shift Elems up
		L.elem[j] = L.elem[j - 1];       //   to make room

	L.elem[i - 1] = e;

	++L.length;   // ����1
	return OK;
} // ListInsert_Sq
Status DestroyList_Sq(SqList& L)
{ //�������Ա�L
	delete[] L.elem;
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestroyList_Sq()
int ListLength_Sq(SqList L)
{ //�������Ա�ĳ���
	return L.length;
}//ListLength_Sq()
Status GetElem_Sq(SqList L, int i, ElemType& e)
{ //��e����L�е�i��Ԫ�ص�ֵ
	e = *(L.elem + i - 1);
	return OK;
}//GetElem_Sq()
MCI_OPEN_PARMS op;

//���޹���mciͨ��
bool mp3player(string s, bool setflag, int start_time, int end_time)
{ //���Ÿ�����mp3player������sΪ�����ļ�������ȫ��·����Ϣ��
	string flag;

	int length = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, 0);
	wchar_t aa[1000];
	wchar_t* wideString = aa;
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, wideString, length);

	op.lpstrElementName = wideString;

	char* c = nullptr;                    //��ʼ��char*���ͣ�����ֵΪ��
	const char* constc = nullptr;         //��ʼ��const char*���ͣ�����ֵΪ��
	constc = s.c_str();                 //string����תconst char*����
	c = const_cast<char*>(constc);

	const char* d = ".";
	char* p1 = NULL, * p2 = NULL;
	p1 = strtok_s(c, d, &c);
	while (p1)
	{
		p2 = p1;
		p1 = strtok_s(NULL, d, &c);
	}

	if (p1 == "wav")
	{
		op.lpstrDeviceType = L"waveaudio";
	}
	else
	{
		op.lpstrDeviceType = L"mpegvideo";
	}

	int rs = mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_WAIT, (DWORD_PTR)&op);

	if (rs != 0)
	{
		MessageBox(NULL, L"�޷����ļ�, ���� 3s �󲥷���һ��", L"WARN", MB_OK | MB_ICONINFORMATION);
		Sleep(3000);
		return false;
	}
	else
	{
		MCI_PLAY_PARMS pp;
		if (setflag)
		{
			pp.dwFrom = start_time;
			pp.dwTo = end_time;
			mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_FROM | MCI_TO, (DWORD_PTR)&pp);
		}
		else
		{
			mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&pp);
		}
		return true;
	}
}


//һЩȫ�ֱ���
SqList SongList;
bool Playflag = true, IsPlay = false, IsPause = false, IsChange = false, IsTimeSet = false, IsVolumBarShow = false, IsVolumChange = false;
int PlayIndex = 0, SetTime, PlayMode = 0, Volum = 0;
HWND hwnd, Lable, hListBox, RollBar, TimeLable, ModeLable, VolumBar, VolumLable;

void SearchFolder(string PathDir);
//�����ļ��б���
void DfsListFolderFiles(string path, string FileType, bool IsDir)
{
	_finddata_t file_info;
	string current_path = path + "\\" + FileType;
	intptr_t handle = _findfirst(current_path.c_str(), &file_info);
	//����ֵΪ-1�����ʧ��  
	if (-1 == handle)
	{
		//MessageBox(NULL, L"     �ļ��е���ʧ��!", L"Err", MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	do
	{
		if (file_info.attrib == _A_SUBDIR && IsDir)
		{
			if (strcmp(file_info.name, "..") != 0 && strcmp(file_info.name, ".") != 0)
				SearchFolder(path + "\\" + file_info.name);
		}
		else if (!IsDir)
		{
			SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)char2wchar(file_info.name));
			ListInsert_Sq(SongList, ListLength_Sq(SongList) + 1, path + "\\" + file_info.name);
		}
	} while (!_findnext(handle, &file_info));
	//�ر��ļ����  
	_findclose(handle);
}

//�����ļ������
void SearchFolder(string PathDir)
{
	DfsListFolderFiles(PathDir, "*.mp3", false);
	DfsListFolderFiles(PathDir, "*.wav", false);
	DfsListFolderFiles(PathDir, "*.*", true);
}

//[���ļ���] ��
BOOL SelectDir(HWND hWnd, wstring& strPath)
{
	BROWSEINFO bifolder;
	wchar_t FileName[MAX_PATH];
	ZeroMemory(&bifolder, sizeof(BROWSEINFO));
	bifolder.hwndOwner = hWnd;				// ӵ���߾��
	bifolder.pszDisplayName = FileName;		// ���Ŀ¼·��������
	bifolder.lpszTitle = TEXT("��ѡ���ļ���");	// ����
	bifolder.ulFlags = BIF_USENEWUI; // �µ���ʽ,���༭��

	LPITEMIDLIST idl = SHBrowseForFolder(&bifolder);
	if (idl == NULL)
	{
		return FALSE;
	}

	SHGetPathFromIDList(idl, FileName);
	strPath = FileName;
	return TRUE;
}

//���ֲ����߳�
DWORD WINAPI MusicPlayer(LPVOID arg)
{
	string songName, Lyrics;
	bool Checkflag, timesetflag = false, Lyrics_flag;
	int start_time = 0, end_time = 0, Lyric_time = 0;

	while (Playflag)
	{
		Lyrics = "δ�ҵ����";
		while (PlayIndex >= ListLength_Sq(SongList))
		{
			PlayIndex -= ListLength_Sq(SongList);
		}

		Checkflag = false;
		GetElem_Sq(SongList, PlayIndex + 1, songName);
		if (!mp3player(songName, timesetflag,start_time,end_time))
		{
			Checkflag = true;
		}
		timesetflag = false;
		if (!Checkflag)
		{
			ifstream Lyrics_File(songName.substr(0, songName.length() - 3) + "lrc");
			if (!Lyrics_File.fail())
			{
				getline(Lyrics_File, Lyrics);
				Lyrics = UTF8_To_string(Lyrics);
				Lyrics = Lyrics.substr(10, Lyrics.length() - 10);
				Lyrics_flag = true;
			}
			else Lyrics_flag = false;

			LPTSTR s10 = new TCHAR[100];
			wstring s11 = L"���ڲ���: ";
			wstring s12 = string2wstring(Lyrics);
			SendMessage(hListBox, LB_GETTEXT, PlayIndex, (LPARAM)s10);
			wstring s20(s10);
			SetWindowText(hwnd, (s11 + s10 + L"  00:00/00:00").c_str());
			wstring s_front = s11 + s20 + L"\n\n\n\n\n";
			s20 = s_front + s12;
			SetWindowText(Lable, s20.c_str());

			MCI_STATUS_PARMS sp1, sp2;
			sp1.dwItem = MCI_STATUS_LENGTH;
			sp2.dwItem = MCI_STATUS_POSITION;
			mciSendCommand(op.wDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&sp1);
			SetScrollRange(RollBar, SB_CTL, 0, int(sp1.dwReturn/1000), true);
			
			if (Lyrics_flag)
			{
				getline(Lyrics_File, Lyrics);
				Lyrics = UTF8_To_string(Lyrics);
				Lyric_time = ((Lyrics[1] - 48) * 600 + (Lyrics[2] - 48) * 60 + (Lyrics[4] - 48) * 10 + (Lyrics[5] - 48)) * 1000;
				Lyrics = Lyrics.substr(10, Lyrics.length() - 10);
			}
			while (!Checkflag)
			{
				Sleep(100);
				mciSendCommand(op.wDeviceID, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD_PTR)&sp2);
				SetScrollPos(RollBar, SB_CTL, int(sp2.dwReturn / 1000), true);
				SetWindowText(TimeLable, mmsecond2str(sp2.dwReturn, sp1.dwReturn).c_str());
				SetWindowText(hwnd, (s11 + s10 + L"  " + mmsecond2str(sp2.dwReturn, sp1.dwReturn)).c_str());

				while (Lyric_time <= sp2.dwReturn && Lyrics_flag)
				{
					s20 = s_front + string2wstring(Lyrics);
					SetWindowText(Lable, s20.c_str());
					getline(Lyrics_File, Lyrics);
					Lyrics = UTF8_To_string(Lyrics);
					Lyric_time = ((Lyrics[1] - 48) * 600 + (Lyrics[2] - 48) * 60 + (Lyrics[4] - 48) * 10 + (Lyrics[5] - 48)) * 1000;
					Lyrics = Lyrics.substr(10, Lyrics.length() - 10);
				}
				if (sp2.dwReturn == sp1.dwReturn)
				{
					MCI_GENERIC_PARMS gp;
					mciSendCommand(op.wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD_PTR)&gp);
					Checkflag = true;
					switch (PlayMode)
					{
					case 0:
						break;
					case 1:
						PlayIndex+= rand() % 50;
						break;
					case 2:
						PlayIndex--;
						break;
					}
				}
				if(IsVolumChange)
				{
					MCI_DGV_SETAUDIO_PARMS  mciSetAudioPara;  //����ṹ����Ҫ����<digitalv.h> 
					mciSetAudioPara.dwCallback = NULL;  //�ص������ÿ�
					mciSetAudioPara.dwItem = MCI_DGV_SETAUDIO_VOLUME;  //ѡ��Ϊ����������
					mciSetAudioPara.dwValue = (DWORD)Volum;   //�˴����Ǿ���������С (0--1000) 
					mciSendCommand(op.wDeviceID, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD_PTR)&mciSetAudioPara);
					//waveOutSetVolume((HWAVEOUT)op.dwCallback, (DWORD)Volum);
					IsVolumChange = false;
				}
				if (IsTimeSet)
				{
					start_time = SetTime;
					end_time = sp1.dwReturn;
					MCI_GENERIC_PARMS gp;
					mciSendCommand(op.wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD_PTR)&gp);
					PlayIndex--;
					SetTime = 0;
					timesetflag = true;
					IsTimeSet = false;
					Checkflag = true;
				}
				if (IsChange)
				{
					MCI_GENERIC_PARMS gp;
					mciSendCommand(op.wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD_PTR)&gp);
					IsChange = false;
					Checkflag = true;
					switch (PlayMode)
					{
					case 0:
						break;
					case 1:
						PlayIndex += rand() % 50;
					case 2:
						PlayIndex--;
					}
				}
				if (IsPause)
				{
					MCI_GENERIC_PARMS gp;
					int a = mciSendCommand(op.wDeviceID, MCI_PAUSE, MCI_WAIT, (DWORD_PTR)&gp);
					if (a != 0)
					{
						IsPause = false;
					}
					while (IsPause)
					{
						Sleep(10);
					}
					if (a == 0)
					{
						mciSendCommand(op.wDeviceID, MCI_RESUME, MCI_WAIT, (DWORD_PTR)&gp);
					}
				}
			}
			delete(s10);
			Lyrics_File.close();
		}
		PlayIndex++;
	}
	return NULL;
}


//[��] [���Ϊ] ��
void GetMoreFile(HWND hwnd, int funtype) {
	if (funtype != 4)
	{
		TCHAR szPath[MAX_PATH]{ 0 };//�洢��ǰ�ļ�����·���������ļ���
		TCHAR szTitle[MAX_PATH]{ 0 };//�洢��ǰ�ļ���
		TCHAR szFilePath[MAX_PATH]{ 0 };//�洢��ǰ�ļ�·��
		TCHAR szFiles[256 * MAX_PATH]{ 0 };//���Դ������80���ļ���·��,���洢���л���ļ�
		TCHAR* p;
		LPOPENFILENAME var = new OPENFILENAMEW;

		ZeroMemory(var, sizeof(OPENFILENAMEW));
		var->hwndOwner = hwnd;
		//ָ�������߶Ի��򴰿ڵľ���������Ա������������Ч���ھ����������Ի���û��������������ΪNULL��
		var->lStructSize = sizeof(OPENFILENAMEW);
		var->lpstrInitialDir = L".\\";//Ĭ�ϵĳ�ʼ�ļ�·��
		var->lpstrFile = szFiles;//��Ž�Ҫ��ȡ�������ļ��Ļ�����
		var->nMaxFile = sizeof(szFiles);//���������ֽ���
		var->nFilterIndex = NULL;
		var->lpstrFileTitle = szTitle;
		//ָ�����ѡ����ļ����ļ�������չ���Ļ���(����·����Ϣ)�������Ա������NULL��
		if (funtype == 1)
		{
			var->lpstrTitle = L"ѡȡ�����ļ�";
			var->lpstrFilter = L"�����ļ�(*.mp3,*.wav)\0*.mp3;*.wav\0�����ļ�(*.*)\0*.*\0\0";
			var->Flags =
				OFN_PATHMUSTEXIST | //ֻ�����������·��
				OFN_FILEMUSTEXIST | //ֻ������������ļ�
				OFN_EXPLORER | 		//ʹ��Explorer����Ĭ�϶Ի�����Ӵ�����Ϊָ��ģ��������һ���Ի���
				OFN_NOCHANGEDIR | 	//���仯��ǰ·�����Է�ֹӰ���ļ�����
				OFN_ALLOWMULTISELECT;	//�����ѡ
		}
		else if (funtype == 2)
		{
			var->lpstrTitle = L"ѡȡ�赥�ļ�";
			var->lpstrFilter = L"�赥�ļ�(*.txt,*.slist)\0*.txt;*.slist\0�����ļ�(*.*)\0*.*\0\0";
			var->Flags =
				OFN_PATHMUSTEXIST | //ֻ�����������·��
				OFN_FILEMUSTEXIST | //ֻ������������ļ�
				OFN_EXPLORER | 		//ʹ��Explorer����Ĭ�϶Ի�����Ӵ�����Ϊָ��ģ��������һ���Ի���
				OFN_NOCHANGEDIR; 	//���仯��ǰ·�����Է�ֹӰ���ļ�����;
		}
		else if (funtype == 3)
		{
			var->lpstrTitle = L"����赥�ļ�";
			var->lpstrFilter = L"�赥�ļ�(*.txt,*.slist)\0*.txt;*.slist\0\0";
			var->Flags =
				OFN_PATHMUSTEXIST | //ֻ�����������·��
				OFN_FILEMUSTEXIST | //ֻ������������ļ�
				OFN_EXPLORER | 		//ʹ��Explorer����Ĭ�϶Ի�����Ӵ�����Ϊָ��ģ��������һ���Ի���
				OFN_NOCHANGEDIR; 	//���仯��ǰ·�����Է�ֹӰ���ļ�����;
		}
		if (funtype == 3 ? GetSaveFileName(var) : GetOpenFileName(var)) {
			lstrcpyn(szPath, szFiles, var->nFileOffset);
			//�ѵ�һ���ļ���ǰ�ĸ��Ƶ�szPath,��:
			 //���ֻѡ��һ���ļ�,�͸��Ƶ����һ��'/'
			//���ѡ�˶���ļ�,�͸��Ƶ���һ��NULL�ַ�
			szPath[var->nFileOffset] = L'\0';//����ַ���,���·���Ļ�ȡ
			lstrcpy(szFilePath, szPath);//��·�������ļ�·����׼����ȡ�����ļ�·��
			lstrcat(szFilePath, TEXT("\\"));//������һ��\��
			p = szFiles + var->nFileOffset;//��ָ���Ƶ���һ���ļ�
			while (*p) {//ֻҪû��ָ��\0��Ҳ����˵�����ļ���
				szFilePath[var->nFileOffset] = L'\0';//����ַ���,׼������
				lstrcpy(szTitle, p);//��ȡ���ļ����ļ���
				lstrcat(szFilePath, szTitle);//����ļ�����·��
				//�˴�Ӧ���жԻ�ú���ļ������ļ�����·���ĸ��ֲ���
				if (funtype == 1)
				{
					SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)szTitle);
					ListInsert_Sq(SongList, ListLength_Sq(SongList) + 1, TCHAR2STRING(szFilePath));
				}
				else if (funtype == 2)
				{
					string songName;
					ifstream infile(szFilePath); // �������ļ�SongList.txt
					while (!infile.eof())
					{
						getline(infile, songName);
						songName = UTF8_To_string(songName);
						ListInsert_Sq(SongList, ListLength_Sq(SongList) + 1, songName);
						char* c = nullptr;                    //��ʼ��char*���ͣ�����ֵΪ��
						const char* constc = nullptr;         //��ʼ��const char*���ͣ�����ֵΪ��
						constc = songName.c_str();                 //string����תconst char*����
						c = const_cast<char*>(constc);

						const char* d = "\\";
						char* p1 = NULL, * p2 = NULL;
						p1 = strtok_s(c, d, &c);
						while (p1)
						{
							p2 = p1;
							p1 = strtok_s(NULL, d, &c);
						}
						WCHAR wc[MAX_PATH];
						//_stprintf_s(wc, MAX_PATH, _T("%S"), m_csFileName.c_str());//%S���ַ�
						_stprintf_s(wc, MAX_PATH, _T("%S"), p2);//%s���ַ�
						SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)wc);
					}
					// ��getline��infile�����ж�ȡ�����ļ����������뵽 ���������б�
					infile.close();
				}
				else if (funtype == 3)
				{
					string SongListName = TCHAR2STRING(szFilePath);
					string temp = TCHAR2STRING(szFilePath);
					char* c = nullptr;                    //��ʼ��char*���ͣ�����ֵΪ��
					const char* constc = nullptr;         //��ʼ��const char*���ͣ�����ֵΪ��
					constc = SongListName.c_str();                 //string����תconst char*����
					c = const_cast<char*>(constc);

					const char* d = "\\";
					char* p1 = NULL, * p2 = NULL;
					p1 = strtok_s(c, d, &c);
					while (p1)
					{
						p2 = p1;
						p1 = strtok_s(NULL, d, &c);
					}
					if (p2 != "txt" || p2 != "slist")
					{
						temp = temp + ".slist";
					}

					ofstream infile(temp);
					string songName;
					for (int i = 0; i < ListLength_Sq(SongList); i++)
					{
						GetElem_Sq(SongList, i + 1, songName);
						infile.write(songName.c_str(), songName.size());
						infile.write("\n", 1);
					}
					infile.close();
				}
				//MessageBox(NULL, szTitle, szFilePath, MB_OK);
				p += lstrlen(p) + 1;//������һ���ļ�
			}
		}
		delete var;
	}
	else
	{
		wstring PathDir;
		SelectDir(hwnd, PathDir);
		if (PathDir != L"")
		{
			SearchFolder(wstring2string(PathDir));
		}
	}
}




//����callback
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;

	switch (uMsg)//ͨ���ж���Ϣ������Ϣ��Ӧ
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case 1://�������
			GetMoreFile(hwnd, 1);
			break;
		case 2://����赥
			GetMoreFile(hwnd, 2);
			break;
		case 3://����赥
			GetMoreFile(hwnd, 3);
			break;
		case 4://����
			MessageBox(NULL, L"     Made by: Luis\n     2023 October ", L"About", MB_OK | MB_ICONINFORMATION);
			break;
		case 5://����
			MessageBox(NULL, L"     �˵��� (��) �ɵ��������ļ�\n     �˵��� (����) �ɱ���赥\n     ˫�������������л�����Ӧ��Ŀ\n     ���������϶�\n\n     (��֪��Ϊʲôwavû�취������", L"Help", MB_OK | MB_ICONINFORMATION);
			break;
		case 6://���ļ���
			GetMoreFile(hwnd, 4);
			break;
		case 80://��ʼ��ť
			if (!IsPlay && ListLength_Sq(SongList)!=0)
			{
				IsPlay = true;
				CreateThread(NULL, 0, &(MusicPlayer), NULL, 0, NULL);
			}
			else if (IsPause)
			{
				IsPause = false;
			}
			break;
		case 81://��ͣ��ť
			if (IsPlay && !IsPause)
			{
				IsPause = true;
			}
			break;
		case 82://�и谴ť
			if (IsPlay)
			{
				IsChange = true;
			}
			break;
		case 83://��һ�װ�ť
			if (IsPlay)
			{
				if (PlayIndex == 0)
				{
					PlayIndex = ListLength_Sq(SongList)-2;
				}
				else
				{
					PlayIndex -= 2;
				}
				IsChange = true;
			}
			break;
		case 84://�и谴ť
			PlayMode++;
			if (PlayMode == 3)
			{
				PlayMode = 0;
			}
			switch (PlayMode)
			{
			case 0:
				SetWindowText(ModeLable, L"��ǰģʽ: ˳�򲥷�");
				break;
			case 1:
				SetWindowText(ModeLable, L"��ǰģʽ: �������");
				break;
			case 2:
				SetWindowText(ModeLable, L"��ǰģʽ: ����ѭ��");
				break;
			}
			break;
		case 85://������ť
			if (IsVolumBarShow)
			{
				ShowWindow(VolumBar, SW_HIDE);
				ShowWindow(VolumLable, SW_HIDE);
			}
			else
			{
				ShowWindow(VolumBar, SW_SHOW);
				ShowWindow(VolumLable, SW_SHOW);
			}
			IsVolumBarShow = !IsVolumBarShow;
			break;
		case 111://�б��
			if (HIWORD(wParam) == LBN_DBLCLK)
			{
				PlayIndex = SendMessage(hListBox, LB_GETCURSEL, 0, 0)-1;
				IsChange = true;
			}
			break;
		}
	case  WM_CTLCOLORSTATIC:
	{
		HDC   hdc = (HDC)wParam;
		HWND hStatic = (HWND)lParam;
		SetBkMode(hdc, TRANSPARENT);
		return  (LRESULT)CreateSolidBrush(RGB(255, 255, 255)); 
	}
	case WM_HSCROLL://������
		switch (LOWORD(wParam))
		{
		case SB_THUMBPOSITION:
			SetScrollPos(RollBar, SB_CTL, int(HIWORD(wParam)), true);
			SetTime = HIWORD(wParam)*1000;
			IsTimeSet = true;
			break;
		}
		break;
	case WM_VSCROLL://������
		switch (LOWORD(wParam))
		{
		case SB_THUMBPOSITION:
			SetScrollPos(VolumBar, SB_CTL, int(HIWORD(wParam)), true);
			SetWindowText(VolumLable, to_wstring(100 - HIWORD(wParam)).c_str());
			Volum = 100 - HIWORD(wParam);
			IsVolumChange = true;
			break;
		}
		break;
	case WM_PAINT:
		BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);//���ٴ��ڲ�����WM_DESTROY��Ϣ�����ǳ���û���˳�
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//����WM_QUIT��Ϣ��������Ϣѭ��
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);//�Բ�����Ȥ����Ϣ����ȱʡ���������иô��룬�������������
	}
	return 0;
}

//�����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	setlocale(LC_ALL, "chs");
	time_t ctime;
	time(&ctime);
	srand(ctime);
	

	MyIconExtract();
	HICON hIcon = ExtractIcon(GetModuleHandle(NULL), L"LuisIcon.ico", 0);
	remove("LuisIcon.ico");

	WNDCLASS wndcls; //����һ��������
	wndcls.cbClsExtra = 0;//��Ķ����ڴ棬Ĭ��Ϊ0����
	wndcls.cbWndExtra = 0;//���ڵĶ����ڴ棬Ĭ��Ϊ0����
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��ȡ��ˢ����������ص�HGDIOBJ����ǿ������ת����
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);//���ù��
	wndcls.hIcon = hIcon;
	wndcls.hInstance = hInstance;//���ô���������Ӧ�ó���ʵ��
	wndcls.lpfnWndProc = WinSunProc;//���ô���Ļص���������ʱûд��������ΪNULL�����油��
	wndcls.lpszClassName = L"Luis'sMusicPlayer";//���ô��������
	wndcls.lpszMenuName = NULL;//���ô���Ĳ˵�,û�У���NULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//���ô�����Ϊˮƽ�ػ��ʹ�ֱ�ػ�
	RegisterClass(&wndcls);//�����ϵͳע�ᴰ��
	

	//����һ�����壬�����ظô���ľ������һ����������ΪҪ�����Ĵ�����������ڶ�������Ϊ���������
	hwnd = CreateWindow(L"Luis'sMusicPlayer", L"MusicPlayer", WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION, 500,
		300, 1000, 700, NULL, NULL, hInstance, NULL);

	//�����б��ؼ�
	hListBox = CreateWindow(L"listBOX", L"XXX", WS_CHILD | WS_VSCROLL | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
		705, 75, 250, 520, hwnd, (HMENU)111, GetModuleHandle(NULL), NULL);
	
	HWND PlayButton = CreateWindow(L"BUTTON", L"����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		250, 550, 80, 40, hwnd, (HMENU)80, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND PauseButton = CreateWindow(L"BUTTON", L"��ͣ", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		360, 550, 80, 40, hwnd, (HMENU)81, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND NextButton = CreateWindow(L"BUTTON", L"��һ��", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		130, 550, 70, 40, hwnd, (HMENU)82, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND LastButton = CreateWindow(L"BUTTON", L"��һ��", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		60, 550, 70, 40, hwnd, (HMENU)83, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND ModeButton = CreateWindow(L"BUTTON", L"ģʽ", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		490, 550, 60, 40, hwnd, (HMENU)84, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND VolumButton = CreateWindow(L"BUTTON", L"����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		590, 550, 60, 40, hwnd, (HMENU)85, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	

	RollBar = CreateWindow(L"SCROLLBAR", L"", WS_CHILD | WS_VISIBLE | SBS_HORZ,
		50, 500, 600, 20, hwnd, (HMENU)NULL, hInstance, NULL);
	VolumBar = CreateWindow(L"SCROLLBAR", L"", WS_CHILD | SBS_VERT,
		670, 450, 15, 140, hwnd, (HMENU)NULL, hInstance, NULL);
	SetScrollRange(VolumBar, SB_CTL, 0, 100, false);
	

	Lable = CreateWindowW(L"STATIC", L"���� (����) ��ʼ����...\n\n(����׼�������ר������ĵ������˺þö�û�ҵ����õ�������ķ���", WS_CHILD | WS_VISIBLE | SS_CENTER,
		100, 250, 500, 200, hwnd, (HMENU)100, hInstance, NULL);
	HWND PlayListLable = CreateWindow(L"STATIC", L"�����б�", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER,
		705, 40, 250, 35, hwnd, (HMENU)101, hInstance, NULL);
	TimeLable = CreateWindow(L"STATIC", L"00:00/00:00", WS_CHILD | WS_VISIBLE | SS_CENTER,
		200, 470, 300, 20, hwnd, (HMENU)102, hInstance, NULL);
	ModeLable = CreateWindow(L"STATIC", L"��ǰģʽ: ˳�򲥷�", WS_CHILD | WS_VISIBLE | SS_CENTER,
		500, 470, 150, 20, hwnd, (HMENU)103, hInstance, NULL);
	VolumLable = CreateWindow(L"STATIC", L"100", WS_CHILD | SS_CENTER,
		657, 600, 40, 20, hwnd, (HMENU)104, hInstance, NULL);
	
	
	
	
	ShowWindow(hwnd, SW_SHOWNORMAL);//�Ѵ�����ʾ����
	UpdateWindow(hwnd);//���´���


	HMENU mymenu1 = CreateMenu();
	HMENU mymenu0 = CreateMenu();

	AppendMenu(mymenu1, 0, 1, L"�򿪸����ļ�");
	AppendMenu(mymenu1, 0, 6, L"���ļ���");
	AppendMenu(mymenu1, 0, 2, L"����赥�ļ�");
	AppendMenu(mymenu0, MF_POPUP, (UINT)mymenu1, _T("��&(O)"));
	AppendMenu(mymenu0, 0, 3, _T("����&(S)"));
	AppendMenu(mymenu0, 0, 4, _T("����&(A)"));
	AppendMenu(mymenu0, 0, 5, _T("����&(H)"));
	SetMenu(hwnd, mymenu0);
	DrawMenuBar(hwnd);
	

	InitList_Sq(SongList);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))//�����Ϣ����WM_QUIT,���ط���ֵ�������Ϣ��WM_QUIT��������
	{
		TranslateMessage(&msg);//������Ϣ�����WM_KEYDOWN��WM_KEYUP�����һ��WM_CHAR��Ϣ
		DispatchMessage(&msg);//�ɷ���Ϣ
	}

	DestroyList_Sq(SongList);
	DestroyIcon(hIcon);
}

