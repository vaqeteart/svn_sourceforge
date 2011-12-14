/*功能：
*本程序测试将对结构按位访问，这样不需要对位操作的时候还得用位操作的方式。
*本程序输出如下：
*sizeof Myfield:4,bit_8:11,bit_16:12,bit_15:13,bit_1:1
*all:0x800d0c0b
*注意：如果使用int，那么bit_1则为-1。如果使用非指针定义"all"，那么会编译出错。
*/
#include <stdio.h>
struct Myfield
{
	unsigned bit_8:8;
	unsigned bit_16:8;
	unsigned bit_15:15;
	unsigned bit_1:1;
};
int main(int argc, char *argv[])
{
	struct Myfield test;
	test.bit_8=11;
	test.bit_16=12;
	test.bit_15=13;
	test.bit_1=1;
	printf("sizeof Myfield:%d,bit_8:%d,bit_16:%d,bit_15:%d,bit_1:%d\n", 
			sizeof(struct Myfield),test.bit_8,test.bit_16,test.bit_15,test.bit_1);
	unsigned *all = (unsigned*)&test;
	printf("all:0x%x\n",*all);
	return 0;
}
