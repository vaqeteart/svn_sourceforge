//���Ķ����� 51������ʽ������ʹ�� 
//#define N 51
//�����Ӷ�������4�� 
#ifndef __myGraph_h__
#define __myGraph_h__
#define DEBUGMYGRAPH 1//���屾�ļ��Ŀ��ص���
#define N 4
#include<iostream>
#include<fstream>
#include "myVertex.h"
#include "myEdge.h"
// No description
class MyGraph
{
	public:
		// class constructor
		MyGraph();
		// class destructor
		~MyGraph();
		//�������һ��ͼ
		void generateGraph();
		//������ڵ�ǰͼ������һ����ʾ��ǰͼ���ļ���������ͼ�浽һ���ļ���
		void createGraphFile();
		//��ȡͼ�ļ��ĺ���
		void readGraph();
		//��
		//��ʽ������V *Vertex 
#if DEBUGMYGRAPH == 1
		MyVertex1 Vertex[N];
#else
		MyVertex1 *Vertex;
#endif
		//�� 
		//��ʽ��������һ����ά�Ķ�̬������ô��??
#if DEBUGMYGRAPH == 1
		MyEdge Edge[N][N];
#else
		MyEdge **Edge;
#endif
		int n;//��ʾͼ�еĽڵ�����
};
#endif