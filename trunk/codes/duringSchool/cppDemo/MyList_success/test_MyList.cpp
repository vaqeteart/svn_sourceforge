#include<iostream.h>
#include"myList.h"
void main()
{
	cout<<"hello myList:"<<endl;
	MyList list;
	cout<<"����һ���������"<<endl;
	cout<<"ɾ��������Ԫ��"<<endl;
	list.removeFirst();
	int a = 1;
	cout<<"����Ԫ��1"<<endl;
	list.add(a);
	a = 2;
	cout<<"����Ԫ��2"<<endl;
	list.add(a);
	a = 3;
	cout<<"����Ԫ��3"<<endl;
	list.add(a);
	cout<<"���ȣ�"<<list.length<<endl;
	cout<<"��length��ͷ�쿴����Ԫ�ؽ������:"<<endl;
	MyListNode* p = list.first;
	for(int i = 0; i < list.length; i ++)
	{
		cout<<p->element<<',';
		p = p->next;
	}
	cout<<endl;
	cout<<"�����һ��Ԫ���Ƿ�Ϊ�մ�ͷ�쿴����Ԫ�ؽ������:"<<endl;
	for(p = list.first; p != NULL; p = p->next)
	{		
		cout<<p->element<<',';
	}
	cout<<endl;
	cout<<"��ʼȥ����Ԫ��"<<endl;
	list.removeFirst();
	cout<<"���ȣ�"<<list.length<<endl;
	cout<<"��ʼȥ������Ԫ��"<<endl;
	//for(int j = 0; j < list.length; j ++)//ע��lengthҲ�Ƕ�̬�仯��
	while(list.length != 0)
	{
		list.removeFirst();
	}
	cout<<"���ȣ�"<<list.length<<endl;
	cout<<"��ɾ��������Ԫ��"<<endl;
	list.removeFirst();
	cout<<"�������!"<<endl;
}