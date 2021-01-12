# ttt
Unbeatable tic-tac-toe using hash-table and a graph data structure.
A structure called BoardNode represents a node in the graph of all possible tic-tac-toe game. Each node represents one board, some properties for that board, and the moves that can be applied to that board and the subsequent boards, based on those nodes.
Program evaluates the nodes in order of decreasing depth, and assigns a score to each entry in the table htable that has an init value of 1. The best possible move position is the move leading to the child node with the highest score for x, and the lowest score for o. 
A file called alphatoe.c that contains the code to play games of tic-tac-toe.
A file called ttt.h that contains macro constants, a typedef, external (global) variable definitions, a structure, and function prototypes.
A file called ttt1.c that contains global variables, and two helper functions.
