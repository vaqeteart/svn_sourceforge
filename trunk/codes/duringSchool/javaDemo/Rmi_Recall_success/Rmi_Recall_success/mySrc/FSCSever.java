//�������������
//package myRmiRecall;
import java.rmi.*;
public class FSCSever {
	public static void main(String args[]){
		//System.setSecurityManager(new RMISecurityManager());//������ȫ�������
		try{
			//�����ͻ������÷������ӿڵĽӿ�ʵ�������
			FunctionImpl obj = new FunctionImpl("functionsc");
			//����������ѷ�����Զ�̶���obj����"functionsc"��
			Naming.rebind("functionsc",obj);
			System.out.println("functionsc bound in registry");
		}
		catch(Exception e){
			System.out.println("FSCSever Functionsc err:" + e.getLocalizedMessage());
			e.printStackTrace();
		}
	}

}
