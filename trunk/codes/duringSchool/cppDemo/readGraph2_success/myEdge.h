#ifndef __myEdge_h__
#define __myEdge_h__
class MyEdge
{
	public:
		// class constructor
		MyEdge();
		// class destructor
		~MyEdge();
		// ����ʱ���ȡ�ñߵĴ��۵ĺ���
		int getCost(int i,int j,int t);
		int getCost2(int i,int j,int t);//�ڶ���Ȩֵ����
		// �ж��Ƿ���ͼ�е�һ����
		int isE;
		//��¼�ñ߱����ʵĴ���
        int isVisited; 
};
#endif