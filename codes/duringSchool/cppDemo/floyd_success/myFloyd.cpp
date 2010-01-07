//�ؼ����Ǽ�¼��������֮������·��
//��floyd��װ��һ��������
#include"myFloyd.h"
MyFloyd::MyFloyd()
{
	n = 0;
	cost = NULL;
}
MyFloyd::~MyFloyd()
{
	int i = 0;
	if(cost != NULL)
	{//�ͷ�cost�Ķѿռ�	
		for(i = 0; i < n; i++)
		{
			delete[]cost[i];
		}
		delete cost;
		cost = NULL;
		n = 0;
	}
}
void MyFloyd::compute(const MyGraph &g)
{
	cout<<"��ʼ��floyd��������..."<<endl;
	n = g.n;
	int i = 0;
	int j = 0;
	int k = 0;
	//Ϊ���۾�����䶯̬�ռ�
	cost = new int*[n];
	for(i = 0; i < n;i ++)
	{
		cost[i] = new int[n];
	}

	//��ʼ�����۾���
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cost[i][j] = g.Edge[i][j].cost;
		}
	}
	for(k = 0; k < n; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(cost[i][j] > cost[i][k] + cost[k][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}
	cout<<"������ϣ������뿴ͼ��������������̾���:"<<endl;
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<cost[i][j]<<',';
		}
		cout<<endl;
	}
}