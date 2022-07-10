#include <time.h>
#include <stdlib.h>
#include "supArray.h"

#pragma region WORST_ARRAY

int *genArray_WORST500()
{
    const int dim = 500;
    static int r[500];
    for (int i = 0; i < dim; i++)
    {
        r[i] = dim - i;
    }
    return r;
}
int *genArray_WORST1000()
{
    const int dim = 1000;
    static int r[1000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = dim - i;
    }
    return r;
}
int *genArray_WORST5000()
{
    const int dim = 5000;
    static int r[5000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = dim - i;
    }
    return r;
}
int *genArray_WORST10000()
{
    const int dim = 10000;
    static int r[10000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = dim - i;
    }
    return r;
}
int *genArray_WORST20000()
{
    const int dim = 20000;
    static int r[20000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = dim - i;
    }
    return r;
}
int *genArray_WORST35000()
{
    const int dim = 35000;
    static int r[35000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = dim - i;
    }
    return r;
}
int *genArray_WORST50000()
{
    const int dim = 50000;
    static int r[50000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = dim - i;
    }
    return r;
}


#pragma endregion

#pragma region BEST_ARRAY

int *genArray_BEST500()
{
    const int dim = 500;
    static int r[500];
    for (int i = 0; i < dim; i++)
    {
        r[i] = i + 1;
    }
    return r;
}
int *genArray_BEST1000()
{
    const int dim = 1000;
    static int r[1000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = i + 1;
    }
    return r;
}
int *genArray_BEST5000()
{
    const int dim = 5000;
    static int r[5000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = i + 1;
    }
    return r;
}
int *genArray_BEST10000()
{
    const int dim = 10000;
    static int r[10000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = i + 1;
    }
    return r;
}
int *genArray_BEST20000()
{
    const int dim = 20000;
    static int r[20000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = i + 1;
    }
    return r;
}
int *genArray_BEST35000()
{
    const int dim = 35000;
    static int r[35000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = i + 1;
    }
    return r;
}
int *genArray_BEST50000()
{
    const int dim = 50000;
    static int r[50000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = i + 1;
    }
    return r;
}

#pragma endregion

#pragma region region gen_RND_Array
int *genArray_500()
{
    srand(time(NULL));
    const int dim = 500;
    static int r[500];
    for (int i = 0; i < dim; i++)
    {
        r[i] = rand();
    }
    return r;
}
int *genArray_1000()
{
    srand(time(NULL));
    const int dim = 1000;
    static int r[1000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = rand();
    }
    return r;
}
int *genArray_5000()
{
    srand(time(NULL));
    const int dim = 5000;
    static int r[5000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = rand();
    }
    return r;
}
int *genArray_10000()
{
    srand(time(NULL));
    const int dim = 10000;
    static int r[10000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = rand();
    }
    return r;
}
int *genArray_20000()
{
    srand(time(NULL));
    const int dim = 20000;
    static int r[20000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = rand();
    }
    return r;
}
int *genArray_35000()
{
    srand(time(NULL));
    const int dim = 35000;
    static int r[35000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = rand();
    }
    return r;
}
int *genArray_50000()
{
    srand(time(NULL));
    const int dim = 50000;
    static int r[50000];
    for (int i = 0; i < dim; i++)
    {
        r[i] = rand();
    }
    return r;
}

#pragma endregion