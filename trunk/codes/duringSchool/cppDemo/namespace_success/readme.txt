C++�����ռ�
C++�в��õ��ǵ�һ��ȫ�ֱ��������ռ䡣���ⵥһ�Ŀռ��У��������������������������ȫ��ͬ���ͻ���ֳ�ͻ����Ȼ����Ҳ����ʹ�ò�ͬ�����֣�����ʱ���ǲ���֪����һ������Ҳʹ����ȫ��ͬ�����֣���ʱΪ�˳���ķ��㣬����ʹ��ͬһ���֡������㶨����һ������string user_name, �п���������õ�ĳ�����ļ�������ĳ��������Ҳ��������ͬ���ֵı�������ͻ���ֳ�ͻ�������ռ����Ϊ���C++�еı�����������������ͻ������ġ�����İ취���ǽ����string user_name����������һ����ͬ���ֵ������ռ��С�

#include <iostream>
#include <string>
using namespace std;

//�����ڲ�ͬ�����ռ��ж����������ͬ�ı���
namespace myown1{
 string user_name = "myown1";
}


namespace myown2{
 string user_name = "myown2";
}

int main()
{
cout<< "\n"
 << "Hello, " 
 << myown1::user_name //�������ռ����Ʒ�myown1���ʱ���user_name
 << "... and goodbye!\n";

cout<< "\n"
 << "Hello, " 
 << myown2::user_name //�������ռ����Ʒ�myown2���ʱ���user_name
 << "... and goodbye!\n";

return 0;
}
Ҳ����������

int main()
{
using namespace myown1;
cout<< "\n"
 << "Hello, " 
 << user_name 
 << "... and goodbye!\n";

// using namespace myown2;
cout<< "\n"
 << "Hello, " 
 << myown2::user_name //�������ռ����Ʒ�myown2���ʱ���user_name
 << "... and goodbye!\n";

return 0;
}
���ڶ������������������ռ����Ʒ������ʣ���Ϊ��ʱmyown1�ռ��еı����Ѿ��ɼ�������������ƣ��������ͻ��޷�ʶ������һ�������ռ��еı�����
