/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///                                                           ///
///                   ！！！老师看我！！！                    ///
///                                                           ///
///          代码大量报错的话要把项目字符集设置为             ///
///                        UNICODE                            ///
///                      才能正常运行                         ///
///                                                           ///
///                   ！！！老师看我！！！                    ///
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
#include <fstream>                 // 支持文件访问的类库

#define OK 1
#define ERROR 0
#define ElemType string
typedef int Status;
#define LIST_INIT_SIZE 10000     //线性表存储空间的初始分配量
#define LISTINCREMENT 10          //线性表存储空间的分配增量
#pragma comment(lib,"winmm.lib")
using namespace std;

#pragma comment(linker, "/subsystem:windows")

//内嵌图标数据
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

//各种字符串格式转换(好像是有重复的
string UTF8_To_string(const string& str)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴
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
	//获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的  
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	//宽字节编码转换成多字节编码  
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}
wstring string2wstring(string str)
{
	wstring result;
	//获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//多字节编码转换成宽字节编码  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //添加字符串结尾  
	//删除缓冲区并返回值  
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

//几乎没改过的实例代码
typedef struct {
	ElemType* elem;       //存储空间基址        
	int length;           //当前长度        
	int listsize;         //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;
Status InitList_Sq(SqList& L)
{  // 构造一个空的线性表L(算法2.3)
	//  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	L.elem = new ElemType[LIST_INIT_SIZE];
	if (!L.elem) return ERROR;        // 存储分配失败
	L.length = 0;                  // 空表长度为0
	L.listsize = LIST_INIT_SIZE;   // 初始存储容量
	return OK;
} // InitList_Sq
Status ListInsert_Sq(SqList& L, int i, ElemType e)
{  // 在顺序线性表L的第i个元素之前插入新的元素e(算法2.4)
   // i的合法值为1≤i≤ListLength_Sq(L)+1
	if (i < 1 || i > L.length + 1) return ERROR;  // i值不合法
	if (L.length >= L.listsize) return ERROR;  // 当前存储空间已满
	for (int j = L.length; j > i; j--)      // Shift Elems up
		L.elem[j] = L.elem[j - 1];       //   to make room

	L.elem[i - 1] = e;

	++L.length;   // 表长增1
	return OK;
} // ListInsert_Sq
Status DestroyList_Sq(SqList& L)
{ //销毁线性表L
	delete[] L.elem;
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestroyList_Sq()
int ListLength_Sq(SqList L)
{ //返回线性表的长度
	return L.length;
}//ListLength_Sq()
Status GetElem_Sq(SqList L, int i, ElemType& e)
{ //用e返回L中第i个元素的值
	e = *(L.elem + i - 1);
	return OK;
}//GetElem_Sq()
MCI_OPEN_PARMS op;

//大修过的mci通信
bool mp3player(string s, bool setflag, int start_time, int end_time)
{ //播放歌曲的mp3player函数，s为歌曲文件名（含全部路径信息）
	string flag;

	int length = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, 0);
	wchar_t aa[1000];
	wchar_t* wideString = aa;
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, wideString, length);

	op.lpstrElementName = wideString;

	char* c = nullptr;                    //初始化char*类型，并赋值为空
	const char* constc = nullptr;         //初始化const char*类型，并赋值为空
	constc = s.c_str();                 //string类型转const char*类型
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
		MessageBox(NULL, L"无法打开文件, 将于 3s 后播放下一首", L"WARN", MB_OK | MB_ICONINFORMATION);
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


//一些全局变量
SqList SongList;
bool Playflag = true, IsPlay = false, IsPause = false, IsChange = false, IsTimeSet = false, IsVolumBarShow = false, IsVolumChange = false;
int PlayIndex = 0, SetTime, PlayMode = 0, Volum = 0;
HWND hwnd, Lable, hListBox, RollBar, TimeLable, ModeLable, VolumBar, VolumLable;

void SearchFolder(string PathDir);
//遍历文件夹本体
void DfsListFolderFiles(string path, string FileType, bool IsDir)
{
	_finddata_t file_info;
	string current_path = path + "\\" + FileType;
	intptr_t handle = _findfirst(current_path.c_str(), &file_info);
	//返回值为-1则查找失败  
	if (-1 == handle)
	{
		//MessageBox(NULL, L"     文件夹导入失败!", L"Err", MB_OK | MB_ICONEXCLAMATION);
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
	//关闭文件句柄  
	_findclose(handle);
}

//遍历文件夹入口
void SearchFolder(string PathDir)
{
	DfsListFolderFiles(PathDir, "*.mp3", false);
	DfsListFolderFiles(PathDir, "*.wav", false);
	DfsListFolderFiles(PathDir, "*.*", true);
}

//[打开文件夹] 栏
BOOL SelectDir(HWND hWnd, wstring& strPath)
{
	BROWSEINFO bifolder;
	wchar_t FileName[MAX_PATH];
	ZeroMemory(&bifolder, sizeof(BROWSEINFO));
	bifolder.hwndOwner = hWnd;				// 拥有者句柄
	bifolder.pszDisplayName = FileName;		// 存放目录路径缓冲区
	bifolder.lpszTitle = TEXT("请选择文件夹");	// 标题
	bifolder.ulFlags = BIF_USENEWUI; // 新的样式,带编辑框

	LPITEMIDLIST idl = SHBrowseForFolder(&bifolder);
	if (idl == NULL)
	{
		return FALSE;
	}

	SHGetPathFromIDList(idl, FileName);
	strPath = FileName;
	return TRUE;
}

//音乐播放线程
DWORD WINAPI MusicPlayer(LPVOID arg)
{
	string songName, Lyrics;
	bool Checkflag, timesetflag = false, Lyrics_flag;
	int start_time = 0, end_time = 0, Lyric_time = 0;

	while (Playflag)
	{
		Lyrics = "未找到歌词";
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
			wstring s11 = L"正在播放: ";
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
					MCI_DGV_SETAUDIO_PARMS  mciSetAudioPara;  //这个结构体需要包含<digitalv.h> 
					mciSetAudioPara.dwCallback = NULL;  //回调函数置空
					mciSetAudioPara.dwItem = MCI_DGV_SETAUDIO_VOLUME;  //选项为设置音量项
					mciSetAudioPara.dwValue = (DWORD)Volum;   //此处就是具体音量大小 (0--1000) 
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


//[打开] [另存为] 栏
void GetMoreFile(HWND hwnd, int funtype) {
	if (funtype != 4)
	{
		TCHAR szPath[MAX_PATH]{ 0 };//存储当前文件所在路径（不含文件）
		TCHAR szTitle[MAX_PATH]{ 0 };//存储当前文件名
		TCHAR szFilePath[MAX_PATH]{ 0 };//存储当前文件路径
		TCHAR szFiles[256 * MAX_PATH]{ 0 };//可以存放至少80个文件的路径,即存储所有获得文件
		TCHAR* p;
		LPOPENFILENAME var = new OPENFILENAMEW;

		ZeroMemory(var, sizeof(OPENFILENAMEW));
		var->hwndOwner = hwnd;
		//指向所有者对话框窗口的句柄。这个成员可以是任意有效窗口句柄，或如果对话框没有所有者它可以为NULL。
		var->lStructSize = sizeof(OPENFILENAMEW);
		var->lpstrInitialDir = L".\\";//默认的初始文件路径
		var->lpstrFile = szFiles;//存放将要获取的所有文件的缓冲区
		var->nMaxFile = sizeof(szFiles);//缓冲区的字节数
		var->nFilterIndex = NULL;
		var->lpstrFileTitle = szTitle;
		//指向接收选择的文件的文件名和扩展名的缓冲(不带路径信息)。这个成员可以是NULL。
		if (funtype == 1)
		{
			var->lpstrTitle = L"选取音乐文件";
			var->lpstrFilter = L"音乐文件(*.mp3,*.wav)\0*.mp3;*.wav\0所有文件(*.*)\0*.*\0\0";
			var->Flags =
				OFN_PATHMUSTEXIST | //只允许输入存在路径
				OFN_FILEMUSTEXIST | //只允许输入存在文件
				OFN_EXPLORER | 		//使用Explorer风格的默认对话框的子窗口作为指定模板来建立一个对话框
				OFN_NOCHANGEDIR | 	//不变化当前路径，以防止影响文件操作
				OFN_ALLOWMULTISELECT;	//允许多选
		}
		else if (funtype == 2)
		{
			var->lpstrTitle = L"选取歌单文件";
			var->lpstrFilter = L"歌单文件(*.txt,*.slist)\0*.txt;*.slist\0所有文件(*.*)\0*.*\0\0";
			var->Flags =
				OFN_PATHMUSTEXIST | //只允许输入存在路径
				OFN_FILEMUSTEXIST | //只允许输入存在文件
				OFN_EXPLORER | 		//使用Explorer风格的默认对话框的子窗口作为指定模板来建立一个对话框
				OFN_NOCHANGEDIR; 	//不变化当前路径，以防止影响文件操作;
		}
		else if (funtype == 3)
		{
			var->lpstrTitle = L"保存歌单文件";
			var->lpstrFilter = L"歌单文件(*.txt,*.slist)\0*.txt;*.slist\0\0";
			var->Flags =
				OFN_PATHMUSTEXIST | //只允许输入存在路径
				OFN_FILEMUSTEXIST | //只允许输入存在文件
				OFN_EXPLORER | 		//使用Explorer风格的默认对话框的子窗口作为指定模板来建立一个对话框
				OFN_NOCHANGEDIR; 	//不变化当前路径，以防止影响文件操作;
		}
		if (funtype == 3 ? GetSaveFileName(var) : GetOpenFileName(var)) {
			lstrcpyn(szPath, szFiles, var->nFileOffset);
			//把第一个文件名前的复制到szPath,即:
			 //如果只选了一个文件,就复制到最后一个'/'
			//如果选了多个文件,就复制到第一个NULL字符
			szPath[var->nFileOffset] = L'\0';//封好字符串,完成路径的获取
			lstrcpy(szFilePath, szPath);//将路径给予文件路径以准备获取完整文件路径
			lstrcat(szFilePath, TEXT("\\"));//附加上一个\号
			p = szFiles + var->nFileOffset;//把指针移到第一个文件
			while (*p) {//只要没有指向\0，也就是说还有文件名
				szFilePath[var->nFileOffset] = L'\0';//封好字符串,准备连接
				lstrcpy(szTitle, p);//获取该文件的文件名
				lstrcat(szFilePath, szTitle);//获得文件完整路径
				//此处应该有对获得后的文件名和文件完整路径的各种操作
				if (funtype == 1)
				{
					SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)szTitle);
					ListInsert_Sq(SongList, ListLength_Sq(SongList) + 1, TCHAR2STRING(szFilePath));
				}
				else if (funtype == 2)
				{
					string songName;
					ifstream infile(szFilePath); // 打开曲单文件SongList.txt
					while (!infile.eof())
					{
						getline(infile, songName);
						songName = UTF8_To_string(songName);
						ListInsert_Sq(SongList, ListLength_Sq(SongList) + 1, songName);
						char* c = nullptr;                    //初始化char*类型，并赋值为空
						const char* constc = nullptr;         //初始化const char*类型，并赋值为空
						constc = songName.c_str();                 //string类型转const char*类型
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
						//_stprintf_s(wc, MAX_PATH, _T("%S"), m_csFileName.c_str());//%S宽字符
						_stprintf_s(wc, MAX_PATH, _T("%S"), p2);//%s单字符
						SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)wc);
					}
					// 用getline从infile中逐行读取歌曲文件名，并插入到 歌曲播放列表
					infile.close();
				}
				else if (funtype == 3)
				{
					string SongListName = TCHAR2STRING(szFilePath);
					string temp = TCHAR2STRING(szFilePath);
					char* c = nullptr;                    //初始化char*类型，并赋值为空
					const char* constc = nullptr;         //初始化const char*类型，并赋值为空
					constc = SongListName.c_str();                 //string类型转const char*类型
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
				p += lstrlen(p) + 1;//移至下一个文件
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




//窗体callback
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;

	switch (uMsg)//通过判断消息进行消息响应
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case 1://加入歌曲
			GetMoreFile(hwnd, 1);
			break;
		case 2://加入歌单
			GetMoreFile(hwnd, 2);
			break;
		case 3://保存歌单
			GetMoreFile(hwnd, 3);
			break;
		case 4://关于
			MessageBox(NULL, L"     Made by: Luis\n     2023 October ", L"About", MB_OK | MB_ICONINFORMATION);
			break;
		case 5://帮助
			MessageBox(NULL, L"     菜单栏 (打开) 可导入音乐文件\n     菜单栏 (保存) 可保存歌单\n     双击歌曲栏可以切换到相应曲目\n     进度栏可拖动\n\n     (不知道为什么wav没办法调音量", L"Help", MB_OK | MB_ICONINFORMATION);
			break;
		case 6://打开文件夹
			GetMoreFile(hwnd, 4);
			break;
		case 80://开始按钮
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
		case 81://暂停按钮
			if (IsPlay && !IsPause)
			{
				IsPause = true;
			}
			break;
		case 82://切歌按钮
			if (IsPlay)
			{
				IsChange = true;
			}
			break;
		case 83://上一首按钮
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
		case 84://切歌按钮
			PlayMode++;
			if (PlayMode == 3)
			{
				PlayMode = 0;
			}
			switch (PlayMode)
			{
			case 0:
				SetWindowText(ModeLable, L"当前模式: 顺序播放");
				break;
			case 1:
				SetWindowText(ModeLable, L"当前模式: 随机播放");
				break;
			case 2:
				SetWindowText(ModeLable, L"当前模式: 单曲循环");
				break;
			}
			break;
		case 85://音量按钮
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
		case 111://列表框
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
	case WM_HSCROLL://进度栏
		switch (LOWORD(wParam))
		{
		case SB_THUMBPOSITION:
			SetScrollPos(RollBar, SB_CTL, int(HIWORD(wParam)), true);
			SetTime = HIWORD(wParam)*1000;
			IsTimeSet = true;
			break;
		}
		break;
	case WM_VSCROLL://音量栏
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
		DestroyWindow(hwnd);//销毁窗口并发送WM_DESTROY消息，但是程序没有退出
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//发出WM_QUIT消息，结束消息循环
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);//对不感兴趣的消息进行缺省处理，必须有该代码，否则程序有问题
	}
	return 0;
}

//主入口
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	setlocale(LC_ALL, "chs");
	time_t ctime;
	time(&ctime);
	srand(ctime);
	

	MyIconExtract();
	HICON hIcon = ExtractIcon(GetModuleHandle(NULL), L"LuisIcon.ico", 0);
	remove("LuisIcon.ico");

	WNDCLASS wndcls; //创建一个窗体类
	wndcls.cbClsExtra = 0;//类的额外内存，默认为0即可
	wndcls.cbWndExtra = 0;//窗口的额外内存，默认为0即可
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//获取画刷句柄（将返回的HGDIOBJ进行强制类型转换）
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);//设置光标
	wndcls.hIcon = hIcon;
	wndcls.hInstance = hInstance;//设置窗体所属的应用程序实例
	wndcls.lpfnWndProc = WinSunProc;//设置窗体的回调函数，暂时没写，先设置为NULL，后面补上
	wndcls.lpszClassName = L"Luis'sMusicPlayer";//设置窗体的类名
	wndcls.lpszMenuName = NULL;//设置窗体的菜单,没有，填NULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//设置窗体风格为水平重画和垂直重画
	RegisterClass(&wndcls);//向操作系统注册窗体
	

	//产生一个窗体，并返回该窗体的句柄，第一个参数必须为要创建的窗体的类名，第二个参数为窗体标题名
	hwnd = CreateWindow(L"Luis'sMusicPlayer", L"MusicPlayer", WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION, 500,
		300, 1000, 700, NULL, NULL, hInstance, NULL);

	//创建列表框控件
	hListBox = CreateWindow(L"listBOX", L"XXX", WS_CHILD | WS_VSCROLL | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
		705, 75, 250, 520, hwnd, (HMENU)111, GetModuleHandle(NULL), NULL);
	
	HWND PlayButton = CreateWindow(L"BUTTON", L"播放", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		250, 550, 80, 40, hwnd, (HMENU)80, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND PauseButton = CreateWindow(L"BUTTON", L"暂停", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		360, 550, 80, 40, hwnd, (HMENU)81, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND NextButton = CreateWindow(L"BUTTON", L"下一首", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		130, 550, 70, 40, hwnd, (HMENU)82, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND LastButton = CreateWindow(L"BUTTON", L"上一首", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		60, 550, 70, 40, hwnd, (HMENU)83, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND ModeButton = CreateWindow(L"BUTTON", L"模式", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		490, 550, 60, 40, hwnd, (HMENU)84, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	HWND VolumButton = CreateWindow(L"BUTTON", L"音量", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		590, 550, 60, 40, hwnd, (HMENU)85, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
	

	RollBar = CreateWindow(L"SCROLLBAR", L"", WS_CHILD | WS_VISIBLE | SBS_HORZ,
		50, 500, 600, 20, hwnd, (HMENU)NULL, hInstance, NULL);
	VolumBar = CreateWindow(L"SCROLLBAR", L"", WS_CHILD | SBS_VERT,
		670, 450, 15, 140, hwnd, (HMENU)NULL, hInstance, NULL);
	SetScrollRange(VolumBar, SB_CTL, 0, 100, false);
	

	Lable = CreateWindowW(L"STATIC", L"按下 (播放) 开始播放...\n\n(本来准备在这放专辑封面的但是找了好久都没找到不用第三方库的方法", WS_CHILD | WS_VISIBLE | SS_CENTER,
		100, 250, 500, 200, hwnd, (HMENU)100, hInstance, NULL);
	HWND PlayListLable = CreateWindow(L"STATIC", L"播放列表", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER,
		705, 40, 250, 35, hwnd, (HMENU)101, hInstance, NULL);
	TimeLable = CreateWindow(L"STATIC", L"00:00/00:00", WS_CHILD | WS_VISIBLE | SS_CENTER,
		200, 470, 300, 20, hwnd, (HMENU)102, hInstance, NULL);
	ModeLable = CreateWindow(L"STATIC", L"当前模式: 顺序播放", WS_CHILD | WS_VISIBLE | SS_CENTER,
		500, 470, 150, 20, hwnd, (HMENU)103, hInstance, NULL);
	VolumLable = CreateWindow(L"STATIC", L"100", WS_CHILD | SS_CENTER,
		657, 600, 40, 20, hwnd, (HMENU)104, hInstance, NULL);
	
	
	
	
	ShowWindow(hwnd, SW_SHOWNORMAL);//把窗体显示出来
	UpdateWindow(hwnd);//更新窗体


	HMENU mymenu1 = CreateMenu();
	HMENU mymenu0 = CreateMenu();

	AppendMenu(mymenu1, 0, 1, L"打开歌曲文件");
	AppendMenu(mymenu1, 0, 6, L"打开文件夹");
	AppendMenu(mymenu1, 0, 2, L"导入歌单文件");
	AppendMenu(mymenu0, MF_POPUP, (UINT)mymenu1, _T("打开&(O)"));
	AppendMenu(mymenu0, 0, 3, _T("保存&(S)"));
	AppendMenu(mymenu0, 0, 4, _T("关于&(A)"));
	AppendMenu(mymenu0, 0, 5, _T("帮助&(H)"));
	SetMenu(hwnd, mymenu0);
	DrawMenuBar(hwnd);
	

	InitList_Sq(SongList);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))//如果消息不是WM_QUIT,返回非零值；如果消息是WM_QUIT，返回零
	{
		TranslateMessage(&msg);//翻译消息，如把WM_KEYDOWN和WM_KEYUP翻译成一个WM_CHAR消息
		DispatchMessage(&msg);//派发消息
	}

	DestroyList_Sq(SongList);
	DestroyIcon(hIcon);
}

