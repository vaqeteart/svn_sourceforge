#include<iostream.h>
#include<fstream.h>

//��cin����Ĳ���
void testCin()
{
	//��cin>>�Ĳ���:
	cout<<"��cin>>�Ĳ���"<<endl;
	char a1,a2,a3;
	cin>>a1;
	cout<<"a1:"<<a1<<endl;//ͬ����cin>>
	cin>>a2;
	cout<<"a2:"<<a2<<endl;
	cin>>a3;
	cout<<"a3:"<<a3<<endl;
	//���ԵĽ����cin������ܶ���Ļس��ѻس�����һ�����뵥Ԫ�ķָ��������,���Ƕ�����ַ��ᱻ����ı��������ܻ��߶�ʧ
	//����cin���ǻػ���س����ŵ�

	//cin.clear();//��ջ��棬�����ã�
	while(cin.get() != 10);//���cin�������
	//while(cin.get() != '\n');//���cin�������
	
	//��cin.get()�Ĳ���
	cout<<"��cin.get()�Ĳ���"<<endl;
	char b1,b2,b3;
	b1=cin.get();
	cout<<"b1:"<<b1<<endl;//ͬ����cin>>
	b2=cin.get();
	cout<<"b2:"<<b2<<endl;
	b3=cin.get();
	cout<<"b3:"<<b3<<endl;
	//���ԵĽ��cin����Ļس�Ҳ�ᱻ������

	//�ܽ������뵽cin�Ĳ�ֻһ���ַ�������ÿ��get()ֻ��ȡ���е�һ���ַ�
}
//ʵ����������ִ�ŵ��ļ�����
void inputToFile()
{//ȱ����ֻ�ܹ���#��Ϊ����Ľ���
	//���ļ��ĺϷ��Լ�黹�����ϸ�
	cout<<"��ʼ�����ļ������ݣ���ŵ��ļ���:"<<endl;
	char filename[256];//���Զ����ַ�������Ϊ�ļ���
	cout<<"�������ļ�����������չ���Ҳ��ó���255�ַ���:"<<endl;
	cin>>filename;
	ofstream savfile(filename);
	if(savfile)
	{
		cout<<"�ļ��Ѿ���,�������ļ����ݣ�"<<endl;
		char tmp;
		cin>>tmp;
		while(tmp != '#')
		{
			savfile<<tmp;//������һ�β�������һ���س���������get�Ͳ���
			tmp = cin.get();//����ŵ�����ͻ��һ���س�,���Ƿŵ�������ʾ��#
		}
		savfile.close();
		cout<<"������ϣ��ļ��Ѿ��ر�!"<<endl;
	}
	else
	{
		cout<<"�����ļ�ʧ�ܣ�"<<endl;
	}
}
void copyToFile()
{
	//����֮ǰ��׼��
	cout<<"׼�������ļ�..."<<endl;
	char source[256];
	char target[256];
	cout<<"������Դ�ļ���(������չ����Ҫ����255�ַ�):"<<endl;
	cin>>source;
	ifstream file1(source,ios::nocreate);
	if(!file1)
	{
		cout<<"Դ�ļ������ڣ�"<<endl;
		return;
	}
	cout<<"������Ŀ���ļ���(������չ����Ҫ����255�ַ�):"<<endl;
	cin>>target;
	ofstream file2(target);
	cout<<"��ʼ�����ļ�..."<<endl;
	//����
	char tmp;
	tmp = file1.get();
	while(!file1.eof())
	{//�������ѭ��ǰ���getд�ϣ���ѭ���ڵ�get��ǰ��ʹ���������һ���Ƿ��ַ�
		file2.put(tmp);
		tmp = file1.get();
	}
	file1.close();
	file2.close();
	cout<<"������ϣ�"<<endl;
}
void main()
{
	//testCin();
	cout<<"hello world!"<<endl;
	//inputToFile();
	copyToFile();
}