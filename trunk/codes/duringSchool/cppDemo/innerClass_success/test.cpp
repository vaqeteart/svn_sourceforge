#include<iostream>
//����ͷ�ļ�
#include"myGraph.h"
using namespace std;
int main()
{
	cout<<"begin test myGraph:"<<endl;
	MyGraph g;//����ͼ����
	g.readGraph();//��ȡ�ļ�������Ӧ��ͼ
	g.print();//��ӡͼ����Ϣ.
	g.createGraphFile();//���ͼ��һ��output.txt�ļ���
	MyGraph g1(g);//�ÿ������캯����ʼ��ͼ
	g1.print();
	MyGraph g2;
	g2 = g1;//����
	g2.print();
	g2.setGraph(6);//��g2������Ϊ6���ڵ�
	cout<<"���ú�:"<<endl;
	g2.print();

	return 0;
}