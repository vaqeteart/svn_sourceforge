//myGraph.h
#ifndef __myGraph_h__
#define __myGraph_h__
#define DEBUGMYGRAPH 1//���屾�ļ��Ŀ��ص���
#define MAX 10000000
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
// No description
class MyGraph
{
	public:
		// class constructor
		class MyVertex;
		class MyEdge;
		MyGraph();
		//�������캯��
		MyGraph(MyGraph& g);
		void print();
		// class destructor
		~MyGraph();

		//�������һ��ͼ
		void generateGraph(int n);
		//������ڵ�ǰͼ������һ����ʾ��ǰͼ���ļ���������ͼ�浽һ���ļ���
		void createGraphFile();
		//��ȡͼ�ļ��ĺ���
		void readGraph();
		//��ԭͼ�ĳɾ���n���ڵ��ͼ
		setGraph(int n);
		//��ֵ����
		MyGraph& operator=(MyGraph& g);
		//��
		//��ʽ������V *Vertex 
		MyVertex *Vertex;
		//�� 
		//��ʽ��������һ����ά�Ķ�̬������ô��??
		MyEdge **Edge;//(�ڽӾ���)
		int n;//��ʾͼ�еĽڵ�����
};
//ͼ�ڵ�ṹ
class MyGraph::MyVertex
{
public:
	// class constructor
	MyVertex();
	// class destructor
	~MyVertex();
	// ��Ķ���
	int k;
	// ���
	int num;
	
};

//ͼ�ߵĽṹ
class MyGraph::MyEdge
{
public:
	// class constructor
	MyEdge();
	// class destructor
	~MyEdge();
	// �ж��Ƿ���ͼ�е�һ����
	int isE;
	//��¼�ñ߱����ʵĴ���
	int isVisited;
	//�ߵ�Ȩֵ
	int cost;
};
#endif