#include <iostream>
using namespace std;
//�Զ��������ռ����ֿռ����������main��������ͳ����˴���
namespace first
{
	char name = '1';
}
namespace second
{
	char name = '2';
}
char name = '3';
void main()
{	
	cout<<name<<endl;//���û��char name = '3'�ᱨ��
	cout<<"��ʼ���������ռ�"<<endl;
	cout<<first::name<<endl;
	cout<<second::name<<endl;
	using namespace first;
	//cout<<name<<endl;//������ʾ���ֳ�ͻ����

	/*using namespace second;//����������
	cout<<name<<endl;//�������þͱ�����ֻ����������second*/
	cout<<second::name<<endl;
	cout<<endl;
}