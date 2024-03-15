#pragma once

#include <QApplication>
#include <QObject>
#include <QResizeEvent>
#include <QShowEvent>
#include <QString>
#include <QVector>
#include <QMap>
#include <QList>
#include <QPair>
#include <QTime>
#include <QStringList>
#include <QDateTime>
#include <QTimer>
#include <QDate>
#include <QByteArray>
#include "QProcess"
#include <QDebug>
#include <QWindow>
#include "QWidget"
#include <QDialog>
#include <QFileDialog>
#include <QThread>
#include <QDir>
#include <QSharedMemory>
#include <QtEndian>
#include <QComboBox>
#include <QPushButton>
#include <QVariant>
#include <QByteArray>
#include <QMessageBox>
#include <QFontDatabase>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include <QMutexLocker>
#include <QMutex>
#include <QWaitCondition>
#include <QByteArray>
#include <QLibrary>
#include <QButtonGroup>
#include <string>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <QSvgGenerator>
#include <chrono> // for std::chrono::system_clocks
#include <cstdlib> // for srand() and rand()
#include <ctime>   // for time()

using namespace std;
namespace SudokuData
{

#define side 9

#define UNASSIGNED 0

	class Sudoku {
		
    public:
        int actualSolution = 0;
        int guessNum[9];
        int gridPos[81];
        int difficultyLevel;
        bool grid_status;

        int grid[side][side] = {
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0}
        };


        int previousGrid[side][side] = {
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

        int solnGrid[side][side] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

	public:
		Sudoku();
	};

}
