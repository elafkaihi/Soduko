#pragma once
#include "constdef.h"
#include <QWidget>

class CExtraWnd : public QWidget
{
	Q_OBJECT

public:
	CExtraWnd(QWidget *parent);
    ~CExtraWnd();

	enum 
	{
		en_Margin = 10,
		en_CellSize = 45,
		en_CellUnit = 9,
		en_WndHeight = en_CellSize * en_CellUnit + 2 * en_Margin,
	};

protected:

	void InitWnd();

	void resizeEvent(QResizeEvent *event);

	void DrawClueData(QPainter& painter, int& nVal,QRect& rect);
	void DrawViewData(QPainter& painter, int& nVal, QRect& rect);
	

private:

	QRect m_rcAvailable;
	SudokuData::Sudoku m_sudoku;

	QPen m_cluePen;
	QBrush m_clueBrush;

	QPen m_viewPen;
	QBrush m_viewBrush;

};
