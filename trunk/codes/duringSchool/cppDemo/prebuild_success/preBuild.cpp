#include<iostream.h>
//�궨�忪�ؿ��Ըı䣬���ڵ���
#define DEBUGPREBUILD 1

void main()
{
	cout<<"��ʼ���ԣ�"<<endl;
#if	DEBUGPREBUILD ==1
	cout<<"���������ú궨��DEBUGPREBULDΪ1��ʱ��"<<endl;
#else
	cout<<"���������ú궨��DEBUGPREBULD��Ϊ1��ʱ��"<<endl;
#endif
	cout<<"�ܻ�ִ�е�����"<<endl;
}