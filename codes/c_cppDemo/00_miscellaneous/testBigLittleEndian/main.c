//判断是little endian还是big endian
#include <stdio.h>
int main(int argc, char *argv[])
{
	int a = 0x11223344;
	if((char)a == 0x11)
	{//低地址存高字节
		printf("big endian!\n");
	}
	printf("%x\n",(int)(char)a);

	short b = 0x1122;
	if((char)b == 0x22)
	{//低地址存低字节
		printf("little endian!\n");
	}
	//强转之后的地址，一定是从低开始算。
	printf("%x\n",(int)(char)b);
	printf("hello\n");
}
