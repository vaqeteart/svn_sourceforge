#include<iostream>
#include"myStack.h"
void main()
{
	//�Զ�ջ�Ĳ���
	cout<<"start to test the stack:"<<endl;
	StackNode node[5];
	for(int i = 0;i < 5; i ++)
	{
		node[i].vertex.num = i;
	}
	for(int j = 0; j < 5; j++)
	{
		cout<<"��"<<j<<"����:"<<node[j].vertex.num<<endl;
	}
	//node[3] = node[4];
	//cout<<node[3].vertex.num;
	//	node[3].vertex.num = 8;
	//	cout<<node[4].vertex.num;//û��java���õ�����
	
	
	cout<<"����5���ڵ�Ķ�ջstack1"<<endl;
	MyStack1 stack1(5);
	cout<<"stack1 top�ĳ�ʼֵΪ��"<<stack1.top<<endl;
	cout<<"ѹ��ڵ��4"<<endl;
	stack1.push(node[4]);
	cout<<"top��ֵΪ��"<<stack1.top<<endl;
	cout<<"ѹ��ڵ��3"<<endl;
	stack1.push(node[3]);
	cout<<"top��ֵΪ��"<<stack1.top<<endl;
	cout<<"��ȡջ��Ԫ�أ�"<<endl;
	StackNode tmpnode = stack1.getTop();
	cout<<tmpnode.vertex.num<<endl;
	cout<<"��ջ"<<endl;
	stack1.pop();
	cout<<"top��ֵΪ��"<<stack1.top<<endl;
	cout<<"��ȡջ��Ԫ�أ�"<<endl;
	tmpnode = stack1.getTop();
	cout<<tmpnode.vertex.num<<endl;

	//[lkdebug
	cout<<stack1.top;
	//lkdebug]
	cout<<"����4���ڵ�Ķ�ջstack2"<<endl;
	MyStack1 stack2(4);
	cout<<"ѹ��ڵ��1"<<endl;
	stack2.push(node[1]);
	cout<<"stack2 top��ֵΪ��"<<stack2.top<<endl;
	cout<<"ѹ��ڵ��2"<<endl;
	stack2.push(node[2]);
	cout<<"top��ֵΪ��"<<stack2.top<<endl;
	cout<<"��ȡջ��Ԫ�أ�"<<endl;
	tmpnode = stack2.getTop();
	cout<<tmpnode.vertex.num<<endl;
	

	cout<<"��stack1���Ƶ�stack2�У�"<<endl;
	stack2 = stack1;
	cout<<"��ȡջ��Ԫ�أ�"<<endl;
	StackNode tmpnode2 = stack2.getTop();
	cout<<tmpnode2.vertex.num<<endl;


	cout<<"stack test over!success!!"<<endl;
	cout<<endl;
	
}