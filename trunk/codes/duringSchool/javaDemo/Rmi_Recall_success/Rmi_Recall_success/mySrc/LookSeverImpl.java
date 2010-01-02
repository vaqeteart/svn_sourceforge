//�ͻ���ʵ�������
//package myRmiRecall;
import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
public class LookSeverImpl extends UnicastRemoteObject implements LookSever{
	private String name;
	//���캯��
	public LookSeverImpl(String s)throws RemoteException{
		super();
		name = s;
	}
	//�ͻ����ӿ�ʵ�ֺ���
	public int lookandfunc(String name,int x)throws RemoteException{
		Function obj = null;
		try{
			//��÷������ṩ�ص�������Զ�̶���
			obj = (Function)Naming.lookup(name);
		}
		catch(Exception e){
			System.out.println(name+"LookSeverImpl: Error is:" + e);
		}
		System.out.println("This time calls x is:" + x);
		//�͵����ӿڷ���
		return obj.func(x);
	}
}
