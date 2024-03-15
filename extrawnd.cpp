#include "extrawnd.h"

CExtraWnd::CExtraWnd(QWidget *parent)
	: QWidget(parent)
{
	this->InitWnd();
}

CExtraWnd::~CExtraWnd()
{

}

void CExtraWnd::InitWnd()
{
	m_cluePen.setColor(Qt::white);
    m_clueBrush.setColor(Qt::gray);

	m_viewPen.setColor(Qt::black);
	m_viewBrush.setColor(QColor(255, 192, 203));
}

void  CExtraWnd::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
	QSize szClient = QWidget::size();
	if (szClient.height() == 0)
	{
		m_rcAvailable.setHeight(0);
		return;
	}
	m_rcAvailable = QRect( (szClient.width() - 2 * en_Margin - en_CellUnit * en_CellSize)/2+10, en_Margin, en_CellUnit*en_CellSize, en_CellUnit*en_CellSize);
}

void CExtraWnd::DrawClueData(QPainter& painter, int& nVal, QRect& rect)
{
	painter.save();
	QRect rc = rect.adjusted(1, 1, -1, -1);
	QFont ft = painter.font();
	painter.setPen(Qt::NoPen);
    painter.fillRect(rc, Qt::gray);
	painter.setPen(m_cluePen);
	ft.setPixelSize(18);
	ft.setBold(true);
	painter.setFont(ft);
	painter.drawText(rc, Qt::AlignCenter, QString::number(nVal));
	painter.restore();
}

void CExtraWnd::DrawViewData(QPainter& painter, int& nVal, QRect& rect)
{
	painter.save();
	QRect rc = rect.adjusted(1, 1, -1, -1);
	QFont ft = painter.font();
	painter.setPen(Qt::NoPen);
	painter.fillRect(rc, QColor(255, 192, 203));
	painter.setPen(m_viewPen);
	ft.setPixelSize(18);
	ft.setBold(true);
	painter.setFont(ft);
	painter.drawText(rc, Qt::AlignCenter, QString::number(nVal));
	painter.restore();
}
