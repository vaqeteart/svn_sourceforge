//���Ķ����� 51������ʽ������ʹ�� 
//#define N 51
//�����Ӷ�������4�� 
#ifndef __myGraph_h__
#define __myGraph_h__
#define DEBUGMYGRAPH 1//���屾�ļ��Ŀ��ص���
#define MAX 10000000
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
		//��ԭͼ�ĳɾ���n���ڵ��ͼ
		setGraph(int n);
		//��
		//��ʽ������V *Vertex 
		MyVertex1 *Vertex;
		//�� 
		//��ʽ��������һ����ά�Ķ�̬������ô��??
		MyEdge **Edge;
		int n;//��ʾͼ�еĽڵ�����
};
#endif