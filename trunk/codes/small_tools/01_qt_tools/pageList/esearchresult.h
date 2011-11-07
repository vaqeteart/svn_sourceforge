#ifndef __ESEARCHRESULT_H__
#define __ESEARCHRESULT_H__
#include <QWidget>
#include <QFrame>
#include <QStackedWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QList>

#define MY_DEBUG_CNT 1

class ESearchItem;
class EItemContainer;
class EPageBar;
class ESearch:public QWidget
{
	enum {ESEARCH_HEIGH=800, ESEARCH_WIDTH=600, EHEADER_HEIGHT=30, EBAR_WIDTH=40};
	Q_OBJECT
	public:
	//ESearch(QWidget *parent = 0, Qt::WindowFlags f = Qt::FramelessWindowHint);
	ESearch(QWidget *parent = 0);
	void init();

	signals:
	void pageCntChanged(int);
	void pageSelected(int);

	private:
	QLabel *m_titleHeader;
	EItemContainer *m_itemContainer;
	EPageBar *m_pageBar;
};

class EItemContainer:public QStackedWidget
{
	Q_OBJECT
	public:
	enum {MAX_PERPAGE=8,TOTAL_ITEM=500};//100,have some thing wrong?
	//EItemContainer(QWidget *parent = 0, Qt::WindowFlags f = Qt::FramelessWindowHint);
	EItemContainer(QWidget *parent = 0);
	void updateLayout();

	//call updateLayout after do add and delete item!
	void deleteItem(int index);
	void addItem(ESearchItem *item);

	void setPageBar(EPageBar *pageBar);

	protected:
	virtual void resizeEvent(QResizeEvent *e);

	public slots:
		void pageSelected(int page);
	void refresh();//update when contents changed

	signals:
	void pageCntChanged(int);

	private:
	void init();//initial the counts of items etc.

	private:
	int m_maxPerPg;
	//int m_iCnt;
	int m_pgCnt;
	QList<ESearchItem*> m_items;
	EPageBar *m_pageBar;
};

class EPushLabel;
class ESearchItem:public QWidget
{
	Q_OBJECT

	enum EIType{BOOKS,DOCUMENTS,PHOTOS,MUSIC,WIKI};

	public:
	ESearchItem(QWidget *parent = 0);
	void defaultUi();
	void refresh();
	void setType(EIType t);
	EIType getType()const;
	void setExtBtn(EPushLabel *btn);
	void setIconLbl(QLabel *icon);
	void setTitleLbl(EPushLabel *title);
	void setDataLbl(QLabel *data);
	void setDateLbl(QLabel *date);
	void showDetail(bool f);

	QString titleText();

	protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void resizeEvent(QResizeEvent *e);

	private:
	QLabel *typeLbl;
	EPushLabel *extBtn;
	QLabel *iconLbl;
	EPushLabel *itemTitle;
	QLabel *dataLbl;
	//EPushLabel *closeLbl;
	//QLabel *chapterLbl;
	QLabel *dateLbl;

	EIType t;
	bool ext;//show detail or not
	
};

class QIcon;
class EPushLabel;
class QSignalMapper;
class EPageBar:public QFrame
{
	Q_OBJECT
	enum {BTN_COUNT=11};
	public:
	EPageBar(QWidget *parent);
	void buildUi();
	void refresh();
	void connectSignals();

	void setItemContainer(EItemContainer *itemContainer);//have problem,with signal

	signals:
		void pageSelected(int);

	protected:
		virtual void resizeEvent(QResizeEvent *e);
	public slots:
		void pageCntChanged(int);
		void pageSelect(int);
		void nextPageBtn();
		void lastPageBtn();

	private:
	//int m_maxPerPage;//items per page
	int m_curPg;
	int m_totalPg;
	int m_curBPg;
	QSignalMapper *m_signalMapper;
	QList<EPushLabel*> m_btns;//button count is BTN_COUNT; while page btn is index [1,9].
	QList<QIcon*> m_btnIcons;
	EItemContainer *m_itemContainer;
};

class EPushLabel:public QLabel
{
	Q_OBJECT
	public:
		EPushLabel(const QString &text, QWidget *parent = 0, Qt::WindowFlags f = 0)
			:QLabel(text, parent, f)
		{   
			;   
		}   
	signals:
		//void pressSignal(ClickLabel*);
		void pressSignal();
	protected:
		void mousePressEvent(QMouseEvent *event)
		{   
			if(rect().contains(event->pos())) { emit pressSignal(); }
		}   
};
#endif
