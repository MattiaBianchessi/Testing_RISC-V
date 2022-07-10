#include <stdio.h>
#include <stdbool.h>
#include "supArray.h"
#include <time.h>
#include <math.h>

//#define formatBool(b) ((b) ? "true" : "false")

void insertionSort(int a[], int dim);
bool sorted(int a[], int dim);
bool viewSorted(bool cond);

//------------------------------------
int main()
{
    // array per le dimensioni degli array da ordinare
    const int dimensioni[] = {500, 1000, 5000, 10000, 20000, 35000, 50000};
    /*--------------------------------
    SEZIONE PER I CASI MIGLIORI E PEGGIORI.
    Nel caso dei casi peggiori l 'array da oridare è in oridne inverso, mentre
    nel caso migliore l 'array è già ardinato. Queste situazioni sono implementate nella libreria
    supArray.h
    --------------------------------*/

    // 7 numerosità, 3 per set
    const int set = 7;
    const int prove = 3;

    //--------------------------------
    // Array per la memorizzazione del tempo dei casi peggiori
    double tempiWORST[set][prove];
    // Array per la memorizzazione del tempo dei casi migliori
    double tempiBEST[set][prove];

    /*---------------------------------
    SEZIONE PER I CASI GENERALI.
    In una situazione normale gli array da oridanare possono non essere ordinati e qui vengono
    generati un numero pari a rndProve di array di numeri casuali da ordinare.
    ----------------------------------*/

    const int rndProve = 150;
    // Array per la memorizzazione del tempo dei casi generali
    double tempiRND[set][rndProve];

    // Variabile per l 'array attuale da ordinare
    int *a;
    // Variabile per
    int dim;

    //----------------

    // Tempi dei Case peggiori
    for (int i = 0; i < set; i++)
    {
        for (int j = 0; j < prove; j++)
        {

            if (i == 0)
            {
                a = genArray_WORST500();
            }
            else if (i == 1)
            {
                a = genArray_WORST1000();
            }
            else if (i == 2)
            {
                a = genArray_WORST5000();
            }
            else if (i == 3)
            {
                a = genArray_WORST10000();
            }
            else if (i == 4)
            {
                a = genArray_WORST20000();
            }
            else if (i == 5)
            {
                a = genArray_WORST35000();
            }
            else if (i == 6)
            {
                a = genArray_WORST50000();
            }

            dim = dimensioni[i];

            // printf("SORTED: %s -> ", formatBool(sorted(a, dim)));
            viewSorted(sorted(a, dim));

            // ordino e cronometro
            clock_t start = clock();
            insertionSort(a, dim);
            clock_t end = clock();

            // printf("SORTED: %s\n", formatBool(sorted(a, dim)));
            viewSorted(sorted(a, dim));
            tempiWORST[i][j] = (((double)(end - start)) / CLOCKS_PER_SEC);
            printf("-");
        }
    }

    printf("Completato: %d worst case\n", set * prove);

    // Tempi dei Case migliori
    for (int i = 0; i < set; i++)
    {
        for (int j = 0; j < prove; j++)
        {

            if (i == 0)
            {
                a = genArray_BEST500();
            }
            else if (i == 1)
            {
                a = genArray_BEST1000();
            }
            else if (i == 2)
            {
                a = genArray_BEST5000();
            }
            else if (i == 3)
            {
                a = genArray_BEST10000();
            }
            else if (i == 4)
            {
                a = genArray_BEST20000();
            }
            else if (i == 5)
            {
                a = genArray_BEST35000();
            }
            else if (i == 6)
            {
                a = genArray_BEST50000();
            }

            dim = dimensioni[i];

            // printf("SORTED: %s -> ", formatBool(sorted(a, dim)));
            viewSorted(sorted(a, dim));

            // ordino e cronometro
            clock_t start = clock();
            insertionSort(a, dim);
            clock_t end = clock();

            // printf("SORTED: %s\n", formatBool(sorted(a, dim)));
            viewSorted(sorted(a, dim));
            tempiBEST[i][j] = (((double)(end - start)) / CLOCKS_PER_SEC);
            printf("-");
        }
    }

    printf("Completato: %d best case\n", set * prove);

    // Tempi dei Case rnd
    for (int i = 0; i < set; i++)
    {
        for (int j = 0; j < rndProve; j++)
        {

            if (i == 0)
            {
                a = genArray_500();
            }
            else if (i == 1)
            {
                a = genArray_1000();
            }
            else if (i == 2)
            {
                a = genArray_5000();
            }
            else if (i == 3)
            {
                a = genArray_10000();
            }
            else if (i == 4)
            {
                a = genArray_20000();
            }
            else if (i == 5)
            {
                a = genArray_35000();
            }
            else if (i == 6)
            {
                a = genArray_50000();
            }

            dim = dimensioni[i];

            // printf("SORTED: %s -> ", formatBool(sorted(a, dim)));
            viewSorted(sorted(a, dim));

            // ordino e cronometro
            clock_t start = clock();
            insertionSort(a, dim);
            clock_t end = clock();

            // printf("SORTED: %s\n", formatBool(sorted(a, dim)));
            viewSorted(sorted(a, dim));
            tempiRND[i][j] = (((double)(end - start)) / CLOCKS_PER_SEC);
            printf("-");
        }
    }
    printf("Completato: %d rnd case\n", set * rndProve);

    double min[set] = {
        tempiRND[0][0],
        tempiRND[1][0],
        tempiRND[2][0],
        tempiRND[3][0],
        tempiRND[4][0],
        tempiRND[5][0],
        tempiRND[6][0],
    };
    double max[set] = {
        tempiRND[0][0],
        tempiRND[1][0],
        tempiRND[2][0],
        tempiRND[3][0],
        tempiRND[4][0],
        tempiRND[5][0],
        tempiRND[6][0],
    };

    double mean[set] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < set; i++)
    {
        double tot = 0;
        for (int j = 0; j < rndProve; j++)
        {
            // MAX
            if (max[i] < tempiRND[i][j])
            {
                max[i] = tempiRND[i][j];
            }

            // MIN
            if (min[i] > tempiRND[i][j])
            {
                min[i] = tempiRND[i][j];
            }

            // MEAN
            tot += tempiRND[i][j];
        }
        mean[i] = tot / rndProve;
    }

    /*-----------------
    VISUALIZZAZIONE DEI RISULTATI
    ------------------*/

    // SHOW RESULT -> Worst
    printf("TAB. Worst case \n");
    for (int i = 0; i < set; i++)
    {
        for (int j = 0; j < prove; j++)
        {
            printf("%f\t", tempiWORST[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // SHOW RESULT -> Best
    printf("TAB. Best case\n");
    for (int i = 0; i < set; i++)
    {
        for (int j = 0; j < prove; j++)
        {
            printf("%f\t", tempiBEST[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // SHOW RESULT  -> min , max, avg
    printf("TAB. RND case\n");
    printf("MIN\t\tMAX\t\tMEAN\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%f\t%f\t%f\n", min[i], max[i], mean[i]);
    }

    printf("\n\n");
    return 0;
}

// Visualizzazione se è stato ordinato
bool viewSorted(bool cond)
{
    if (cond)
    {
        printf("\x1b[32m%c\33[0m", 115);
        return true;
    }
    else
    {
        printf("\x1b[31m%c\33[0m", 115);
        return false;
    }
}

// Controllo se l'array è ordinato
bool sorted(int a[], int dim)
{
    for (int i = 0; i < dim - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;
}

//Algoritmo di ordinamento
void insertionSort(int a[], int dim)
{

    int temp, j;
    for (int i = 1; i < dim; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}