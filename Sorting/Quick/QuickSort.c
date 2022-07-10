#include <stdio.h>
#include <stdbool.h>
#include "supArray.h"
#include <time.h>
#include <math.h>



bool sorted(int a[], int dim);
bool viewSorted(bool cond);

void QuickSort(int v[], int in, int fin);
int partiziona(int v[], int in, int fin);

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

    
    /*---------------------------------
    SEZIONE PER I CASI GENERALI.
    In una situazione normale gli array da oridanare possono non essere ordinati e qui vengono
    generati un numero pari a rndProve di array di numeri casuali da ordinare.
    ----------------------------------*/

    const int rndProve = 150;
    const int set = 7;
    // Array per la memorizzazione del tempo dei casi generali
    double tempiRND[set][rndProve];

    // Variabile per l 'array attuale da ordinare
    int *a;
    // Variabile per
    int dim;

    //----------------

   
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
            QuickSort(a,0 , dim);
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

//Visualizzione se è ordinato
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

//Controllo se l'array è stato ordinato
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


/*---------------
ALGORITMO QuickSort
-----------------*/

void QuickSort(int v[], int in, int fin)
{
    if (fin <= in)
        return;
    int pos = partiziona(v, in, fin);
    /*
     * Ricorsione...(Quindi algoritmo non in-place , in quanto deve
     * allocare memoria fino alla risoluzione del problema)
     */
    QuickSort(v, in, pos - 1);  // Sotto porzione sinistra
    QuickSort(v, pos + 1, fin); // Sotto porzione destra
}


int partiziona(int v[], int in, int fin)
{
    // L'elemento pivot è il primo (posizione 0)
    int i = in + 1, j = fin;
    while (i <= j)
    {
        while ((i <= fin) && (v[i] <= v[in]))
            i++;
        while (v[j] > v[in])
            j--;
        if (i <= j)
        {
            // Scambia
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    // Scambia
    int tt = v[in];
    v[in] = v[i - 1];
    v[i - 1] = tt;

    return i - 1;
}