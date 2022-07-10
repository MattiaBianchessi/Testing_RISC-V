#define COL 9
#define ROW 9

//Sudoku vuoto
int voidSudoku[COL][ROW] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

//Vari
int sudoku1[COL][ROW] =
    {{0, 0, 0, 0, 0, 0, 0, 9, 0},
     {1, 9, 0, 4, 7, 0, 6, 0, 8},
     {0, 5, 2, 8, 1, 9, 4, 0, 7},
     {2, 0, 0, 0, 4, 8, 0, 0, 0},
     {0, 0, 9, 0, 0, 0, 5, 0, 0},
     {0, 0, 0, 7, 5, 0, 0, 0, 9},
     {9, 0, 7, 3, 6, 4, 1, 8, 0},
     {5, 0, 6, 0, 8, 1, 0, 7, 4},
     {0, 8, 0, 0, 0, 0, 0, 0, 0}};

int sudoku2[COL][ROW] =
    {{0, 8, 5, 0, 0, 7, 1, 0, 2},
     {0, 0, 4, 0, 1, 6, 5, 0, 0},
     {0, 0, 0, 0, 5, 3, 7, 6, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 5, 0, 0, 8, 7, 1},
     {4, 0, 0, 0, 0, 9, 2, 0, 6},
     {0, 0, 8, 0, 9, 0, 0, 0, 0},
     {0, 0, 0, 7, 0, 0, 0, 0, 5},
     {1, 9, 0, 0, 0, 0, 0, 8, 0}};

int sudoku3[COL][ROW] =
    {{6, 5, 0, 8, 7, 3, 0, 9, 0},
     {0, 0, 3, 2, 5, 0, 0, 0, 8},
     {9, 8, 0, 1, 0, 4, 3, 5, 7},
     {1, 0, 5, 0, 0, 0, 0, 0, 0},
     {4, 0, 0, 0, 0, 0, 0, 0, 2},
     {0, 0, 0, 0, 0, 0, 5, 0, 3},
     {5, 7, 8, 3, 0, 1, 0, 2, 6},
     {2, 0, 0, 0, 4, 8, 9, 0, 0},
     {0, 9, 0, 6, 2, 5, 0, 8, 1}};

int sudoku4[COL][ROW] =
    {{2, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 1, 0, 0, 0, 0, 7},
     {8, 0, 5, 0, 0, 4, 1, 0, 0},
     {5, 0, 6, 0, 8, 0, 0, 0, 9},
     {0, 7, 0, 0, 0, 6, 0, 0, 0},
     {0, 2, 0, 0, 0, 0, 5, 0, 0},
     {0, 0, 0, 0, 9, 0, 0, 3, 0},
     {0, 6, 0, 0, 0, 0, 0, 0, 0},
     {1, 0, 4, 0, 0, 8, 7, 0, 0}};

int sudoku5[COL][ROW] =
    {
        {4, 0, 0, 0, 0, 0, 9, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 1, 0, 0, 6, 5, 0, 4, 0},
        {0, 0, 0, 3, 0, 0, 0, 5, 0},
        {0, 0, 6, 0, 5, 2, 7, 0, 0},
        {0, 2, 0, 9, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 6, 0, 0, 4, 1, 0, 9, 0},
        {0, 0, 7, 0, 0, 0, 0, 0, 8}};

int sudoku6[COL][ROW] =
    {
        {0, 7, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 3},
        {0, 0, 8, 7, 0, 3, 5, 0, 0},
        {0, 8, 0, 4, 0, 1, 0, 0, 2},
        {0, 0, 5, 0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 4, 0, 3, 0, 8, 0, 0, 1}};

//Sbagliato da costruzione
int sudoku7[COL][ROW] =
    {
        {0, 7, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 3},
        {0, 0, 8, 7, 0, 3, 5, 0, 0},
        {0, 8, 0, 4, 0, 1, 0, 0, 2},
        {0, 0, 5, 0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 0, 3, 0, 8, 0, 0, 2}};

//inserimento impossibile
int sudoku8[COL][ROW] =
    {
        {4, 0, 0, 0, 0, 0, 9, 0, 1},
        {0, 0, 0, 0, 3, 0, 0, 0, 2},
        {0, 1, 0, 0, 6, 5, 0, 4, 3},
        {0, 0, 0, 3, 0, 0, 0, 0, 4},
        {0, 0, 6, 0, 5, 2, 7, 0, 8},
        {0, 2, 0, 9, 0, 0, 0, 0, 5},
        {0, 0, 0, 2, 0, 0, 0, 0, 6},
        {0, 6, 0, 0, 4, 1, 0, 0, 7},
        {0, 0, 7, 0, 0, 0, 0, 0, 9}};