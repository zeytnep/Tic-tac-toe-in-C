Zeynep Erdogru 
zeyneperdogru99@gmail.com

How to compile and run:
1. Type 'make' into terminal
2. To play the game, type './alphatoe'


Unbeatable tic-tac-toe using hash-table and a graph data structure.

1)A file called ttt.h that contains some macro constants, a typedef, some external
(global) variable definitions, a structure, and some function prototypes.
2)A file called ttt1.c that contains some global variables, and two helper functions.
3)A file called alphatoe.c that contains the code to play games of tic-tac-toe.

A structure called BoardNode represents a node in the graph of all possible tic-tac-toe game. Each node represents one board, some properties for that board, and the moves that can be applied to that board and the subsequent boards, based on those nodes.
Program evaluates the nodes in order of decreasing depth, and assigns a score to each entry in the table htable that has an init value of 1. The best possible move position is the move leading to the child node with the highest score for x, and the lowest score for o. 

