#include <windows.h> 
#include <string>
#include <iostream>
#include <fstream>                 // 支持文件访问的类库

#define OK 1
#define ERROR 0
#define ElemType string
typedef int Status;
#define LIST_INIT_SIZE 100      //线性表存储空间的初始分配量
#define LISTINCREMENT 10          //线性表存储空间的分配增量
#pragma comment(lib,"winmm.lib")
using namespace std;


typedef struct {
	ElemType* elem;       //存储空间基址        
	int length;           //当前长度        
	int listsize;         //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;


Status InitList_Sq(SqList& L)
{  // 构造一个空的线性表L(算法2.3)
	//  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	L.elem = new ElemType[LIST_INIT_SIZE];
	if (!L.elem) return OK;        // 存储分配失败
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
//        free(L.elem);
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


void mp3player(string s)
{ //播放歌曲的mp3player函数，s为歌曲文件名（含全部路径信息）
	string flag;
	MCI_OPEN_PARMS op;
	op.lpstrDeviceType = "mpegvideo";
	op.lpstrElementName = s.c_str();
	UINT rs;
	rs = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD_PTR)&op);
	
	if (rs != 0)
	{
		cout << "无法打开" << s << endl;
	}
	else
	{
		cout << "请听歌曲" << s << endl;
		MCI_PLAY_PARMS pp;
		mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_WAIT, (DWORD_PTR)&pp);
	}
	MCI_GENERIC_PARMS gp;
	mciSendCommand(op.wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD_PTR)&gp);
}


int main()
{
	string songName = "C:\\WINDOWS\\Media\\notify.wav";      // 也可播放mp3文件
	mp3player(songName);
	songName = "C:\\WINDOWS\\Media\\tada.wav";      
	mp3player(songName);

	// 定义 歌曲播放列表
	// 初始化 歌曲播放列表
	// 获取mp3文件清单放入 SongList.txt 或 提前创建好 SongList.txt
	ifstream infile("SongList.txt");      // 打开曲单文件SongList.txt
	// 用getline从infile中逐行读取歌曲文件名，并插入到 歌曲播放列表
	infile.close();
	// 遍历整个 歌曲播放列表，逐一播放所有歌曲
	// 销毁 歌曲播放列表
	return 0;
}

