���ܣ��ͻ�������ʵ�ֵ��÷��񷽵�һ�������Ա������
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