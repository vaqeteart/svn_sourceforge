import java.awt.*;
import java.awt.event.*;
/*�����������Ӧ���������¼���Ҳ������Ӧ����ϼ�����¼�*/
class MyButton extends Button
{
	private MyButton friend;
	public void setFriend(MyButton friend)
	{
		this.friend = friend;
	}
	public MyButton(String name)
	{
		super(name);
		enableEvents(AWTEvent.MOUSE_MOTION_EVENT_MASK);//���ť�����Ӧ�¼�����ƶ�
	}
	protected void processMouseMotionEvent(MouseEvent e)
	{
		setVisible(false);
		friend.setVisible(true);
	}
}

public class ComponentEvent
{
	public static void main(String []args)
	{
		MyButton btn1 = new MyButton("����ץ��ѽ��");
		MyButton btn2 = new MyButton("����ץ��ѽ��");
		btn1.setFriend(btn2);
		btn2.setFriend(btn1);
		btn2.setVisible(true);
		Frame f = new Frame("��Ӧ�¼�");
		f.add(btn1,"North");
		f.add(btn2,"South");
		f.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				e.getWindow().setVisible(false);
				((Window)e.getComponent()).dispose();
				System.exit(0);
			}
		});//������������������ڵ��¼��������ڲ���ʵ��
		f.setSize(300,300);
		f.setVisible(true);
		btn1.setVisible(false);
	}
}