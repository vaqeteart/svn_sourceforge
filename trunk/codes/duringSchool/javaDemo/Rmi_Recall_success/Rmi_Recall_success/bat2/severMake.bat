rem ����,֮�����з���˳���
echo off
echo 1.�������е�java�ļ�
echo javac *.java
javac mySrc\*.java -d .
echo 2.����rmic����ӿ�ʵ���ļ�
echo ����˽ӿ�ʵ��:
echo rmic FunctionImpl
rmic FunctionImpl
echo �ͻ��˽ӿ�ʵ��:
echo LookSeverImpl
rmic LookSeverImpl
echo 3.����ע��rmi
echo start rmiregistry
start rmiregistry
echo 4.���з���˳���
echo java -Djava.security.policy=policy.policy FSCSever
echo Ȼ�����пͻ��˳���
java -Djava.security.policy=mySrc\policy.policy FSCSever
PAUSE