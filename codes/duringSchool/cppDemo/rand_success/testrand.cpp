//����0��1��������

#include<iostream.h>
#include<stdlib.h>//rand��srand
#include<math.h>
#include<time.h>
void main()
{
	//rand���ص����������������%�޶���Χrand()%100ָ����100���ڵģ���
	srand(time(NULL));//��rand���ʹ���ǲ���ÿ�ζ�Ҫ����أ�
	double result = fabs (sin ((double)rand()));
	cout<<"result:"<<result<<endl;

	result = (double)rand()/RAND_MAX;
	cout<<"result:"<<result<<endl;
	result = fabs (sin ((double)rand()));
	cout<<"result:"<<result<<endl;
}

