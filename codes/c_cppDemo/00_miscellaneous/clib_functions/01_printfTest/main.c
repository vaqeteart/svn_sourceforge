/*程序功能：主要测试printf的格式部分
 *
 * 关于printf的格式：
 * int printf(const char *restrict format, ...);
 * 参数前面的format参数指名了格式，其形式是：
 * %[flags][fldwidth][precision][lenmodifier]convtype
 * 最好不用翻译，但是翻译起来就是：%[标记][宽度][精度][长度调整]类型
 * 中括号代表可选。这里:
 * 对于flags有:
 * 1)-:指定的参数的输出在所在处是左对齐的(如果存在下面将说的0那么忽略0),默认右对齐。
 * 2)+:指定对于有符号的convtype(相当于类型)，输出其符号。
 * 3) (空格)：指定如果不显示符号的话就以一个空格作为前缀。
 * 4)#:用可选的方式显示。例如：八进制类型（用o)就以0开头，十六进制(用x)就以0x开头等,见man.
 * 5)0:参数的前面用0填充(如果同时存在-将被-覆盖，导致0被忽略)而不是用空格了。
 *
 * 对于fldwidth：
 * 它指明了最小宽度，如果参数小于这个宽度就填充空格。
 * fldwidth可以是一个正的十进制数，或者是一个'*'。例如：5,或者*
 *
 * 对于precision:
 * 它指定了整数的最少显示数字数目，浮点数小数点后面的数字数目以及字符串的最大字节数目。 
 * presion可以是一个点'.'后面接整数或者'*'。例如:.5或者.*
 *
 * 注意：对于fldwidth和precision都可以指定一个'*'，这时候，需要在将要显示的参数前面再添加一个整数参数来指定将要显示的值。可以参见代码中的例子。
 *
 * 其他的暂时不说了，这里主要就说了#和*在format参数中的作用。
 *
 * */
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%-5d\n", 1);//宽度为5，左对齐
	printf("%5d\n", 2);//宽度为5，默认右对齐
	printf("%+5d\n", 3);//宽度为5，显示符号(正号)的3
	printf("%-+5d\n", 4);//宽度为5，显示符号并且左对齐的4.
	printf("%- 5d\n",5);//宽度为5，将正号不显式代之为一个空格，并且左对齐。
	printf("%- 5d\n",-6);//宽度为5，左对齐同%-5d。
	printf("%05d\n",7);//宽度为5，不足的填充为0。
	printf("%*d\n",8,9);//宽度在参数里面指定为8(!!!!!!!!!!!!!)
	printf("%0-5d\n",8);//宽度为5，不足的填充为0,忽略左对齐。

	printf("%7.5d\n",8);//宽度为7，精度为5的整数(00008)。
	printf("%7.5f\n",7.1);//宽度为7，精度为5的浮点数(7.10000)。
	printf("%7.*f\n",3,6.1);//宽度为7，精度在参数中指定为3的浮点数(6.100)。

	printf("%3.5f\n",5.1);//宽度为3，精度为5的浮点数,精度大于宽度(5.10000)。不被截断!!
	printf("%7.3f\n",4.12345);//宽度7，精度3的浮点数,精度小于实际的数值精度(4.123)。截断!!

	printf("%3s\n", "abcdef");//宽度3长度大于3的字符串.不被截断!!
	printf("%.3s\n", "abcdef");//精度3长度大于3的字符串.截断!!
	printf("%.3s\n", "abc");//精度5长度小于5的字符串,没有什么.

	return 0;
}