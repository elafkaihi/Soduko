
#include "inputcell.h"

CInputCell::CInputCell(QWidget *parent)
	: QLineEdit(parent)
{

}

CInputCell::~CInputCell()
{

}

void CInputCell::InitCell()
{
	QString strLineEditStyle = ""
        "QLineEdit { qproperty-alignment:AlignHCenter;  font:bold ; font-size: 18px;  border:1px solid #B0B0B0; color:rgba(0,0,0,200); background-color:rgb(255,255,255); }"
		"QLineEdit:hover { border:1px solid #707070;background-color:#F7F7F7; }"
		"QLineEdit:focus { border:1px solid #1274B7;color:rgba(0,0,0,200); }   "
		"QLineEdit:disabled { border:1px solid lightgray;color:white;background-color:gray; }   "
		;
	this->setStyleSheet(strLineEditStyle);
	QIntValidator* pIntV = new QIntValidator(1, 9, this);
	this->setValidator(pIntV);
	this->setMaxLength(1);
	QObject::connect(this, &QLineEdit::textChanged, this, &CInputCell::SlotTextChanged);
}


void  CInputCell::SlotTextChanged(const QString &text)
{
	if (!text.isEmpty() && text.toInt() == 0)
	{
		this->backspace();
	}
}

void   CInputCell::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
	{
		this->clearFocus();
	}
	QLineEdit::keyPressEvent(event);
}

void CInputCell::SetPos(int nRow, int nCol)
{
	m_nRow = nRow;
	m_nCol = nCol;
}

void CInputCell::GetPos(int& nRow, int& nCol)
{
	nRow = m_nRow;
	nCol = m_nCol;
}

void CInputCell::focusInEvent(QFocusEvent * event)
{
	m_strCurrentText = this->text();
	QLineEdit::focusInEvent(event);
}


void CInputCell::focusOutEvent(QFocusEvent * event)
{
	QString strNewText = this->text();
	if (strNewText != m_strCurrentText)
	{
		emit SignalSubmitData(m_nRow, m_nCol, strNewText, this);
	}
	QLineEdit::focusOutEvent(event);
}

void CInputCell::SetClueMode(const QString& strText)
{
	QString strLineEditStyle = ""
        "QLineEdit { qproperty-alignment:AlignHCenter;  font:bold ; font-size: 18px;  border:1px solid #B0B0B0; color:rgba(0,0,0,200); background-color:rgb(255,255,255); }"
		"QLineEdit:hover { border:1px solid #707070;background-color:#F7F7F7; }"
		"QLineEdit:focus { border:1px solid #1274B7;color:rgba(0,0,0,200); }   "
		"QLineEdit:disabled { border:1px solid lightgray;color:white;background-color:gray; }   "
		;
	this->setStyleSheet(strLineEditStyle);
	this->setEnabled(false);
	QLineEdit::setText(strText);
}
void CInputCell::SetClueModeError(const QString& strText)
{
    QString strLineEditStyle = ""
        "QLineEdit { qproperty-alignment:AlignHCenter;  font:bold ; font-size: 18px;  border:1px solid #B0B0B0; color:rgba(0,0,0,200); background-color:rgb(255,255,255); }"
        "QLineEdit:hover { border:1px solid #707070;background-color:#F7F7F7; }"
        "QLineEdit:focus { border:1px solid #1274B7;color:rgba(0,0,0,200); }   "
        "QLineEdit:disabled { border:1px solid lightgray;color:white;background-color:red; }   "
        ;
    this->setStyleSheet(strLineEditStyle);
    this->setEnabled(false);
    QLineEdit::setText(strText);
}
void CInputCell::SetViewMode(const QString& strText)
{
	QString strLineEditStyle = ""
        "QLineEdit { qproperty-alignment:AlignHCenter;  font:bold ; font-size: 18px;  border:1px solid #B0B0B0; color:rgba(0,0,0,200); background-color:rgb(255,255,255); }"
		"QLineEdit:hover { border:1px solid #707070;background-color:#F7F7F7; }"
		"QLineEdit:focus { border:1px solid #1274B7;color:rgba(0,0,0,200); }   "
		"QLineEdit:disabled { border:1px solid lightgray;color:black;background-color:rgb(255,192,203); }   "
		;
	this->setStyleSheet(strLineEditStyle);
	this->setEnabled(false);
	QLineEdit::setText(strText);
}

void CInputCell::SetInputMode(const QString& strText)
{
	QString strLineEditStyle = ""
        "QLineEdit { qproperty-alignment:AlignHCenter;  font:bold ; font-size: 18px;  border:1px solid #B0B0B0; color:rgba(0,0,0,200); background-color:rgb(255,255,255); }"
		"QLineEdit:hover { border:1px solid #707070;background-color:#F7F7F7; }"
		"QLineEdit:focus { border:1px solid #1274B7;color:rgba(0,0,0,200); }   "
		"QLineEdit:disabled { border:1px solid lightgray;color:white;background-color:gray; }   "
		;
	this->setStyleSheet(strLineEditStyle);
	this->setEnabled(true);
	QLineEdit::setText(strText);
}
