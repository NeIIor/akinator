#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "../h/bin_tree.h"
#include "../h/dump.h"
#include "../h/html.h"

int main () {
    node_t* BIG_BOSS = NULL;
    FILE* file_tree = fopen ("file_tree.txt", "r");
    if (!file_tree) {
        printf("Unluck with opening stream file_tree");
    }

    char* arr =  fillBuff (file_tree);
    char* buff = arr;

    node_t* node = readAkin (&arr, NULL, &BIG_BOSS);
    free (buff);

    fclose (file_tree);
    optionAkin (node, BIG_BOSS);

    file_tree = fopen ("file_tree.txt", "w");
    if (!file_tree) {
        printf("Unluck with opening stream file_tree (2 time)");
    }

    printAkin (node, file_tree);
    fclose (file_tree);
    dumpAkin (node);
    destrAkin (node);

    return 0;
}
