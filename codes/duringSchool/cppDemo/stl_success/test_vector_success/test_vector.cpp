#include<iostream.h>
#include<math.h>//rand()
#include<ctype.h>
#include<vector>
#include<algorithm>
using namespace std;
void print(int i)
{
	cout<<i<<',';
}
int main(int argc, char** argv)
{
/////////����
	vector<int> nums;//vector<int> nums(10);
	vector<int> nums2;
	vector<int> nums3(10);

//////////
	cout<<"nums3�տ�ʼ�ĳ�ʼֵ�ǣ�"<<endl;
	int i = 0;
	for(i = 0; i < nums3.size(); i++)
	{//nums3.size() = 10,�ռ�Ĵ�С
		cout<<nums3[i]<<',';//�����������
	}
	cout<<'\b'<<endl;//Ϊʲô�����˸�
//////////������֮��ĸ�ֵ
	nums3[1] = 5;//����������ֵ
	int test = nums3[1];//����������ֵ
	cout<<"test:"<<test<<endl;
/////////������ɾ��	
	int count;
	cout<<"������Ԫ����Ŀ:"<<endl;
	cin>>count;

	for(i = 0; i < count; i++)
	{
		//nums.insert(nums.begin(),i);//�У�����ͷ������
		nums.insert(nums.end(),i);//������ĩβ����Ԫ�س���
		nums2.insert(nums2.begin());//�����Ԫ��(ע���ʱΪ0)
		//nums.push_back(i);//��
	}
	nums2.erase(nums2.begin());//ɾ��һ��Ԫ��ֻ�ܴ�ͷ����������ֱ�Ӵ�β��
	nums2.erase(nums2.begin());
	nums.erase(nums.end()-1);//����end()-1��ɾ�����һ��Ԫ��
	cout<<nums2.size()<<endl;
//////////������ʾ����
	cout<<"nums:"<<endl;
	for_each(nums.begin(),nums.end(),print);//ѭ����ʵ����ĳ�Ա??<algorithm>
	cout<<endl;
	cout<<"nums2:"<<endl;
	for_each(nums2.begin(),nums2.end(),print);//ѭ����ʵ����ĳ�Ա??<algorithm>
//////////�б�֮��ĸ�ֵ	
	nums2 = nums;
	cout<<endl<<"��ֵ��nums2"<<endl;
	for_each(nums.begin(),nums.end(),print);//ѭ����ʵ����ĳ�Ա,������Ϊprint�Ĳ���
	cout<<endl;
/////////�������Ĳ���
	//vector<int>::iterator it;
	vector<int>::const_iterator cit;//������������޸��ô˵�����
	cit = nums.begin();
	cout<<"nums:"<<endl;
	while(cit != nums.end())
	{
		cout<<*cit<<',';//��ȡ����
		cit++;//��1����
	}
/////////stl�㷨
	reverse(nums.begin(),nums.end());//��ת����
	cit = nums.begin();
	cout<<"reverse nums:"<<endl;
	while(cit != nums.end())
	{
		int a = *cit;//���Ը�ֵ
		//cout<<a<<',';//��ȡ����
		cout<<*cit<<',';//��ȡ����
		cit++;//��1����
	}
	cout<<endl;
	sort(nums2.rbegin(),nums2.rend());//��������
	//sort(nums2.begin(),nums2.end());//��������
	cit = nums2.begin();
	cout<<"r sort nums2:"<<endl;
	while(cit != nums2.end())
	{
		cout<<*cit<<',';//��ȡ����
		cit++;//��1����
	}
	generate(nums3.begin(),nums3.end(),rand);//���������
	cout<<"nums3:"<<endl;
	for(i = 0; i < nums3.size(); i++)
	{
		cout<<nums3[i]<<',';
	}
	cout<<endl;
	//replace_if(nums2.begin(),nums2.end(),odd,5);//���������������Ϊ0����
	cit = nums2.begin();
	cout<<"replace_if nums2:"<<endl;
	while(cit != nums2.end())
	{
		cout<<*cit<<',';//��ȡ����
		cit++;//��1����
	}
	//system("PAUSE");
	//��θ�ֵ
	return 0;
}





















