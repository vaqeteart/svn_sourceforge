//����˽ӿ�ʵ����
//package myRmiRecall;
import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
public class FunctionImpl extends UnicastRemoteObject implements Function{
	private String name;
	//���캯��
	public FunctionImpl(String s)throws RemoteException{
		super();
		name = s;
	}
	//�ӿ�ʵ�ֺ���
	public int func(int x)throws RemoteException{
		//�����ͻ���Զ�̵��ýӿڶ���
		LookSever obj = null;
		if(x == 1){
			return 1;
		}
		else{
			try{
				//���ÿͻ�IP��Ϣ��Զ�̶��������ҿͻ����������
				//obj = (LookSever)Naming.lookup("//192.168.1.139/lxb");
				obj = (LookSever)Naming.lookup("rmi://127.0.0.1/lxb");			
			}
			catch(Exception e){
				System.out.println("FunctionImpl Error is:" + e);
			}
			System.out.println("This calls x is:" + x);
			//���ÿͻ����ӿڷ��������ÿͻ������������������x-1�Ľ׳�(�ݹ����)
			return x * (obj.lookandfunc("rmi://127.0.0.1/functionsc",x - 1));
			
		}
	}

}
