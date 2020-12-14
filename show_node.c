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
    compute_score();

    for (int counter = 1; counter< argc; counter++) print_node(htable[atoi(argv[counter])]);
    
    return 0;
}
