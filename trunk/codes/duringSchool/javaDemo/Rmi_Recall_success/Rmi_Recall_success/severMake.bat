rem ����,֮�����з���˳���
echo off
echo 1.�������е�java�ļ�
echo javac *.java
PAUSE
javac mySrc\*.java -d .
echo 2.����rmic����ӿ�ʵ���ļ�
echo 2.1����˽ӿ�ʵ��:
echo rmic FunctionImpl
PAUSE
rmic FunctionImpl
echo 2.2�ͻ��˽ӿ�ʵ��:
echo LookSeverImpl
PAUSE
rmic LookSeverImpl
echo 3.����ע��rmi
echo start rmiregistry
PAUSE
start rmiregistry
echo 4.���з���˳���
echo java -Djava.security.policy=policy.policy FSCSever
PAUSE
echo ��������׼��������������¡�֮�����пͻ��˳���
java -Djava.security.policy=mySrc\policy.policy FSCSever
PAUSE