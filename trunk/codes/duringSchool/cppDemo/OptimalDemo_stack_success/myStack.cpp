#include "myStack.h"
MyStack1::MyStack1()
{
	/**/s = NULL;
	length = 0;
	top = -1;
}
MyStack1::MyStack1(int l)
{//������ຬ��l��Ԫ�ص�ָ��
/**/
	length = l;
	s = new StackNode[length];
	top = -1;
}
MyStack1::MyStack1(MyStack1 &source)
{
	cout<<"copy!"<<endl;//lkdebug
	s = NULL;
	length = source.length;
	top = -1;
	s = new StackNode[length];
	while(top < source.top)
	{
		top++;
		s[top] = source.s[top];
	}
}
MyStack1::~MyStack1()
{
/**/delete []s;
	s = NULL;
	top = -1;
	length = 0;
}
void MyStack1::pop()
{
/**/	if(top >= 0)
	{
		top --;		
	}
	else
	{
		cout<<"ջ�գ��޷���ջ��"<<endl;
	}
}
void MyStack1::push(StackNode &top)
{
/**/
	if(this->top < length - 1)
	{
		s[++(this->top)] = top;//����ֱ�Ӷ���ֵ�� 
	}
	else
	{
		cout<<"ջ��!"<<endl;
	}
}
StackNode MyStack1::getTop()
{
	if(top >= 0)
		return s[top];
	else
		cout<<"ջ�գ�"<<endl;
} 
MyStack1& MyStack1::operator=(MyStack1 &opnd2)
{
	this->length = opnd2.length;
	delete []s;
	s = NULL;
	top = -1;
	s = new StackNode[length];
	//cout<<"length"<<length<<endl;//lkdebug
	while(top < opnd2.top)
	{
		
		cout<<"good"<<endl;
		top++;
		s[top] = opnd2.s[top];
	}
	//cout<<"operator="<<top<<endl;//lkdebug
	return *this;//copydestructor��newҲ��
}