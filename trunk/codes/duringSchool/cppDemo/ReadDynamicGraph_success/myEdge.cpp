#include "myEdge.h" // class's header file
#include <iostream>
using namespace std;
// class constructor
MyEdge::MyEdge()
{
	// insert your code here
	isE = 0; 
	isVisited = 0;
}

// class destructor
MyEdge::~MyEdge()
{
	// insert your code here
}

// ����ʱ���ȡ�ñߵĴ��۵ĺ�������ͼ�Ĳ�ͬ����ͬ�ڴ���һ������ 
int MyEdge::getCost(int i,int j,int t)
{
	/* TODO (#1#): Implement E::getCost() */
	int time = t;
	//if(isE == 1)
	//{	
		if(time >= 0)
		{
			while(time > 15000)
			{
				time = time - 15000;
			}
			if(time < 5000)
			{
				return 100;
			}
			if(time < 10000)
			{
				return 200;
			}
			return 100;
		}
		else
		{
			int a = 1;
			cout<<"ʱ�䲻��Ϊ����"<<endl;
			return -1; 
		}
	//}
	//else
	//	cout<<"û��������!"<<endl;
}
int MyEdge::getCost2(int i,int j,int t)
{
	/* TODO (#1#): Implement E::getCost() */
	int time = t;
	//if(isE == 1)
	//{	
	if(time >= 0)
	{
		while(time > 15000)
		{
			time = time - 15000;
		}
		if(time < 5000)
		{
			return 2000;
		}
		if(time < 10000)
		{
			return 3000;
		}
		return 2000;
	}
	else
	{
		int a = 1;
		cout<<"ʱ�䲻��Ϊ����"<<endl;
		return -1; 
	}
	//}
	//else
	//	cout<<"û��������!"<<endl;
}