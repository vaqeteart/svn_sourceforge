#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
/*using namespace std;*/
int main(void)
{
	char filename[256];
	cout<<"�������ļ���(������չ����txt�ļ�):"<<endl;
	cin>>filename;
	ifstream infile;
	infile.open(filename);
	while(!infile.is_open())
	//while(!infile)Ҳ����
	{
		cout<<"�ļ������ڣ����������룡"<<endl;
		cin>>filename;
		infile.clear();
		infile.open(filename);	
	}
	char c = ' ';
	c = infile.get();
	while(!infile.eof())
	{
		cout<<c;
		c = infile.get();				
	}
	infile.close();
	return 0;
}