ʹ��˵����
clear.bat ɾ���ϴα���֮��������ļ�
severMake.bat ����Ȼ�����з���˳���
clientMake.bat ���пͻ��˳���



һ�����ܣ�����3�Ľ׳�
1)�ͻ������÷��񷽵�һ�������Ա��������3�Ľ׳�.
2)��������������з����м������ͻ�����֪ͨ�ͻ����ٴε��ñ������������м����׳�.
3)�ݹ���������ֱ���������
�������裺
step1:����
1)��java����������е�javaԴ�ļ�:
javac *.java
2)��rmic����������еĽӿ�ʵ����:
rmic LookSeverImpl
rmic FunctionImpl

step2:����
1)����ע��rmi:
start rmiregistry
2)���з���������:
java FSCSever
3)���пͻ��˳���:
java FSCClient



����ע�⣺
ע�⣺
���rmic������ʾ�Ҳ����࣬���ԣ�
1)javac *.java
2)rmic -classpath . HelloImpl

ע����������ڱ�������Ҫ
1)����
1.1)�ͻ������ͻ��˳��򣬿ͻ��˽ӿ� ����˽ӿ� �ͻ��ӿ�ʵ�� ����ӿ�skeleton �ͻ��ӿ�skeleton
FSCClient.java Function.java LookSever.java LookSeverImpl.java FunctionImpl_stub LookSeverImpl_skeleton 
1.2)���񷽣�����˳��򣬷���˽ӿ� �ͻ��˽ӿ� ����ӿ�ʵ�� �ͻ��ӿ�skeleton ����ӿ�skeleton
FSCSever.java Function.java FunctionImpl.java LookSever.java FuctionImpl_skeleton LookSeverImpl_stub
֮������������£�
2)�������Ϳͻ���ͬʱ����start rmigistry
3)������г�������ǲ���������Ҫ��д���²����ļ�Ȼ����-Djavaѡ���������£�

3.1)����һ��client.policy�ļ��������£�
grant     
  {     permission   java.net.SocketPermission     
              "*:1024-65535",   "connect,accept";   
        permission   java.net.SocketPermission     
              "host:80",   "connect";   
  };
3.2)����ʱ����ӿ�ʵ�����-Djava.security.policy=client.policyѡ��:
java -Djava.security.policy=client.policy FSCClient






�ġ������ο�
���в��裺
���Ӳ����ļ������籣��Ϊ��Ŀ¼��client.policy   
  �ļ����ݣ�   
  grant     
  {     permission   java.net.SocketPermission     
              "*:1024-65535",   "connect,accept";   
        permission   java.net.SocketPermission     
              "host:80",   "connect";   
  };
0/rmic ���񷽽ӿ�ʵ����,javac �ͻ�����.java
1/start rmiregistry
2/���з��񷽽ӿ�ʵ����(java -Djava.....  ����ʵ����)
  ****����ʱ���ϲ�����   
  -Djava.security.policy=client.policy
3/���пͻ������� (java �ͻ�����)

ע�⣺
���������ʾ�Ҳ����࣬���ԣ�
1)javac *.java
2)rmic -classpath . HelloImpl
����һ������ˡ�