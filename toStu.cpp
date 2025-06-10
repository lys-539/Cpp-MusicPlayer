#include <windows.h> 
#include <string>
#include <iostream>
#include <fstream>                 // ֧���ļ����ʵ����

#define OK 1
#define ERROR 0
#define ElemType string
typedef int Status;
#define LIST_INIT_SIZE 100      //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10          //���Ա�洢�ռ�ķ�������
#pragma comment(lib,"winmm.lib")
using namespace std;


typedef struct {
	ElemType* elem;       //�洢�ռ��ַ        
	int length;           //��ǰ����        
	int listsize;         //��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;


Status InitList_Sq(SqList& L)
{  // ����һ���յ����Ա�L(�㷨2.3)
	//  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	L.elem = new ElemType[LIST_INIT_SIZE];
	if (!L.elem) return OK;        // �洢����ʧ��
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
//        free(L.elem);
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


void mp3player(string s)
{ //���Ÿ�����mp3player������sΪ�����ļ�������ȫ��·����Ϣ��
	string flag;
	MCI_OPEN_PARMS op;
	op.lpstrDeviceType = "mpegvideo";
	op.lpstrElementName = s.c_str();
	UINT rs;
	rs = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD_PTR)&op);
	
	if (rs != 0)
	{
		cout << "�޷���" << s << endl;
	}
	else
	{
		cout << "��������" << s << endl;
		MCI_PLAY_PARMS pp;
		mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_WAIT, (DWORD_PTR)&pp);
	}
	MCI_GENERIC_PARMS gp;
	mciSendCommand(op.wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD_PTR)&gp);
}


int main()
{
	string songName = "C:\\WINDOWS\\Media\\notify.wav";      // Ҳ�ɲ���mp3�ļ�
	mp3player(songName);
	songName = "C:\\WINDOWS\\Media\\tada.wav";      
	mp3player(songName);

	// ���� ���������б�
	// ��ʼ�� ���������б�
	// ��ȡmp3�ļ��嵥���� SongList.txt �� ��ǰ������ SongList.txt
	ifstream infile("SongList.txt");      // �������ļ�SongList.txt
	// ��getline��infile�����ж�ȡ�����ļ����������뵽 ���������б�
	infile.close();
	// �������� ���������б���һ�������и���
	// ���� ���������б�
	return 0;
}

