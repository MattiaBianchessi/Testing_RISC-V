#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------
CALCOLA PRIMI 
-----------*/

//Numeri di primi da calcolare
#define DIM 5000

//Stampa array
void printArray(int *a){
    int i =0;
    printf("[");
    while (a[i] != '\0')
    {
        printf("%d", a[i]);
        i++;

        if(a[i] == '\0'){
            printf("]\n");
        }else{
            printf(", ");
        }

    }
    
}

//Controlla se c e un dicisione di n in a
// 0 -> se non ci sono
// 1 -> se ne trovo uno
int divisibile(int *a, int n){
    int i = 0;
    while (a[i] != '\0')
    {
        if( n % a[i] == 0)
            return 1;
        i++;
    }
    return 0;
}


//riempie l'array con i numeri primi. La dimensione della array è DIM
void fillPrime(int *a){
    int num = 2;
    int pos = 0;
    while(pos < DIM){

        if( divisibile(a, num) == 0){
            a[pos] = num;
            pos++;
        }

        num ++;
    }
}


int main(){
    int *a = malloc(DIM * sizeof(int));
    clock_t start, end;

    start = clock();
    fillPrime(a);
    end = clock();

    printf("Tempo: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //printArray(a);

    return 0 ;
}