/*
Zeynep Erdogru
EMAIL: zeyneperdogru99@gmail.com 
*/

#include "ttt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* The function goes through the entire table and set the init variable in each structure to 0.
 * This indicates that elements of the hashtable is empty.
 */
void init_boards() {
    for (int i = 0; i< HSIZE; i++) htable[i].init = 0;
}

/* The function returns the number of markers (Xs and Os) on the board. */
int depth( Board board ) {
    int d =0;
    for (int i=0; i<9; i++) {
        if ((board[pos2idx[i]] == 'O') || (board[pos2idx[i]] == 'X')) d++;
    }
    return d;
}


/* Determine whether the game is over. 
 * If X has won the game return 'X'
 * If O has won the game return 'O'
 * If the board is filled and no-one has won return '-'
 * If the game is incomplete and no-one has won '?'
 */
char winner( Board board ) {
    for (int i=0; i<8; i++) {
        int counterX =0;
        int counterY =0;
        for (int j=0; j<3; j++) {
            if(board[pos2idx[WINS[i][j]]] == 'O') counterY++;
            if (board[pos2idx[WINS[i][j]]] == 'X') counterX++;
            if(counterX == 3) return 'X';
            if(counterY == 3) return 'O';
        }
    }
    if (depth(board) == 9) return '-'; /* If the board is filled and no one has won */

    return '?'; /* If the game is incomplete and no one has won */
}

/* Determine whose turn it is. */
char turn( Board board ) {
    if (winner(board) == 'X') return '-';
    if (winner(board) == 'O') return '-';
    if (depth(board) == 9) return '-';
    if (depth(board) % 2 == 0) return 'X';
    
    return 'O';
}

/* Computes the hash index of the board using board_hash.
 * Sets the variables of the structure at that index by calling
 * turn, depth, and, winner functions.
*/
void init_board( Board board ) {
    int hashVal = board_hash(board); 
    htable[hashVal].init = 1;
    htable[hashVal].turn = turn(board);
    htable[hashVal].depth = depth(board);
    strcpy((htable[hashVal]).board, board);
    htable[hashVal].winner = winner(board);
}


/* Create and join all the nodes of all possible tic-tac-toe games. */
void join_graph( Board board ) {

    if ((winner(board) == '?')) { /* Check if the game is over */
        for(int i=0; i<9; i++) {
            if ((board[pos2idx[i]] == 'X') || (board[pos2idx[i]] == 'O')) {
                htable[board_hash(board)].move[i] = -1;
            } else {
                Board newBoard;
                strcpy(newBoard, board);
                char xo = turn(newBoard);
                newBoard[pos2idx[i]] = xo;
                /* now i have a before and after position of the board */
                int hashVal = board_hash(newBoard); /* apply hash value to after board */
                htable[board_hash(board)].move[i] = hashVal;

                if (htable[hashVal].init == 0) { /* if there is no entry */
                    init_board(newBoard);
                    join_graph(newBoard);
                }
            }
        }
    }
    /* Check if there is a winner */
    if ((winner(board) != '?')) { 
        for(int win=0; win<9; win++) htable[board_hash(board)].move[win] = -1;
    }  
}



/*
* Assign a score to each entry in the hash table that has an init value of 1.
* Evaluate the nodes in order of decreasing depth.
*/
void compute_score() {

  for(int j = 9; j >= 0; j--) {
    for(int i = 0; i < HSIZE; i++) {

      if(htable[i].depth == j) {
        if(htable[i].init == 1) {
          if(htable[i].winner == 'X') {
            htable[i].score = 1;
          } else if(htable[i].winner == 'O') {
                htable[i].score = -1;
          } else if(htable[i].winner == '-') {
                htable[i].score = 0;
          } else {
                if(htable[i].turn == 'X') {
                    htable[i].score = -1;
                    for(int k = 0; k < 9; k++) {
                        if(htable[htable[i].move[k]].init == 1) {
                            if(htable[htable[i].move[k]].score > htable[i].score) {
                                htable[i].score = htable[htable[i].move[k]].score;
                            }
                        }
                    }
                } else if(htable[i].turn == 'O') {
                    htable[i].score = 1;
                    for(int k = 0; k < 9; k++) {
                        if(htable[htable[i].move[k]].init == 1) {
                            if(htable[htable[i].move[k]].score < htable[i].score) {
                                htable[i].score = htable[htable[i].move[k]].score;
                            }
                        }
                    }
                }
            }
        }
      }
    }
  }
}

/* Return the best possible move position. */
int best_move(int board) {
  int move1 = -1;
  int move2 = -1;
  int move3 = -1;

  for(int i = 0; i < 9; i++) {

    printf("%d: Score = %d   Hash = %d\n", i, htable[htable[board].move[i]].score, htable[board].move[i]);
    if(htable[htable[board].move[i]].init == 1) {
      if(htable[htable[board].move[i]].score == 1) {
        move1 = i;
      } else if(htable[htable[board].move[i]].score == 0) {
            move2 = i;
      } else if(htable[htable[board].move[i]].score == -1) {
            move3 = i;
      }
    }
  }
  printf("Move1: %d\n", move1);
  printf("Move2: %d\n", move2);
  printf("Move3: %d\n", move3);
  if(htable[board].turn == 'X') {
    if(move1 != -1) {
      return move1;
    } else if(move2 != -1) {
      return move2;
    } else {
      return move3;
    }
  } else {
    if(move3 != -1) {
      return move3;
    } else if(move2 != -1) {
        return move2;
    } else {
        return move1;
    }
  }

}
