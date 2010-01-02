import java.io.*;
/*����һ���ļ�������Բ鿴�ļ�������Ҳ���Բ����ļ�������������д������*/
public class FileTest
{
	public static void main(String[] args)
	{
		File f = new File("1.txt");
		if(f.exists())
			f.delete();
		try
		{
				f.createNewFile();
		}
		catch(Exception e)
		{
				System.out.println(e.getMessage());
		}
				
		System.out.println("File Path:"+f.getAbsolutePath());
		System.out.println(f.canWrite()?"is writeable":"is not writeable");
	}
}