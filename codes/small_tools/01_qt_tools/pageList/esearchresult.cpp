#include "esearchresult.h"
#include <QSignalMapper>
#include <QIcon>
#include <QDebug>
#include <QTimer>
#include <QResizeEvent>
//ESearch::ESearch(QWidget *parent,Qt::WindowFlags f):QWidget(parent,f)
ESearch::ESearch(QWidget *parent):QWidget(parent)
{
	init();
}

void ESearch::init()
{
	//UI
	setWindowTitle("Search Results");
	setFixedSize(ESEARCH_WIDTH, ESEARCH_HEIGH);
	m_titleHeader = new QLabel("keywords",this);
	m_titleHeader->setFrameShape(QFrame::StyledPanel);

	m_itemContainer = new EItemContainer(this);
	m_itemContainer->setFrameShape(QFrame::StyledPanel);

	m_pageBar = new EPageBar(this);
	m_pageBar->setFrameShape(QFrame::StyledPanel);

	m_titleHeader->setGeometry(0, 0, width(), EHEADER_HEIGHT);
	m_pageBar->setGeometry(width()-EBAR_WIDTH, EHEADER_HEIGHT,
				EBAR_WIDTH, height() - EHEADER_HEIGHT);
	qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	qDebug()<<"set height of m_pageBar is:"<<height() - EHEADER_HEIGHT;
	qDebug()<<"m_pageBar's real height is:"<<m_pageBar->height();
	m_itemContainer->setGeometry(0, EHEADER_HEIGHT,
				width()-EBAR_WIDTH, height() - EHEADER_HEIGHT);

	//Signals,etc
	connect(m_itemContainer,SIGNAL(pageCntChanged(int)),this,SIGNAL(pageCntChanged(int)));
	connect(m_pageBar,SIGNAL(pageSelected(int)),this,SIGNAL(pageSelected(int)));

	connect(this,SIGNAL(pageSelected(int)),m_itemContainer,SLOT(pageSelected(int)));
	connect(this,SIGNAL(pageCntChanged(int)),m_pageBar,SLOT(pageCntChanged(int)));

	m_pageBar->setItemContainer(m_itemContainer);
	m_itemContainer->setPageBar(m_pageBar);

}


EItemContainer::EItemContainer(QWidget *parent):QStackedWidget(parent)
{
	init();
	//qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__<<"page count is:"<<m_pgCnt;
}

void EItemContainer::init()
{
	m_maxPerPg = MAX_PERPAGE;//to do
	m_pgCnt = 0;
	m_pageBar = NULL;

	//m_iCnt = 20;//to be modified for test
	for(int i = 0; i < TOTAL_ITEM; ++i)
	{
		addItem(new ESearchItem());
	}
	/*
	for(int i = 0; i < m_pgCnt - 1; ++i)
	{
		QWidget *subPg = new QWidget();
		this->addWidget(subPg);
	}
	*/
	m_pageBar = NULL;
	updateLayout();
}

void EItemContainer::updateLayout()
{
	QTimer::singleShot(0,this,SLOT(refresh()));
}
void EItemContainer::refresh()
{
	qDebug()<<"@@@@@@{"<<__PRETTY_FUNCTION__;

	//lvkai+{
	for(int i = 0; i < m_items.count(); ++i)
	{
		m_items[i]->setParent(0);
	}
	while(count()> 0)
	{
		QWidget *subPg = widget(0);
		removeWidget(subPg);
		delete subPg;
		subPg=NULL;
	}
	//lvkai+}
	//qDebug()<<"the height is:"<<height();
	for(int i = 0; i < m_pgCnt - 1; ++i)
	{
		//qDebug()<<"in loop1,i="<<i;
		/*
		QWidget *subPg = widget(i);
		if(!subPg)
		{
			//qDebug()<<"subPg Null";
			subPg = new QWidget();
			this->addWidget(subPg);
			for(int j = 0; j < m_maxPerPg; ++j)
			{
				ESearchItem *item=m_items[j + (i*m_maxPerPg)];
				qDebug()<<"item->title:"<<item->titleText();
				item->setParent(subPg);
				//item->parent();
				//m_items[j + (i*m_maxPerPg)]->setParent(subPg);
			}
		}
		*/
		QWidget *subPg = new QWidget();
		addWidget(subPg);

		//subPg->adjustSize();
		subPg->setGeometry(0,0,width(),height());
		for(int j = 0; j < m_maxPerPg; ++j)
		{
			qDebug()<<"j"<<j;
			qDebug()<<"item:"<<m_items[j + (i*m_maxPerPg)]->titleText();
			/*
				ESearchItem *item=m_items[j + (i*m_maxPerPg)];
				qDebug()<<"item->title:"<<item->titleText();
			*/
			m_items[j + (i*m_maxPerPg)]->setParent(subPg);//segment fault if i==11&&j==6
			m_items[j + (i*m_maxPerPg)]->setGeometry(0,
				j*(subPg->height()/m_maxPerPg),subPg->width(), 
				subPg->height()/m_maxPerPg);
		}
	}

	//last page
	//QWidget *subPg = widget(m_pgCnt-1);
	QWidget *subPg = new QWidget();
	addWidget(subPg);
	int index = (m_pgCnt-1)*m_maxPerPg;

	int lstC = m_items.count() % m_maxPerPg;
	/*if(!subPg)
	{
		subPg = new QWidget();
		this->addWidget(subPg);
		for(int i = 0; i < (lstC==0?m_maxPerPg:lstC); ++i)
		{
			m_items[i + index]->setParent(subPg);
		}
	}
	*/

	if(lstC == 0)
	{
		for(int i = 0; i < m_maxPerPg; ++i)
		{
			m_items[index + i]->setParent(subPg);
			m_items[index + i]->setGeometry(0, i * (subPg->height()/m_maxPerPg),
					subPg->width(), subPg->height()/m_maxPerPg);
		}
	}
	else
	{
		for(int i = 0; i < lstC; ++i)
		{
			m_items[index + i]->setParent(subPg);
			m_items[index + i]->setGeometry(0, i * (subPg->height()/m_maxPerPg),
					subPg->width(), subPg->height()/m_maxPerPg);
		}
	}
	setCurrentIndex(0);
	emit pageCntChanged(m_pgCnt);
	qDebug()<<"@@@@@@}"<<__PRETTY_FUNCTION__;
}

void EItemContainer::resizeEvent(QResizeEvent *e)
{
	updateLayout();
	e->ignore();
}

void EItemContainer::deleteItem(int index)
{//not safe
	qDebug()<<"index is:"<<index;

	if(index < m_items.count())
	{
		m_items.removeAt(index);
	}
	if(m_items.count()>0)
	{
		m_pgCnt = (m_items.count()-1) / m_maxPerPg + 1;
	}
	else
	{
		m_pgCnt = 0;
	}
}

void EItemContainer::addItem(ESearchItem *item)
{
	m_items<<item;
	m_pgCnt = (m_items.count()-1) / m_maxPerPg + 1;
	//++m_iCnt;
}

void EItemContainer::setPageBar(EPageBar *pageBar)
{
	m_pageBar = pageBar;
	emit pageCntChanged(m_pgCnt);//tell pagebar the pages
}

void EItemContainer::pageSelected(int page)
{
	qDebug()<<"In:"<<__PRETTY_FUNCTION__<<",set page to:"<<page;
	if(page > 0 && page <= m_pgCnt)
	{
		setCurrentIndex(page - 1);
	}
	else
	{
		qDebug()<<"some error in:"<<__PRETTY_FUNCTION__;
	}
}

ESearchItem::ESearchItem(QWidget *parent):QWidget(parent)
{
	typeLbl = NULL;
	extBtn = NULL;
	iconLbl = NULL;
	itemTitle = NULL;
	dataLbl = NULL;
	dateLbl = NULL;
	t = BOOKS;
	ext = false;
	defaultUi();
}
void ESearchItem::defaultUi()
{
#if MY_DEBUG_CNT == 1
	static int testCount = 0;
	++testCount;
	if(testCount>EItemContainer::TOTAL_ITEM)
		testCount=0;
#endif
	//qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	//qDebug()<<"the height is:"<<height();
	typeLbl = new QLabel("Books", this);
	typeLbl->setFrameShape(QFrame::StyledPanel);

	extBtn = new EPushLabel("ext", this);
	iconLbl = new QLabel("icon", this);
#if MY_DEBUG_CNT == 1
	itemTitle = new EPushLabel(QString("title%1").arg(testCount), this);
#else
	itemTitle = new EPushLabel("title0", this);
#endif
	dataLbl = new QLabel("data", this);
	dateLbl = new QLabel("date", this);
	t = BOOKS;
	ext = false;
	refresh();
}

void ESearchItem::refresh()
{
	//may be changed to grid layout
	typeLbl->setGeometry(0,0,width(),height()/3);
	extBtn->setGeometry(0,height()/3,height()/3,height()/3*2);
	iconLbl->setGeometry(0,0,0,0);//not show icon now
	itemTitle->setGeometry(height()/3,height()/3,width()-height()/3,height()/3);
	dataLbl->setGeometry(height()/3,height()/3<<1,width()-height()/3,height()/3);
	dateLbl->setGeometry(0,0,0,0);//not show date now
}

void ESearchItem::setType(EIType t)
{
	this->t = t;
}
ESearchItem::EIType ESearchItem::getType()const
{
	return t;
}
void ESearchItem::setExtBtn(EPushLabel *btn)
{
	if(extBtn != NULL)
	{
		delete extBtn;
		extBtn = NULL;
	}
	extBtn = btn;
}
void ESearchItem::setIconLbl(QLabel *icon)
{
	if(iconLbl != NULL)
	{
		delete iconLbl;
		iconLbl = NULL;
	}
	iconLbl = icon;
}
void ESearchItem::setTitleLbl(EPushLabel *title)
{
	if(itemTitle != NULL)
	{
		delete itemTitle;
		itemTitle = NULL;
	}
	itemTitle = title;
}
QString ESearchItem::titleText()
{
	return itemTitle->text();
}
void ESearchItem::setDataLbl(QLabel *data)
{
	if(dataLbl != NULL)
	{
		delete dataLbl;
		dataLbl = NULL;
	}
	dataLbl = data;
}
void ESearchItem::setDateLbl(QLabel *date)
{
	if(dateLbl != NULL)
	{
		delete dateLbl;
		dateLbl = NULL;
	}
	dateLbl = date;
}
void ESearchItem::showDetail(bool f)
{
	ext = f;
}
void ESearchItem::mousePressEvent(QMouseEvent *event)
{   
	if(rect().contains(event->pos())) { qDebug()<<"pressed item"; }
}

void ESearchItem::resizeEvent(QResizeEvent *event)
{
	refresh();
	event->ignore();
}


EPageBar::EPageBar(QWidget *parent):QFrame(parent)
{
	m_signalMapper = NULL;
	m_itemContainer = NULL;
	m_curPg = 1;
	m_curBPg = 1;

	buildUi();
	qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	qDebug()<<"height() is"<<height();
	connectSignals();
}

void EPageBar::resizeEvent(QResizeEvent *e)
{
	buildUi();
	e->ignore();
}
void EPageBar::buildUi()
{
	if(!m_signalMapper)
	{
		m_signalMapper = new QSignalMapper(this);
	}
	if(m_btns.count() == 0)
	{
		for(int i = 0; i < BTN_COUNT; ++i)
		{
			m_btns<<new EPushLabel(" ", this);
		}
		m_btns[0]->setText("^");
		for(int i = 1; i < m_btns.count()-1;++i)
		{
			m_btns[i]->setText(
				QString("%1").arg((m_curBPg-1)*(m_btns.count()-2)+i));
		}
		m_btns[m_btns.count()-1]->setText("v");
	}
	qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	qDebug()<<"height is:"<<height();
	qDebug()<<"btn count is:"<<m_btns.count();

	refresh();

}

void EPageBar::refresh()
{
	m_btns[0]->setGeometry(0,0, width(), height()/15);
	//m_btns[0]->setText("^");

	for(int i = 1; i < m_btns.count() -1; ++i)
	{
		m_btns[i]->setGeometry(0,i * (height()/15), width(), height()/15);
	}

	m_btns[m_btns.count()-1]->setGeometry(0,height()-height()/15,
						width(), height()/15);
	m_btns[m_btns.count()-1]->setText("v");
#if 0
	for(int i = 0; i < BTN_COUNT; ++i)
	{
		m_btnIcons<<QIcon();
	}
#endif
}
void EPageBar::connectSignals()
{
	connect(m_btns[0],SIGNAL(pressSignal()),this,SLOT(lastPageBtn()));
	connect(m_btns[m_btns.count()-1],SIGNAL(pressSignal()),this,SLOT(nextPageBtn()));

	connect(m_signalMapper, SIGNAL(mapped(int)),
			this, SLOT(pageSelect(int)));
	for(int i = 1; i < m_btns.count()-1; ++i)
	{
		m_signalMapper->setMapping(m_btns[i],i);
		connect(m_btns[i],SIGNAL(pressSignal()),m_signalMapper,SLOT(map()));
	}
}

void EPageBar::lastPageBtn()
{
	qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	//if(m_curPg >  m_btns.count() - 2)
	if(m_curBPg > 1)
	{
		qDebug()<<"press last page";
		refresh();
		--m_curBPg;
		m_btns[0]->setText("^");
		for(int i = 1; i < m_btns.count()-1; ++i)
		{
			m_btns[i]->setText(
				QString("%1").arg((m_curBPg-1)*(m_btns.count()-2)+i));
			m_signalMapper->setMapping(m_btns[i],
					i+(m_curBPg-1)*(m_btns.count()-2));
		}
		m_btns[m_btns.count()-1]->setText("v");
	}
}

void EPageBar::nextPageBtn()
{
	qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	qDebug()<<"press next page";
	qDebug()<<"m_totalPg:"<<m_totalPg;
	qDebug()<<"m_curBPg:"<<m_curBPg;
	qDebug()<<"max BPg:"<<(m_totalPg-1)/(m_btns.count()-2)+1;
	//if((m_curPg - 1)/(m_btns.count()-2) < m_totalPg/(m_btns.count()-2))
	if(m_curBPg < (m_totalPg-1)/(m_btns.count()-2)+1)
	{
		refresh();
		++m_curBPg;
		//int curBtnPg = (m_curPg -1)/(m_btns.count()-2);
		m_btns[0]->setText("^");
		for(int i = 1; i < m_btns.count()-1; ++i)
		{
			m_btns[i]->setText(
				QString("%1").arg((m_curBPg-1)*(m_btns.count()-2)+i));
			m_signalMapper->setMapping(m_btns[i],
					i+(m_curBPg-1)*(m_btns.count()-2));
		}
		m_btns[m_btns.count()-1]->setText("v");
	}
}

void EPageBar::pageSelect(int page)
{
	qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	qDebug()<<"selected page is:"<<page;
	m_curPg = page;
	refresh();
	emit pageSelected(page);
}

void EPageBar::setItemContainer(EItemContainer *itemContainer)
{
	m_itemContainer = itemContainer;
}

void EPageBar::pageCntChanged(int count)
{
	qDebug()<<"@@@@@@"<<__PRETTY_FUNCTION__;
	qDebug()<<"total page is"<<count;
	m_totalPg = count;
}
