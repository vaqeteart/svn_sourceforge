//��������������ķ���
import java.util.*;
public class TestRandom
{
	public static void main(String argv[])
	{
		System.out.println("��������������ĺ�����");
		double a = Math.random();
		System.out.println("Math.random()���ɵ�0��1֮����������������1��:"+a);
		int ia = new Random().nextInt(100);
		System.out.println("new Random().nextInt()���ɵ�0,100(������100)����������:"+ia);
	}
}