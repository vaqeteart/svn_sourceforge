#include<iostream.h>
#include<fstream.h>
void test()
{
	char filename[256];
	cout<<"�������ļ���(������չ����txt�ļ�):"<<endl;
	cin>>filename;
	ifstream infile(filename,ios::nocreate);
	/*while(!infile)
	{
		cout<<"�ļ������ڣ����������룡"<<endl;
		infile.close();//???�˴�����ѭ������
		cin>>filename;
		infile.open(filename,ios::nocreate);
	}*/
	//����Ĵ��벻��ʵ�֣���һ�δ����ˣ��ͽ�����ѭ���ˡ�����Ŀ��ԡ� 
	//infile.open(filename,ios::nocreate);
    while(!infile.is_open())
	//while(!infile)//����
    {
        cout<<"�ļ������ڣ�����������"<<endl;  
        infile.close();//������ѭ����                                  
        cin>>filename;  
        infile.open(filename,ios::nocreate); 
	}
}
void main()
{
	cout<<"hello world!"<<endl;
	test();
}