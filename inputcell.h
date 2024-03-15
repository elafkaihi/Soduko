#pragma once
#include "constdef.h"
#include <QLineEdit>

class CInputCell : public QLineEdit
{
	Q_OBJECT

public:
	CInputCell(QWidget *parent);
	~CInputCell();

	void InitCell();

	void SetPos(int nRow, int nCol);
	void GetPos(int& nRow, int& nCol);

	void SetClueMode(const QString& strText);
	void SetViewMode(const QString& strText);
	void SetInputMode(const QString& strText);

    void SetClueModeError(const QString &strText);
protected:

	void keyPressEvent(QKeyEvent * event);

	void focusInEvent(QFocusEvent * event);
	void focusOutEvent(QFocusEvent * event);

protected Q_SLOTS:

	void  SlotTextChanged(const QString &text);

Q_SIGNALS:

	void SignalSubmitData(int nRow,int nCol, const QString& strText ,CInputCell* pCell);
	
private:

	int m_nRow;
	int m_nCol;

	QString m_strCurrentText;

};
