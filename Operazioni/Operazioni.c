#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


typedef struct 
{
    double somma;
    double sottrazione;
    double prodotto;
    double divisione;
    double modulo;
} Operazioni;

/*------------
GENERA MATRICI
-------------*/
//Genera una matrice casuale di dimensione dim x dim. Ogni elemento generato varia tra 1 e range
int **genMatriceRnd(int dim,int range)
{
    int **a;
    a = (int **)malloc(dim * sizeof(int *));
    for (int i = 0; i < dim; i++)
    {
        a[i] = malloc(dim * sizeof(int));
    }

   for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            int num = (rand() % range) + 1;
            a[i][j] = num;
            
        }
    }
    return a;
}

// Genera una matrice casuale di dimensione dim x dim. Ogni elemento generato è zero
int **genMatrice(int dim)
{
    int **a;
    a = (int **)malloc(dim * sizeof(int *));
    for (int i = 0; i < dim; i++)
    {
        a[i] = malloc(dim * sizeof(int));
    }
    return a;
}

/*---------
OPERAZIONI:
    Esegue l'operazione tra le matrici A e B.
    Ogni matrice ha dimensione dim x dim.
----------*/

//SOMMA
void sumMatrice(int dim, int **a, int **b){
    for(int i = 0; i < dim; i ++){
        for(int j = 0 ;j < dim ; j++){
            //c[i][j] = a[i][j] + b[i][j];
            a[i][j] + b[i][j];
        }
    }
}

//SOTTRAZIONE
void subMatrice(int dim, int **a, int **b)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            //c[i][j] = a[i][j] - b[i][j];
            a[i][j] - b[i][j];
        }
    }
}

//PRODOTTO
void multMatrice(int dim, int **a, int **b)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            //c[i][j] = a[i][j] * b[i][j];
            a[i][j] * b[i][j];
        }
    }
}

//DIVISIONE
void divMatrice(int dim, int **a, int **b)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            //c[i][j] = a[i][j] / b[i][j];
            a[i][j] / b[i][j];
        }
    }
}

//MODULO
void modMatrice(int dim, int **a, int **b)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
           // c[i][j] = a[i][j] % b[i][j];
           a[i][j] % b[i][j];
        }
    }
}

int main(){
    // Dimensioni possibili
    const int dimensioni[] = {1000, 2500, 5000, 8000, 10000, 15000};
    const int DIMLEN = 6;           // dimensione ^
    const int range[] = {200, 100}; //range delle matrici A e B
    
    //Numero di prove per dimensione
    const int PROVE = 5;
    
    //
    srand(time(NULL));

    //Timer
    clock_t start, end;
    //2D array per i dati
    Operazioni operazioni[DIMLEN][PROVE];
    
    //counter
    int completi = 0;

    int dim;
    int** a;
    int** b;
    

    // Tempi di esecuzione
    for (int i = 0; i < DIMLEN; i++)
    {
        for (int j = 0; j < PROVE; j++)
        {
            dim = dimensioni[i];
            // Matrice A
            a = genMatriceRnd(dim, range[0]);

            // Matrice B
            b = genMatriceRnd(dim, range[1]);

            // Matrice C
            //int **c = genMatrice(dim);

            // SOMMA
            start = clock();
            sumMatrice(dim, a, b);
            end = clock();
            operazioni[i][j].somma = ((double)(end - start)) / CLOCKS_PER_SEC;

            // DIFFERENZA
            start = clock();
            subMatrice(dim, a, b);
            end = clock();
            operazioni[i][j].sottrazione = ((double)(end - start)) / CLOCKS_PER_SEC;

            // PRODOTTO
            start = clock();
            multMatrice(dim, a, b);
            end = clock();
            operazioni[i][j].prodotto = ((double)(end - start)) / CLOCKS_PER_SEC;

            // DIVISIONE
            start = clock();
            divMatrice(dim, a, b);
            end = clock();
            operazioni[i][j].divisione = ((double)(end - start)) / CLOCKS_PER_SEC;

            // MODULO
            start = clock();
            modMatrice(dim, a, b);
            end = clock();
            operazioni[i][j].modulo = ((double)(end - start)) / CLOCKS_PER_SEC;

            // COMUNICAZIONE
            printf("%d/%d Completati\n", ++completi , DIMLEN * PROVE);

            free(a);
            free(b);
            }
            
        }
    

    /*-------------
    CALCOLA I VALORI MEDI
    --------------*/
    Operazioni opMean[DIMLEN];
    for(int i =0 ; i < DIMLEN; i++){
        double totSum = 0;
        double totSub = 0;
        double totProd = 0;
        double totDiv = 0;
        double totMod = 0;

        for(int j = 0;  j < PROVE; j++){
            totSum += operazioni[i][j].somma;
            totSub += operazioni[i][j].sottrazione;
            totProd += operazioni[i][j].prodotto;
            totDiv += operazioni[i][j].divisione;
            totMod += operazioni[i][j].modulo;
        }
        opMean[i].somma = totSum / PROVE;
        opMean[i].sottrazione = totSub / PROVE;
        opMean[i].prodotto = totProd / PROVE;
        opMean[i].divisione = totDiv / PROVE;
        opMean[i].modulo = totMod / PROVE;
    }

    /*-------------
    VISUALIZZO RISULTATI
    --------------*/
    /*
        TABELLA FORMATTATA
    */
    printf("Dimensione:\t");
    for (int i = 0; i < DIMLEN; i++)
    {
        printf("%d\t\t",dimensioni[i]);
    }

    printf("\nSomma:\t");
    for (int i = 0; i < DIMLEN; i++)
    {
        printf("\t%f", opMean[i].somma);
    }

    printf("\nSottrazione:");
    for (int i = 0; i < DIMLEN; i++)
    {
        printf("\t%f", opMean[i].sottrazione);
    }

    printf("\nProdotto:");
    for (int i = 0; i < DIMLEN; i++)
    {
        printf("\t%f", opMean[i].prodotto);
    }

    printf("\nDivisione:");
    for (int i = 0; i < DIMLEN; i++)
    {
        printf("\t%f", opMean[i].divisione);
    }

    printf("\nModulo:\t");
    for (int i = 0; i < DIMLEN; i++)
    {
        printf("\t%f", opMean[i].modulo);
    }

    printf("\n");
}

