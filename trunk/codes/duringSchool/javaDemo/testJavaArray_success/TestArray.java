import java.io.*;

class TEdge
{
	TEdge()
	{
		isE = 1;
	}
	int isE = 0;
}
public class TestArray
{
	public static void main(String argv[])
	{
		System.out.println("test Array:");
		//���Ի����������͵�����
		int A[][];
		int n = 5;
		A = new int[n][n];
		int c = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				System.out.println(A[i][j]);
			}			
		}
		//�����������ݲ��Գɹ���Ĭ��ֵ��0
		
		//�����Զ������͵�����
		TEdge E = new TEdge();
		System.out.println(E.isE);//��ʾ���캯����ĳ�ʼ��1
		TEdge AT[][];
		AT = new TEdge[n][n];
		//����ǳ���Ҫ����ҪΪ������ռ���ܷ��ʡ����û�����ѭ����ô���һ��ѭ���д�
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				//System.out.println(AT[i][j].isE);
				AT[i][j] = new TEdge();
			}			
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				System.out.println(AT[i][j].isE);
				//AT[i][j] = new TEdge();
			}			
		}
		
		//�Զ��������������ʧ�ܣ���ָ�����
	}
}
