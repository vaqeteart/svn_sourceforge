#include<iostream.h>
void test()
{
	cout<<"��ʼ���Զ�̬��άָ��.."<<endl;
	int m;
	cout<<"������ά��:"<<endl;
	cin>>m;
	cout<<"��ʼ����"<<m<<"ά�Ķ�̬����"<<endl;
	//������ά����
	int **p;
	p = new int*[m];
	int i = 0;
	int j = 0;
	for(i = 0; i < m; i++)
	{
		p[i] = new int[m];
	}
	//���Դ���������
	int count = 0;
	for(i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			p[i][j] = count ++;
			cout<<p[i][j];
		}
	}
	//�ͷŶ�̬��ά����
	for(i = 0; i < m; i++)
	{
		delete[]p[i];
		p[i] = NULL;
	}
	delete []p;
	p = NULL;
	//�ͷ�֮��Ĳ���
}
void main()
{
	test();
}
