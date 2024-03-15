#include "sudoku.h"


Sudoku::Sudoku(QWidget *parent)
	: QWidget(parent), m_blFirstShow(false)
{
	ui.setupUi(this);
	this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->Init();

    //On initialise une variable qui va etre le niveau de difficultée avec une valeur initiale  0 qui est le plus simple
    //On va utiliser cette variable pour générer des grilles de soduko selon le niveau de difficulté demandé
    m_sudoku.difficultyLevel = 0;

    //On fait une boucle pour donner une position pour les différentes cases de la grille
    for(int i=0;i<81;i++)
    {
        m_sudoku.gridPos[i] = i;
    }

    //On fait un shuffling de la grid des positions
    random_shuffle(m_sudoku.gridPos, (m_sudoku.gridPos) + 81);

    // Ici on crée une liste des nombres de 1 à 9 , cette liste va présenter un box
    for(int i=0;i<9;i++)
    {
        m_sudoku.guessNum[i]=i+1;
    }

    // A chaque fois on va le Shuffler pour avoir une nouvelle proposition
    random_shuffle(m_sudoku.guessNum, (m_sudoku.guessNum) + 9);

    // ici une variable boolean qui va nous garantir que les 3 critères d'une grilles sont bien validés
    m_sudoku.grid_status = true;
}

Sudoku::~Sudoku()
{

}

//initialisateur de GUI
void Sudoku::Init()
{
    this->InitCtrl();
    this->InitVar();
}

//initialisateur de UI
void Sudoku::InitCtrl()
{
    int nRow = 0;
    m_vectR0 << ui.lineEdit_r0_0 << ui.lineEdit_r0_1 << ui.lineEdit_r0_2 << ui.lineEdit_r0_3<< ui.lineEdit_r0_4<< ui.lineEdit_r0_5<< ui.lineEdit_r0_6<< ui.lineEdit_r0_7<< ui.lineEdit_r0_8;
    for (int i=0;i < m_vectR0.size();i++)
    {
        m_vectR0[i]->SetPos(nRow, i);
    }

    m_vectR1 << ui.lineEdit_r1_0 << ui.lineEdit_r1_1 << ui.lineEdit_r1_2 << ui.lineEdit_r1_3 << ui.lineEdit_r1_4 << ui.lineEdit_r1_5 << ui.lineEdit_r1_6 << ui.lineEdit_r1_7 << ui.lineEdit_r1_8;
    ++nRow;
    for (int i = 0; i < m_vectR1.size(); i++)
    {
        m_vectR1[i]->SetPos(nRow, i);
    }
	
    m_vectR2 << ui.lineEdit_r2_0 << ui.lineEdit_r2_1 << ui.lineEdit_r2_2 << ui.lineEdit_r2_3 << ui.lineEdit_r2_4 << ui.lineEdit_r2_5 << ui.lineEdit_r2_6 << ui.lineEdit_r2_7 << ui.lineEdit_r2_8;
    ++nRow;
    for (int i = 0; i < m_vectR2.size(); i++)
    {
        m_vectR2[i]->SetPos(nRow, i);
    }

    m_vectR3 << ui.lineEdit_r3_0 << ui.lineEdit_r3_1 << ui.lineEdit_r3_2 << ui.lineEdit_r3_3 << ui.lineEdit_r3_4 << ui.lineEdit_r3_5 << ui.lineEdit_r3_6 << ui.lineEdit_r3_7 << ui.lineEdit_r3_8;
    ++nRow;
    for (int i = 0; i < m_vectR3.size(); i++)
    {
        m_vectR3[i]->SetPos(nRow, i);
    }

    m_vectR4 << ui.lineEdit_r4_0 << ui.lineEdit_r4_1 << ui.lineEdit_r4_2 << ui.lineEdit_r4_3 << ui.lineEdit_r4_4 << ui.lineEdit_r4_5 << ui.lineEdit_r4_6 << ui.lineEdit_r4_7 << ui.lineEdit_r4_8;
    ++nRow;
    for (int i = 0; i < m_vectR4.size(); i++)
    {
        m_vectR4[i]->SetPos(nRow, i);
    }

    m_vectR5 << ui.lineEdit_r5_0 << ui.lineEdit_r5_1 << ui.lineEdit_r5_2 << ui.lineEdit_r5_3 << ui.lineEdit_r5_4 << ui.lineEdit_r5_5 << ui.lineEdit_r5_6 << ui.lineEdit_r5_7 << ui.lineEdit_r5_8;
    ++nRow;
    for (int i = 0; i < m_vectR5.size(); i++)
    {
        m_vectR5[i]->SetPos(nRow, i);
    }

    m_vectR6 << ui.lineEdit_r6_0 << ui.lineEdit_r6_1 << ui.lineEdit_r6_2 << ui.lineEdit_r6_3 << ui.lineEdit_r6_4 << ui.lineEdit_r6_5 << ui.lineEdit_r6_6 << ui.lineEdit_r6_7 << ui.lineEdit_r6_8;
    ++nRow;
    for (int i = 0; i < m_vectR6.size(); i++)
    {
        m_vectR6[i]->SetPos(nRow, i);
    }

    m_vectR7 << ui.lineEdit_r7_0 << ui.lineEdit_r7_1 << ui.lineEdit_r7_2 << ui.lineEdit_r7_3 << ui.lineEdit_r7_4 << ui.lineEdit_r7_5 << ui.lineEdit_r7_6 << ui.lineEdit_r7_7 << ui.lineEdit_r7_8;
    ++nRow;
    for (int i = 0; i < m_vectR7.size(); i++)
    {
        m_vectR7[i]->SetPos(nRow, i);
    }

    m_vectR8 << ui.lineEdit_r8_0 << ui.lineEdit_r8_1 << ui.lineEdit_r8_2 << ui.lineEdit_r8_3 << ui.lineEdit_r8_4 << ui.lineEdit_r8_5 << ui.lineEdit_r8_6 << ui.lineEdit_r8_7 << ui.lineEdit_r8_8;
    ++nRow;
    for (int i = 0; i < m_vectR8.size(); i++)
    {
        m_vectR8[i]->SetPos(nRow, i);
    }

    m_vectCell  << m_vectR0 << m_vectR1 << m_vectR2 << m_vectR3 << m_vectR4 << m_vectR5 << m_vectR6 << m_vectR7<<m_vectR8;
    for(auto var : m_vectCell)
    {
        var->InitCell();
        var->setText("");
        QObject::connect(var, &CInputCell::SignalSubmitData, this, &Sudoku::SlotSubmitData);
    }

	QString strButStyle = QString(
		"QPushButton       { border-radius: 5px;  border: 2px solid rgba(44, 61, 113,120);  color : #FFFFFF; background: rgba(10,10,255,225); }"
		" QPushButton:focus{ padding: -1; } "
		"QPushButton:disabled    {background: gray;}"
		"QPushButton:hover  {border: none; background:  rgb(44, 61, 113) ;}"
		"QPushButton:pressed{border:none;}"
		"QPushButton:checked        {border: none;background: rgb(216,30,6);}"
		"QPushButton:checked:hover  {border: none; background: rgb(150,30,6) ; } "
		"QPushButton:checked:pressed{border: none;}"
	);

    m_pViewResult = ui.pushButton_viewresult;
    m_pViewResult->setStyleSheet(strButStyle);

    m_pSave = ui.pushButton_save;
    m_pSave->setStyleSheet(strButStyle);

    m_pLoad = ui.pushButton_load;
    m_pLoad->setStyleSheet(strButStyle);

    m_pNew = ui.pushButton_new;
    m_pNew->setStyleSheet(strButStyle);

    m_comboBox = ui.comboBox;
	
	ui.scrollArea->setWidgetResizable(true);
}

//Initialisateur de la grille
void Sudoku::InitVar()
{
    this->SetGUIInitHint();
}

void Sudoku::showEvent(QShowEvent *event)
{
    if (!m_blFirstShow)
    {
        m_blFirstShow = true;
    }
    QWidget::showEvent(event);
}

// event on input data
void Sudoku::SlotSubmitData(int nRow, int nCol, const QString& strText, CInputCell* pCell)
{
    //get cell value
	int nVal = strText.toInt();

    //Check if cell's data is valid
    if(!isSafe(m_sudoku.grid, nRow, nCol, m_sudoku.guessNum[nVal])){
        pCell->SetClueModeError(QString::number(nVal));
    }else{
        m_sudoku.grid[nRow][nCol] = nVal;
        //m_sudoku.previousGrid[nRow][nCol] = nVal;
        pCell->SetClueMode(QString::number(nVal));
    }
}

void Sudoku::SetGUIInitHint()
{
    for(auto var : m_vectCell)
    {
        var->setText("");
        int nRow, nCol;
        var->GetPos(nRow, nCol);
        var->SetInputMode("");
    }

    for(int i = 0; i<9; i++)
        for(int j = 0; j <9; j++) {
            m_sudoku.grid[i][j]= 0;
        }
}

// On définit une fonction qui nous cherche s'il existe des cases vides
bool Sudoku::FindUnassignedLocation(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == UNASSIGNED)
                return true;
        }
    }

    return false;
}
// On définit trois fonnctions afin de s'assurer respectivement que chaque ligne , column et box
//sont valides
bool Sudoku::UsedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
            return true;
    }

    return false;
}

bool Sudoku::UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
            return true;
    }

    return false;
}

bool Sudoku::UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }

    return false;
}

//cette fonction va englobaliser les 3 fonctions précédents pour dire si la position
//d'un numéro est correct
bool Sudoku::isSafe(int grid[9][9], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row%3 , col - col%3, num);
}


//fonction d'affichage de la grille dans la sortie de l'application comme un string
string Sudoku::getGrid()
{
    string s = "";
    for(int row_num=0; row_num<9; ++row_num)
    {
        for(int col_num=0; col_num<9; ++col_num)
        {
            s = s + to_string( m_sudoku.grid[row_num][col_num]);
        }
    }

    return s;
}

// Comme les 3 boxes diagonales sont indépendants deux à deux on commence par les remplire avec
// des valeurs random en faisant shuffle à l'array guessNum
void Sudoku::fillEmptyDiagonalBox(int idx)
{
    int start = idx*3;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(m_sudoku.guessNum, m_sudoku.guessNum + 9, std::default_random_engine(seed));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m_sudoku.grid[start+i][start+j] = m_sudoku.guessNum[i*3+j];
        }
    }
}


void Sudoku::createSeed()
{
    /* On remplit les 3 boxes diagonales
      x | . | .
      . | x | .
      . | . | x
  */
    this->fillEmptyDiagonalBox(0);
    this->fillEmptyDiagonalBox(1);
    this->fillEmptyDiagonalBox(2);

    /* On remplit les cases restants en utilisant la méthode de solvegrid:
      x | x | x
      x | x | x
      x | x | x
  */
    this->solveGrid();
    // on enregistre la solution de la grid
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            m_sudoku.solnGrid[i][j] = m_sudoku.grid[i][j];
        }
    }
}

// verifier la grille s'il est bien homogène vis à vis les 3 contraintes
bool Sudoku::verifyGridStatus()
{
    return m_sudoku.grid_status;
}
// END: Verification of the custom grid passed

// afficher la grille dans le terminal
void Sudoku::printGrid()
{
    for(int i=0;i<9;i++)
    {
        QString strRow = "";
        for(int j=0;j<9;j++)
        {
            int value = m_sudoku.grid[i][j];
            //m_sudoku.previousGrid[i][j] = value;
            if(value == 0) {
                strRow += ".|";
                m_vectCell[i * 9 + j]->SetInputMode("");
            }
            else {
                strRow += QString::number(value) + "|";
                m_vectCell[i * 9 + j]->SetViewMode(QString::number(value));
            }
        }
        qDebug() << strRow;
    }

    qDebug() << "Difficulté de la  grille : "<< m_sudoku.difficultyLevel;
    qDebug() << "";
}
//solveur de la grille d'une manière récursive
bool Sudoku::solveGrid()
{
    int row, col;

    // si tous les cases sont remplis on est okay
    if (!FindUnassignedLocation(m_sudoku.grid, row, col))
        return true; // success!

    // sinon on prend les nombres de 1 à 9
    for (int num = 0; num < 9; num++)
    {
        // On teste la valeur num avec isSafe
        if (isSafe(m_sudoku.grid, row, col, m_sudoku.guessNum[num]))
        {
            m_sudoku.grid[row][col] = m_sudoku.guessNum[num];

            // on fait un appel récursif , si ca marche on retourne true
            if (solveGrid())
                return true;

            // Sinon on change la valeur de num dans la position (row , col).
            m_sudoku.grid[row][col] = UNASSIGNED;
        }
    }

    return false; // si on ne trouve pas de solution on retourne false

}

//la grille de soduko de l'utilisateur doit avoir une solution unique pour ce faire on définit
//une fonction qui compte les solutions possible d'une grille
void Sudoku::countSoln(int &number)
{
    int row, col;

    if(!FindUnassignedLocation(m_sudoku.grid, row, col))
    {
        number++;
        return ;
    }


    for(int i=0;i<9 && number<2;i++)
    {
        if( isSafe(m_sudoku.grid, row, col, m_sudoku.guessNum[i]) )
        {
            m_sudoku.grid[row][col] = m_sudoku.guessNum[i];
            countSoln(number);
        }

        m_sudoku.grid[row][col] = UNASSIGNED;
    }

}

// Ici on génère le puzzle selon la difficulté à l'aide de l'indice difficultylevel avec des
//intervalles approximatives
void Sudoku::genPuzzle(QString level)
{
    int difficultyLevel = 0;

    if (level == "Débutant") {
        srand(time(nullptr));
        difficultyLevel = rand() % 601;
    }
    else if (level == "Intermédiaire") {
        srand(time(nullptr));
    difficultyLevel = rand() % 401 + 600;
    }
    else {
        srand(time(nullptr));
        difficultyLevel = rand() % 1001 + 1000;
    }

    // Générer une liste de toutes les positions de cellule
    std::vector<int> positions;
    for (int i = 0; i < 81; i++) {
        positions.push_back(i);
    }

    // on fait un shuffle pour les positions
    std::random_shuffle(positions.begin(), positions.end());

    // on supprime les cases jusque arriver à la difficulter voulu
    for (int i = 0; i < positions.size(); i++) {
        int pos = positions[i];
        int x = pos / 9;
        int y = pos % 9;

        int temp = m_sudoku.grid[x][y];
        m_sudoku.grid[x][y] = UNASSIGNED;

        // on vérifie s'il a toujours une solution unique
        int check = 0;
        countSoln(check);

        if (check != 1) {
            // s'il n ' y a pas une unique solution on remets la dernière case supprimée
            m_sudoku.grid[x][y] = temp;
        } else {
            // Sinon on continue avec le calcul de la defficulté
            calculateDifficulty();

            if (m_sudoku.difficultyLevel >= difficultyLevel) {
                // Si on obtient le niveau de difficulté minimum voulu on sort de la boucle
                break;
            }
        }
    }

}

// Sauvegarde du fichier sous format SVG:
void Sudoku::printSVG()
{
    // choisir le nom de fichier pour le sauvegarde
    QString path = QFileDialog::getSaveFileName(nullptr, "Save SVG", QDir::homePath(), "SVG Files (*.svg)");

    // Create an SVG generator object and set the output filename and size
    QSvgGenerator svgGen;
    svgGen.setFileName(path);
    svgGen.setSize(QSize(550, 550));

    //  SVG document
    QPainter painter;
    painter.begin(&svgGen);
    painter.setRenderHint(QPainter::Antialiasing);

    // Choix des dimensions
    int gridSize = 450;
    int cellSize = gridSize / 9;
    int gridX = (svgGen.width() - gridSize) / 3;
    int gridY = (svgGen.height() - gridSize) / 3;

    // Draw the Sudoku grid
    painter.setPen(QPen(Qt::black, 2));
    painter.setFont(QFont("Arial", 20));
    for(int i=0; i<=9; i++) // dresser les lignes horizontale et verticale
    {
        if(i % 3 == 0)
        {
            painter.setPen(QPen(Qt::black, 3)); // dresser des lignes foncées pour séparer les boxes
        }
        painter.drawLine(QPoint(gridX, gridY + i*cellSize), QPoint(gridX + gridSize, gridY + i*cellSize));
        painter.drawLine(QPoint(gridX + i*cellSize, gridY), QPoint(gridX + i*cellSize, gridY + gridSize));
        painter.setPen(QPen(Qt::black, 2));
    }

    // afficher les nombres dans les cases
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(m_sudoku.grid[i][j]!=0)
            {
                int x = gridX + j*cellSize + cellSize/3;
                int y = gridY + i*cellSize + cellSize/3 + 10;

                // afficher le numéro dans la case
                painter.drawText(QPoint(x, y), QString::number(m_sudoku.grid[i][j]));
            }
        }
    }

    // Draw the difficulty level text
    painter.drawText(QPoint(50, 525), QString("le niveau de difficulté commencant de 0 : %1").arg(m_sudoku.difficultyLevel));

    painter.end();

    QMessageBox::information(this, tr("Succès"), tr("Sauvegarde avec succès. On peut le voir dans le fichier SVG."));
}

// Calculer la difficulté d'une grille donnée à l'utilisateur
int Sudoku::branchDifficultyScore()
{
    int emptyPositions = -1;
    int tempGrid[9][9];
    int sum=0;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            tempGrid[i][j] = m_sudoku.grid[i][j];
        }
    }

    while(emptyPositions!=0)
    {
        vector<vector<int> > empty;

        for(int i=0;i<81;i++)
        {
            if(tempGrid[(int)(i/9)][(int)(i%9)] == 0)
            {
                vector<int> temp;
                temp.push_back(i);

                for(int num=1;num<=9;num++)
                {
                    if(isSafe(tempGrid,i/9,i%9,num))
                    {
                        temp.push_back(num);
                    }
                }

                empty.push_back(temp);
            }

        }

        if(empty.size() == 0)
        {
            qDebug() <<"Hello: "<<sum;
            return sum;
        }

        int minIndex = 0;

        int check = empty.size();
        for(int i=0;i<check;i++)
        {
            if(empty[i].size() < empty[minIndex].size())
                minIndex = i;
        }

        int branchFactor=empty[minIndex].size();
        int rowIndex = empty[minIndex][0]/9;
        int colIndex = empty[minIndex][0]%9;

        tempGrid[rowIndex][colIndex] = m_sudoku.solnGrid[rowIndex][colIndex];
        sum = sum + ((branchFactor-2) * (branchFactor-2)) ;

        emptyPositions = empty.size() - 1;
    }

    return sum;

}


// on calcul la difficulté à l'aide du back-tracking avec branchDifficultyScore
void Sudoku::calculateDifficulty()
{
    int B = branchDifficultyScore();
    int emptyCells = 0;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(m_sudoku.grid[i][j] == 0)
                emptyCells++;
        }
    }

    m_sudoku.difficultyLevel = B*100 + emptyCells;
}

void Sudoku::on_pushButton_save_clicked()
{
    for(int i = 0; i<9; i++)
        for(int j = 0; j <9; j++) {
            m_sudoku.previousGrid[i][j] = m_sudoku.grid[i][j];
        }

    printSVG();
}


void Sudoku::on_pushButton_viewresult_clicked()
{
    // show the first solution on the interface
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            qDebug() << "m_sudoku.grid[" << i << "][" <<j <<"] " << m_sudoku.grid[i][j];
            if(m_sudoku.grid[i][j]!=0)
                m_vectCell[i * 9 + j]->SetViewMode(QString::number(m_sudoku.solnGrid[i][j]));
            else
                m_vectCell[i * 9 + j]->SetClueMode(QString::number(m_sudoku.solnGrid[i][j]));
        }
    }
}


void Sudoku::on_pushButton_load_clicked()
{
    for(int i = 0; i<9; i++)
        for(int j = 0; j <9; j++) {
            int value = m_sudoku.previousGrid[i][j];
            if(value == 0) {
                m_sudoku.grid[i][j] = 0;
                m_vectCell[i * 9 + j]->SetInputMode("");
            }
            else {
                m_sudoku.grid[i][j] = value;
                m_vectCell[i * 9 + j]->SetViewMode(QString::number(value));
            }
        }
}


void Sudoku::on_pushButton_new_clicked()
{
    this->Init();

    // creation d'un puzzle lorsqu'on clique sur new
    createSeed();

    QString level = m_comboBox->currentText();
    qDebug() << "Level = " << level;

    // génerer le puzzle selon le level
    genPuzzle(level);

    // on calcule le niveau de difficulté
    calculateDifficulty();

    printGrid();
}
