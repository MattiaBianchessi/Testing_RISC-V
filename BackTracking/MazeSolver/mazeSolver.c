#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

/* Coordinata */
typedef struct
{
    int x, y;
} Coordinate;

Coordinate new_coordinate(int x, int y)
{
    Coordinate ret = {x, y};
    return ret;
}

/* cerco inizio.
 se non trovo restituisce (x,y) = (-1,-1)
 */
Coordinate puntoInizio(char **m, int l, int c)
{
    Coordinate entrance = {-1, -1};
    
   for(int i = 0; i < l; i ++){
    for(int j = 0; j < c; j++){
        if(m[i][j] == 'I'){
            entrance = new_coordinate(i,j);
            return entrance;
        }
    }
   }
    return entrance; 
}

//Confronto coordinate
char equals_coordinates(Coordinate c1, Coordinate c2)
{
    if ((c1.x == c2.x) && (c1.y == c2.y))
        return 1;
    return 0;
}

//stampa il labirinto
void print_maze(char **maze, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}


/* The array must have 4 spaces */
void possibile(Coordinate curr, char **maze, Coordinate *dirPoss,
                   int lines, int columns)
{
    /* giu */
    if (curr.x >= lines - 1)
        dirPoss[0] = new_coordinate(-1, -1);
    else
    {
        if (maze[curr.x + 1][curr.y] == ' ' || maze[curr.x + 1][curr.y] == 'O')
            dirPoss[0] = new_coordinate(curr.x + 1, curr.y);
        else
        {
            dirPoss[0] = new_coordinate(-1, -1);
        }
    }

    /* su */
    if (curr.x <= 0)
        dirPoss[1] = new_coordinate(-1, -1);
    else
    {
        if (maze[curr.x - 1][curr.y] == ' ' || maze[curr.x - 1][curr.y] == 'O')
            dirPoss[1] = new_coordinate(curr.x - 1, curr.y);
        else
        {
            dirPoss[1] = new_coordinate(-1, -1);
        }
    }

    /* sinistra */
    if (curr.y <= 0)
        dirPoss[2] = new_coordinate(-1, -1);
    else
    {
        if (maze[curr.x][curr.y - 1] == ' ' || maze[curr.x][curr.y - 1] == 'O')
            dirPoss[2] = new_coordinate(curr.x, curr.y - 1);
        else
        {
            dirPoss[2] = new_coordinate(-1, -1);
        }
    }

    /* destra  */
    if (curr.y >= columns - 1)
        dirPoss[3] = new_coordinate(-1, -1);
    else
    {
        if (maze[curr.x][curr.y + 1] == ' ' || maze[curr.x][curr.y + 1] == 'O')
            dirPoss[3] = new_coordinate(curr.x, curr.y + 1);
        else
        {
            dirPoss[3] = new_coordinate(-1, -1);
        }
    }
}

char stop_program()
{
    char answer;
    printf("\nTerminare il programma? (Y/N)\n");
    scanf(" %c", &answer);
    return toupper(answer);
}

/* ================================================================= */
/*                              SOLVER                               */
/* ================================================================= */

/* se trovo una soluzione restituisco la coordinata (-2, -2), questa coordinata è utilizzata solo per
verificiare l esistenza di una soluzione. Se non viene trovata nessuna soluzione allora viene restituita
la coordinata iniziale. 
*/
Coordinate solve(Coordinate current, char **maze, int lines, int columns)
{
    Coordinate poss[4];
    Coordinate answer;

    if (current.x == -1)
        return current;
    if (maze[current.x][current.y] == 'O')
        return new_coordinate(-2, -2);
    maze[current.x][current.y] = 'x';

    /*print_maze(maze, lines, columns); printf("\n");*/

    possibile(current, maze, poss, lines, columns);
    for (int i = 0; i < 4; i++)
    {
        answer = solve(poss[i], maze, lines, columns);
        if (answer.x == -1) /* non da questa parte*/
            continue;
        if (answer.x == -2) /* trovato */
            return answer;
    }

    /* back */
    maze[current.x][current.y] = ' ';
    return current;
}



int main(void)
{
    char save;
    char pathToFile[256];
    char **maze;
    int nLines, nColumns, i, j;
    FILE *fil;
    clock_t start, end;

    

    do
    {
        printf("\nInserire il path del labirinto:\n");

        scanf("%255s", pathToFile);

        if ((fil = fopen(pathToFile, "r")) == NULL)
        {
            printf("\nQualcosa è andato storto :(.\n");
            continue;
        }

        /*DIMENSIONE */
        fscanf(fil, "%d", &nLines);
        fscanf(fil, "%d", &nColumns);

        /* LABIRINTO */
        //alloco
        maze = (char **)malloc(sizeof(char *) * nLines);
        for (i = 0; i < nLines; i++)
            maze[i] = (char *)malloc(sizeof(char) * nColumns);
        //scrivo
        fgetc(fil);
        for (i = 0; i < nLines; i++)
        {
            for (j = 0; j < nColumns; j++)
            {
                maze[i][j] = fgetc(fil);
            }
            fgetc(fil);
        }

        /* chiudo */
        fclose(fil);

        

        Coordinate entrance_to_maze = puntoInizio(maze, nLines, nColumns);

        start = clock();
        Coordinate exit_to_maze = solve(entrance_to_maze, maze, nLines, nColumns);
        end = clock();


        if (equals_coordinates(entrance_to_maze, exit_to_maze)){
            /* NESSUNA SOLUZIONE */
            printf("\nNon ho trovato soluzioni.\n");
            printf("\ttempo : %f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
        }
        else
        {
           /* SOLUZIONE */
           
           maze[entrance_to_maze.x][entrance_to_maze.y] = 'I';

           printf("\nUna soluzione trovata.\n");
           printf("\tin : %f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
           //print_maze(maze, nLines, nColumns);

           printf("\nSalvare il risultato? (Y/N)\n");
           scanf(" %c", &save);
           if (toupper(save) == 'Y')
           {
               /* Save */
               printf("\nInserire il path per salvare la soluzione:\n");

               scanf("%255s", pathToFile);

               if ((fil = fopen(pathToFile, "w")) == NULL)
               {
                   printf("\nQualcosa è andato storto :(.\n");
               }
               else
               {
                   fprintf(fil, "%d\n", nLines);
                   fprintf(fil, "%d\n", nColumns);
                   for (i = 0; i < nLines; i++)
                   {
                       for (j = 0; j < nColumns; j++)
                           fprintf(fil, "%c", maze[i][j]);
                       fprintf(fil, "\n");
                   }

                   fclose(fil);
               }
            }
        }

        /* libero */
        for (i = 0; i < nLines; i++)
            free(maze[i]);
        free(maze);

    } while (stop_program() != 'Y');

    return 0;
}