#include"myList.h"
MyList::MyList()
{
	length = 0;
	first = NULL;
	//last = 0;
}
MyList::~MyList()
{
	while(first != NULL)
	{
		delete first;
		//first = first->next;
	}
}
void MyList::add(int& node)
{
	MyListNode *p = new MyListNode;
	p->element = node;
	p->next = first;
	first = p;
	length = length + 1;
}
//void MyList::removeLast()
//{
//}
void MyList::removeFirst()
{
	if(first != NULL)
	{
	MyListNode* p = first;
	first = first->next;
	cout<<"ɾ��"<<p->element<<endl;
	delete p;
	length = length - 1;
	}
	else
	{
		cout<<"����Ϊ�գ�����ɾ��!"<<endl;
	}
}