 /*Java��main�����Ĳ���   
 * Filename��MainArgs.java
 * Task��Java��main�����Ĳ���
 * Java��main�����ĵ�һ��������args[0]
 * ���û�в�����Ȼ����һ�������飨args.length����0��
 */
public class TestArgv {

 public static void main(String args[]) { 
 System.out.println(args.length);//û�в�����0
  if (args.length != 0) 
  {//�в��������Ȳ���0
	  for(int i = 0; i < args.length; ++i)
	  {
		  System.out.println(args[i]);
	  }
  }
  System.out.println(args.length);//û�в�����0
  } 
}
/*
 * ���:
 * 1.����java TestArgv,��:args.length = 0;
 * 2.����java TestArgv first second����:args.length = 2��args[0] = first��args[1] = second;
 * */


