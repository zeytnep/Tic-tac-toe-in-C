/*
Zeynep Erdogru
EMAIL: zeyneperdogru99@gmail.com 
*/

#include "ttt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);
    int counter = 0;

    for (int i=0; i<HSIZE; i++) {
        if(htable[i].init ==1) counter++;
    }
    printf(" %d\n", counter);

    return 0;
}
