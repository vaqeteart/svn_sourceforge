import java.io.*;
public class FileStream
{
	public static void main(String[] args)
	{
		File f = new File("hello.txt");
		try
		{
			FileWriter out = new FileWriter(f);//д���ļ�����
			String buf = "goodplay";
			out.write(buf,f.length());
			out.close();
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
		try
		{
			FileReader in = new FileReader(f);//���ļ������ȡ
			char buf[] = new char[10024];
			int len = in.read(buf);
			System.out.println(new String(buf,0,len));
		}	
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}