#ifndef __myFloyd_h__
#define __myFloyd_h__
#include<iostream>
#include"myGraph.h"
class MyFloyd
{
public:
	MyFloyd();
	~MyFloyd();
	void compute(const MyGraph &g);//�������,�ⲿ���õĽӿ�	
	int **cost ;//cost����
	int n;//��¼ͼ�Ľڵ���

};
#endif