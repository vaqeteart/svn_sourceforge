
//�������飬�ر��Ƕ�ά����ά������ռ�ķ���
public class TestAllocate {
	public static void main(String args[])
	{
//		a2[][]={{1,2},{3,4,5}} 
		/*int a2[][];
		a2[][] = new int [2][]; //2�� ��������*/
		int a2[][] = new int [2][]; //2��
		a2[0]=new int [2]; //��1�� 2Ԫ�� 
		a2[1]=new int [3];//��1�� 3Ԫ��
		System.out.println("������"+ a2.length);
		int value = 1;
		for(int i = 0; i < a2.length; ++i)
		{
			for(int j = 0; j < a2[i].length; ++j)
			{
				a2[i][j] = value++;
			}
		}
		
		System.out.println("Ԫ���������£�\n{");
		for(int i = 0; i < a2.length; ++i)
		{
			System.out.print("{");
			for(int j = 0; j < a2[i].length - 1; ++j)
			{
				System.out.print(a2[i][j]+",");			
			}
			System.out.println(a2[i][a2[i].length-1]+"}");
		}
		System.out.println("}");/**/
	}
}
