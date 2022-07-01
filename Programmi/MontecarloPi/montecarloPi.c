#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SEED time(NULL)


double valuePi(int times);

int main(){

    srand(SEED);
    //quante prove per potenza
    int provePerSet = 5;
    //Potenza massima da provare
    int potenzaMax = 10;
    //potenza iniziale 10 ^ 1
    int potenza = 10;

    double midTimer, totTimer = 0, pi;

    double valori[potenzaMax][provePerSet];
    double tempi[potenzaMax][provePerSet];

    for (int t = 0; t < potenzaMax; t++)
    {
        int cp = 0;
        printf("10^%d: ", t + 1 );
       

        while(cp < provePerSet){

            clock_t start = clock();
            pi = valuePi(potenza);
            clock_t end = clock();
            printf("%f ",pi );

            valori[t][cp] = pi;

            midTimer = ((double)(end - start)) / CLOCKS_PER_SEC;
            tempi[t][cp] = pi;

            totTimer += midTimer;
            printf("\x1b[31m (%f s )\x1b[37m|", midTimer);

            cp++;
        }

       printf("| TETot :  %f| TM: %f|\n", totTimer, totTimer / provePerSet);
        totTimer = 0;
        potenza *= 10;
    }
    printf("\n");
    

    //Print valori 
    /*
    for (int i = 0; i < potenzaMax; i++){
        for (int j = 0; j < provePerSet; j++)
        {
            printf(" %f", valori[i][j]);
        }
        printf("\n");
    }
    */


    return 0;
}

/*
* algoritmo di montecarlo per calcolo del pi greco
*/
double valuePi(int times){

    int i, count;
    double x, y, eq, pi;

    for (i = 0; i < times; ++i)
    {

        x = ((double)rand() / RAND_MAX);

        y = ((double)rand() / RAND_MAX);

        eq = x * x + y * y;

        if (eq <= 1)
        {
            count++;
        }
    }

    pi = (long double)4 * (long double)count / (long double)times;
    return pi;
}

