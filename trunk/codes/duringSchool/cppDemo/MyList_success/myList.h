#ifndef __myList_h__
#define __myList_h__
//#ifndef MYNODETYPE int
//#define MYNODETYPE int
//#endif
#include<iostream.h>
#include"myListNode.h"
class MyList
{
public:
	MyList();
	~MyList();
	void add(int& node);//��һ��Ԫ�ز��뵽��ͷ
//	void removeLast();
	void removeFirst();
	int length;//������
	MyListNode* first;//ָ���һ��Ԫ�ص�ָ�루�ڵ�����Ӧ�øı䣩
//	MyListNode* last;//ָ�����һ��Ԫ�ص�ָ��
	//MYNODETYPE num;//�ڵ����Ϳ��Ըı�
	//MYNODETYPE *next;
};
#endif