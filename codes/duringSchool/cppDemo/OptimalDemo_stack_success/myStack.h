#include "stackNode.h"
//·���ĳ���������?
//#define L 100
class MyStack1
{//��ջ��20070314���Կ���
	public:
		MyStack1(int l);
		MyStack1();
		MyStack1(MyStack1 &source);
		~MyStack1();
		//����ջ��Ԫ�� 
		void pop();
		//ѹ��ջ��Ԫ�� 
		void push(StackNode &top);
		//��ȡջ��Ԫ�� 
		StackNode getTop();
		/*���������*/
		MyStack1& operator=(MyStack1 &opnd2);
		//��ջ������ָ��
		StackNode *s;
		//ָ���ջ��ջ��Ԫ��
		int top;
		//��ջ�ĳ���
		int length;
		/*�����д������
		û��seter,geter,
		û��getLength,setEmpty
		û�����·����ջ����
		*/
};
