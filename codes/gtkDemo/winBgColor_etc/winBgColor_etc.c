/*设置window的背景颜色以及其他的属性*/
#include <gtk/gtk.h>

int main( int   argc,
          char *argv[] )
{
  /* GtkWidget 是构件的存储类型 */
  GtkWidget *window;
  GdkColor red;

  /* 初始化 */
  gtk_init (&argc, &argv);
    
  /* 创建一个新窗口 */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Fixed Container");
  gtk_window_set_default_size(GTK_WINDOW(window), 100,100);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  /*去掉标题栏*/
  gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
  /*设置窗口背景*/
  gdk_color_parse ("red", &red);
  gtk_widget_modify_bg (window, GTK_STATE_NORMAL, &red);

  /* 为窗口的 "destroy" 事件设置一个信号处理函数 */ 
  g_signal_connect (G_OBJECT (window), "destroy",
		    G_CALLBACK (gtk_main_quit), NULL);
 
  /* 显示窗口 */
  gtk_widget_show_all (window);
    
  /* 进入事件循环 */
  gtk_main ();
    
  return 0;
}
