#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

/*----------------
Moltiplicazione normale o bit shift
-----------------*/

//Dimensione set di prove
#define N 1000

//Numero di prove
//#define S 100

/*---------------
CREAZIONE ARRAY 
----------------*/
//genera un array di dimensione N. I numeri dell array sono compresi tra 0 e maxInt
int* generaNumeri(){
    int *a = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        a[i] = rand() ;
    }
    return a;
}

//genera un array di multipli di 2 di dimensione N. Il valore minimo è 2 e il massimo 1024
int* generaMult(){
    int e;
    int *a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        e = (rand() % 10) + 1;
        a[i] = pow(2, e);
    }
    return a;
}

//genera un array di dimensione N. Ogni elemento è il logaritmo in base 2 dall elemento in posizione corrispondente di a
int* esponenti(int *a){
    int *e = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        e[i] = (int)log2(a[i]);
    }
    return e;
}

/*------------
OPERAZIONI
-------------*/


//Esegue la moltiplicazione posizione per posizione tra a e b e memorizza il risultato in un array
int* eseguiMult(int *a, int *b){
    int *res = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        res[i] = a[i] * b[i];
    }
    return res;
}

// Esegue la divisione posizione per posizione tra a e b e memorizza il risultato in un array
int* eseguiDiv(int *a, int *b)
{
    int *res = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        res[i] = a[i] / b[i];
    }
    return res;
}

// Esegue la moltiplicazione tramite shift posizione per posizione tra a e b e memorizza il risultato in un array
int* eseguiMultShift(int *a, int *b)
{
    int *res = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        res[i] = a[i] << b[i];
    }
    return res;
}

// Esegue la divisione tramite shift posizione per posizione tra a e b e memorizza il risultato in un array
int* eseguiDivShift(int *a, int *b)
{
    int *res = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        res[i] = a[i] >> b[i];
    }
    return res;
}


//Controlla se gli elementi, posizione per posizione, sono uguali.
// 0 -> se gli elementi sono uguali, -1 altrimenti
int controllo(int *a, int *b){
    for(int i = 0; i < N; i++){
        if(a[i] != b[i]) {
            printf("%d %d\n",a[i], b[i]);
        return -1;
        }
    }   
    return 0;
}


int main(){
    //Operandi
    int *numeri;
    int *valori;
    int *exp;

    //Risultati
    int *resmult, *resmultShift;
    int *resdiv, *resdivShift;

    srand(time(NULL));
    clock_t start ,end;

    double tempiMult[N][2];
    double tempiDiv[N][2];

   
        for(int j = 0; j < N ; j++){
            //Genera i numeri
            numeri = generaNumeri();
            valori = generaMult();
            exp = esponenti(valori);

            //Moltiplicazione
            start = clock();
            resmult = eseguiMult(numeri, valori);
            end = clock();

            tempiMult[j][0] = ((double)(end - start)) / CLOCKS_PER_SEC;

            //Divisione
            start = clock();
            resdiv = eseguiDiv(numeri, valori);
            end = clock();

            tempiDiv[j][0] = ((double)(end - start)) / CLOCKS_PER_SEC;


            //shift moltiplicazione
            start = clock();
            resmultShift = eseguiMultShift(numeri, exp);
            end = clock();

            tempiMult[j][1] = ((double)(end - start)) / CLOCKS_PER_SEC;

            //shift divisione
            start = clock();
            resdivShift = eseguiDivShift(numeri, exp);
            end = clock();

            tempiDiv[j][1] = ((double)(end - start)) / CLOCKS_PER_SEC;

            if (controllo(resmult, resmultShift) == -1){
                printf("ERRORE");
                return -1;
            }

            if (controllo(resdiv, resdivShift) == -1)
            {
                printf("ERRORE");
                return -1;
            }

            free(resmult);
            free(resmultShift);
            free(resdiv);
            free(resdivShift);
            free(numeri);
            free(valori);
        
    }

    
    //tempi [moltiplicazione / divisione] [normale / shift]
    double tempi[2][2];

    
        for (int j = 0; j < N; j++)
        {
            tempi[0][0]+= tempiMult[j][0]; 
            tempi[1][0]+= tempiDiv[j][0];
            tempi[0][1]+= tempiMult[j][1];
            tempi[1][1]+= tempiDiv[j][1];
        
    }
    printf(" %f \n", tempi[0][0]);
    printf("\t  Mult\t | Div\nNormale:%.4fms | %.4fms\nShift:\t%.4fms | %.4fms\n",
           (tempi[0][0]/ N) * 1000,
           (tempi[1][0]/ N) * 1000,
           (tempi[0][1]/ N) * 1000,
           (tempi[1][1]/ N) * 1000);
    printf("Operazioni: %d\n", N);

    
}