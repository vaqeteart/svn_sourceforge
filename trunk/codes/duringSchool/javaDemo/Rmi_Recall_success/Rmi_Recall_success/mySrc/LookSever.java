//�ͻ��˷���ӿ�
//package myRmiRecall;
import java.rmi.Remote;
import java.rmi.RemoteException;
public interface LookSever extends Remote{
	//�������˶����ʶip�ͷ���˷�������ֵ
	int lookandfunc(String s,int x)throws RemoteException;
}
