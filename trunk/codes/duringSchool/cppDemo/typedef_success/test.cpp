#include<iostream>
using std::cout;
using std::endl;
typedef int A[6];//����int A[6]�Ǹ�����������typedef�൱�ڱ�����������
int main()
{
	cout<<"start"<<endl;
	//A b;//�൱��int b[6]��
	A b[5];	//����typedef�൱��int b[5][6]��
	int i = 0;
	int j = 0;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 6; j++)
		b[i][j] = i*6 + j;
	}
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 6; j++)
		{
			cout<<b[i][j]<<',';
		}
		cout<<endl;
	}

	return 0;
}