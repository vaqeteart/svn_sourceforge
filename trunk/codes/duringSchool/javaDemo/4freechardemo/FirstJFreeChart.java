package demo;

import org.jfree.chart.JFreeChart;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartFrame;
import org.jfree.data.general.DefaultPieDataset;

public class FirstJFreeChart {
  public FirstJFreeChart() {
  }
  
  public static void main(String[] args){
    DefaultPieDataset dpd = new DefaultPieDataset();//��������ͼ���ݶ���
    //���ñ���ͼ����ʾ
    dpd.setValue("�ɼ�����",25);
    dpd.setValue("��������",25);
    dpd.setValue("�����㷨",45);
    dpd.setValue("������ʱ����",5);
    
    //Create JFreeChart object
    //�������Բ鿴Դ��
    JFreeChart pieChart = ChartFactory.createPieChart("���ܽ�ͨ��Ŀ����",dpd,true,true,false);
    ChartFrame pieFrame = new ChartFrame("���ܽ�ͨ��Ŀ����",pieChart);
    pieFrame.pack();
    pieFrame.setVisible(true);
  }
}
