// Heap Sort in C
#include <stdio.h>
#include <stdbool.h>
#include "supArray.h"
#include <time.h>
#include <math.h>

//
bool viewSorted(bool cond);
bool sorted(int a[], int dim);
void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);


//
int main()
{
    // array per le dimensioni degli array da ordinare
    const int dimensioni[] = {500, 1000, 5000, 10000, 20000, 35000, 50000};
    // 7 numerosità, 3 per set
    const int set = 7;
    const int rndProve = 150;

    // Array per la memorizzazione del tempo dei casi generali
    double tempiRND[set][rndProve];

    // Variabile per l 'array attuale da ordinare
    int dim;
    // Variabile per
    int *a;

    //----------------

    //Tempi
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
            heapSort(a, dim);
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

    printf("TAB. RND case\n");
    printf("MIN\t\tMAX\t\tMEAN\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%f\t%f\t%f\n", min[i], max[i], mean[i]);
    }

    printf("\n\n");
    return 0;
}

//Visualizzazione se l'array è ordinato
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

//Controllo se l'array è ordinato
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
Algoritmo HeapSort
----------------*/

void swap(int *a, int *b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int n, int i)
{

    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < n && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i)
    {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)

        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}



