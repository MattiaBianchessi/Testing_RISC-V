# Backtracking

In questa direcotry sono contenuti due programmi: 
- Un solutore di sudoku
- Un solutore di labirinti

In entrambi i casi vengono utilizzate tecniche di backtracking.
Lo scopo è quello di valutare il tempo di esecuizione di programmi che fanno uso del backtracking su processore RISC.


## Sudoku
Nel file sudoku.h sono presenti 8 sudoku di varia difficoltà, 2 di essi non sono fattibili, uno per costruzione(sbagliato in partenza) e l 'altro è impossibile risolverlo per la configurazione.

## MazeSolver
Questa directory è presente il file mazeGen.py che è stato utilizzato come generatore di labirinti.
Il solutore mazeSolver.c, una volta in esecuzione, chiede il path del labirinto da risolvere e successivamente è possibile salvare la soluzione, se trovta, in un nuovo file. 
### Requisiti labirinto
Il file con estensione .txt, se si vuole utilizzare un altro labirinto, dovrà avere:
- sulla prima linea il numero di linee del labirinto.
- sulla seconda linea il numero di colonne.
- dalla terza in poi il labirinto che dovrà avere un simbolo , come ad esempio '#', per indicare i muri, lo spazio ' ' per indicare i corridoi, uno e un solo simbolo 'I' per indicare l' inizio e uno e un solo simbolo 'O' per indicare l' uscita del labirinto.

Sono presenti alcuni esempi nella sottodirectory maze di labirinti.
