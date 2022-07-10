#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Sudoku.h"
#include <stdlib.h>
#include <string.h>

#define SIZE 9


// stampa il sudoku
void print_sudoku(int matrix[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        if(i %3 == 0){
            printf("+------+------+------+\n");
        }
        for (j = 0; j < SIZE; j++)
        {
            if (j % 3 == 0)
            {
                printf("|");
            }
            printf("%2d", matrix[i][j]);
        }
        printf("|\n");
    }
    printf("+------+------+------+\n");
}

// controlla se tutte le celle sono assegnate
// se esiste almeno una non assegnata -> aggiunge un valore e continua a cercare la soluzione
int numero_non_assegnato(int matrix[SIZE][SIZE], int *row, int *col)
{
    int num_nA = 0;
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            // cella non assegnata
            if (matrix[i][j] == 0)
            {
                // cambio valori
                *row = i;
                *col = j;
                
                num_nA = 1;
                return num_nA;
            }
        }
    }
    return num_nA;
}


// posizionamento valido
int valido(int matrix[SIZE][SIZE], int n, int r, int c)
{
    int i, j;
    // checking in row
    for (i = 0; i < SIZE; i++)
    {
        // there is a cell with same value
        if (matrix[r][i] == n)
            return 0;
    }
    // checking column
    for (i = 0; i < SIZE; i++)
    {
        // there is a cell with the value equal to i
        if (matrix[i][c] == n)
            return 0;
    }
    // checking sub matrix
    int row_start = (r / 3) * 3;
    int col_start = (c / 3) * 3;
    for (i = row_start; i < row_start + 3; i++)
    {
        for (j = col_start; j < col_start + 3; j++)
        {
            if (matrix[i][j] == n)
                return 0;
        }
    }
    return 1;
}

//Risolvi (Backtracking)
int solve_sudoku(int matrix[SIZE][SIZE])
{
    int row;
    int col;
    
    if (numero_non_assegnato(matrix, &row, &col) == 0)
        return 1;
    int n, i;
    // 1 -> 9
    for (i = 1; i <= SIZE; i++)
    {
       
        if (valido(matrix, i, row, col))
        {
            matrix[row][col] = i;
            // backtracking
            if (solve_sudoku(matrix))
                return 1;
            
            matrix[row][col] = 0;
        }
    }
    return 0;
}



int main(int argc, char *argv[])
{
    clock_t start = clock();
    
    int m [SIZE][SIZE];
    
    if(argc == 2){
        switch (atoi(argv[1])){
        case 1:
            memcpy(m, sudoku1, sizeof(int) * SIZE * SIZE);
            break;
        case 2:
            memcpy(m, sudoku2, sizeof(int) * SIZE * SIZE);
            break;
        case 3:
            memcpy(m, sudoku3, sizeof(int) * SIZE * SIZE);
            break;

        case 4:
            memcpy(m, sudoku4, sizeof(int) * SIZE * SIZE);
            break;
        case 5:
            memcpy(m, sudoku5, sizeof(int) * SIZE * SIZE);
            break;
        case 6:
            memcpy(m, sudoku6, sizeof(int) * SIZE * SIZE);
            break;

// sbagliato da partenza
        case 7:
            memcpy(m, sudoku7, sizeof(int) * SIZE * SIZE);
            break;
// non risolvibile 
        case 8:
            memcpy(m, sudoku8, sizeof(int) * SIZE * SIZE);
            break;

        default:
            printf("Void Sudoku\n");
            memcpy(m, voidSudoku, sizeof(int) * SIZE * SIZE);
        }
    }else if(argc == 1){
        printf("Void Sudoku\n");
        memcpy(m, voidSudoku, sizeof(int) * SIZE * SIZE);
    }else{
        printf("ERROR");
        return 1;
    }



    if (solve_sudoku(m))
    {
        clock_t end = clock();
        print_sudoku(m);
        printf("\n\nSoluzione trovata in : %f", ((double)(end - start)) / CLOCKS_PER_SEC);
    }
    else
    { 
        clock_t end = clock();
       
        printf("\n\nNo soluzione in : %f", ((double)(end - start)) / CLOCKS_PER_SEC);
    }
    return 0;
    
}