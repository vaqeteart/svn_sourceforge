/*程序功能：测试数组的初始化值
 * 测试结果：
 * a,b的第一个元素是10,其他元素是0。
 * c的元素值都是随机的。
 * */
#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char *argv[])
{
	int a[10] = {10};
	int b[10] = {10,};
	int c[10];

	cout<<"int a[10]={10};"<<endl;
	cout<<"int b[10]={10,};"<<endl;
	cout<<"int c[10];"<<endl;
	cout<<"the initialize value of a,b,c is:"<<endl;
	for(int i = 0; i < 10; ++i)
	{
		cout<<"a["<<i<<"]="<<a[i]<<endl;
		cout<<"b["<<i<<"]="<<b[i]<<endl;
		cout<<"c["<<i<<"]="<<c[i]<<endl;
	}
	return 0;
}
