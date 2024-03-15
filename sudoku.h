#pragma once
#include <QtWidgets>
#include "inputcell.h"
#include "ui_sudoku.h"

#define UNASSIGNED 0


using namespace std;

class Sudoku : public QWidget
{
	Q_OBJECT

public:
	Sudoku(QWidget *parent = Q_NULLPTR);
    Sudoku (string, bool row_major=true);
    ~Sudoku();

protected:

	void Init();
	void InitCtrl();
	void InitVar();

    void showEvent(QShowEvent *event);

	// Set GUI Data
	void SetGUIInitHint();

protected Q_SLOTS:

    void SlotSubmitData(int nRow, int nCol, const QString& strText, CInputCell* pCell);

private slots:

    void on_pushButton_save_clicked();

    void on_pushButton_viewresult_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_new_clicked();

private:
    Ui::SudokuClass ui;
    QVector<QString> solutions;

	bool m_blFirstShow;

	QVector<CInputCell*> m_vectR0;
	QVector<CInputCell*> m_vectR1;
	QVector<CInputCell*> m_vectR2;
	QVector<CInputCell*> m_vectR3;
	QVector<CInputCell*> m_vectR4;
	QVector<CInputCell*> m_vectR5;
	QVector<CInputCell*> m_vectR6;
	QVector<CInputCell*> m_vectR7;
	QVector<CInputCell*> m_vectR8;
	QVector<CInputCell*> m_vectCell;

//	CExtraWnd* m_pExtraWnd;
    QPushButton* m_pViewResult;
    QPushButton* m_pSave;
    QPushButton* m_pLoad;
    QPushButton* m_pNew;
    QComboBox* m_comboBox;

    SudokuData::Sudoku m_sudoku;

    void fillEmptyDiagonalBox(int);
    bool solveGrid();
    string getGrid();
    void countSoln(int &number);
    bool verifyGridStatus();
    int  branchDifficultyScore();
    bool FindUnassignedLocation(int grid[9][9], int &row, int &col);
    bool UsedInRow(int grid[9][9], int row, int num);
    bool UsedInCol(int grid[9][9], int col, int num);
    bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num);
    bool isSafe(int grid[9][9], int row, int col, int num);

    void createSeed();
    void genPuzzle(QString level);
    void printSVG();
    void calculateDifficulty();
    void printGrid();
    int generateRandomDifficultyLevel(QString level);
};
