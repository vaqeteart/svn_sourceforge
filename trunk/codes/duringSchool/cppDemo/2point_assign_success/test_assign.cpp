#include<iostream>
using namespace std;
int main()
{
	//����ָ��
	int** p1 = NULL;
	//int p1[][5];
	int** p2 = NULL;
	//int p2[][5];
	int n = 5;
	//����ռ�
	p1 = new int*[n];
	int i = 0;
	for(i = 0; i < n; i++)
	{
		p1[i] = new int[n];//�˴������Ƿ����ŷ���Խ��
	}
	for(i = 0; i < n; i++)
	{
		register int j = 0;
		for(j = 0; j < n; j++)
		{
			p1[i][j] = i*n + j;
			cout<<p1[i][j]<<',';
		}
	}
	//ָ�븳ֵ
	p2 = p1;
	/*for(i = 0; i < n; i++)
	{
		p2[i] = p1[i];
	}
	for(i = 0; i < n; i++)
	{
		cout<<p1[i]<<':';
		cout<<p2[i]<<',';
	}*/
	//cout<<**p2;
	//����ָ��
	for(i = 0; i < n; i++)
	{
		register int j = 0;
		for(j = 0; j < n; j++)
		{
			//p2[i][j] = i*n + j;
			cout<<p2[i][j]<<',';
			p2[i][j] = 1;
		}
	}/**/
	for(i = 0; i < n; i++)
	{
		register int j = 0;
		for(j = 0; j < n; j++)
		{
			//p2[i][j] = i*n + j;
			cout<<p1[i][j]<<',';
		}
	}
	//���ʧ��,������ָ̬��֮�䲻��ֱ�Ӹ�ֵ
	return 0;
}
