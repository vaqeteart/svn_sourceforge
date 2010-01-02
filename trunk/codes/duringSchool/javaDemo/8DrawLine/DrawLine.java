import java.awt.*;
import java.awt.event.*;
public class DrawLine extends Frame
{
	public static void main(String []args)
	{
		DrawLine f = new DrawLine();
		//��Ŀ���ܼӵ����캯�����棬��Ϊû�м̳��Ǹ����캯��
		//DrawLine f = new DrawLine("����ֱ��ͼ��");
		f.setTitle("����ֱ��");
		f.doit();
	}
	public void paint(Graphics g)
	{//���»��ƴ��ڵ�ͼ��
		g.setColor(Color.RED);
		g.setFont(new Font("����",Font.ITALIC|Font.BOLD,30));
		g.drawString(new String(orgX+","+orgY),orgX,orgY);
		g.drawString(new String(endX+","+endY),endX,endY);
		g.drawLine(orgX,orgY,endX,endY);
	}
	public void doit()
	{
		setSize(500,500);
		setVisible(true);
		addMouseListener(new MouseAdapter()
		{
			public void mousePressed(MouseEvent e)
			{
				down = true;
				orgX = e.getX();
				orgY = e.getY();
			}
			public void mouseReleased(MouseEvent e)
			{
				down = false;
				endX = e.getX();
				endY = e.getY();
				Graphics g = getGraphics();
				//����ͼ�ε���ʾ��ɫ
				g.setColor(Color.RED);
				//�����ı�������
				g.setFont(new Font("����",Font.ITALIC|Font.BOLD,30));
				g.drawString(new String(orgX+","+orgY),orgX,orgY);
				g.drawString(new String(endX+","+endY),endX,endY);
				g.drawLine(orgX,orgY,endX,endY);
			}
		});
		addMouseMotionListener(new MouseMotionAdapter()
		{
			public void mouseMoved(MouseEvent e)
			{//�������ƶ��ĺ���
				if(down)//Ϊʲô������??�ǲ��Ƕ��̵߳����⣿
				{
				Graphics g = getGraphics();
				//����ͼ�ε���ʾ��ɫ
				g.setColor(Color.RED);
				endX = e.getX();
				endY = e.getY();
				g.drawLine(orgX,orgY,endX,endY);
				orgX = endX;
				orgY = endY;
				}
			}
		});
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{//�رմ��ڵ���Ӧ����
				((Window)e.getSource()).dispose();//û����仰Ҳ�����˳�����
				System.exit(0);
			}
		});
	}
	//Graphics g = getGraphics();//����ֻ������??
	int orgX;
	int orgY;
	int endX;
	int endY;
	boolean down = false;
}