#include<iostream.h>
void main()
{
int n;
cout<<"input the n:"<<endl;
cin>>n;
int* array1d = new int[n*n];
int** array = new int*[n];
int i = 0;
for (i = 0; i < n; i++)
    array[i] = array1d + i * n;

// ����arrayָ����Ժ�һ���ά����һ��ʹ��
int count = 0;
for(i = 0; i < n; i++)
{
	for(int j = 0; j < n; j++)
	{
		array[i][j] = count++;
		cout<<array[i][j];
	}
	cout<<endl;
}

delete[] array;
delete[] array1d;
}