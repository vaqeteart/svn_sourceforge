//�ͻ��������
//package myRmiRecall;
import java.rmi.*;
public class FSCClient {
	public static void main(String args[]){
		//System.setSecurityManager(new RMISecurityManager());
		Function obj = null;
		try{
			//�������������ÿͻ����ӿڵĽӿ�ʵ�������
			LookSeverImpl obj1 = new LookSeverImpl("client");
			//Ϊ�ͻ�����Զ�̶������ֹ��������˵��ÿͻ���ʱʹ��
			Naming.rebind("lxb", obj1);
			//����������ַ��Զ�̶�������Զ�̷������˶���
			obj = (Function)Naming.lookup("rmi://127.0.0.1/functionsc");
			//ͨ��Զ�̷������ṩ�Ľӿں�������3�Ľ׳�
			int results = obj.func(3);
			//System.out.println("��ĿǰҲ������ȷ��");
			System.out.println("RMI Result:" + results);
		}
		catch(Exception ex){
			System.out.println("FSCClient RMI exception:" + ex.getLocalizedMessage());
			ex.printStackTrace();
			
		}
	}

}
