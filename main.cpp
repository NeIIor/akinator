#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bin_tree.h"
#include "dump.h"
#include "html.h"

int main () {
    FILE* file_tree = fopen ("file_tree.txt", "r");
    assert (file_tree);

    char* arr;
    arr =  fillBuffAkin (file_tree, &arr);
    assert (arr);
    arr++;

    node_t* node = readAkin (&arr, NULL);
    assert (node);

    fclose (file_tree);
    akinator (node);

    file_tree = fopen ("file_tree.txt", "w");
    assert (file_tree);

    printAkin (node, file_tree);
    fclose (file_tree);
    dumpAkin (node);
    destrAkin (node);

    return 0;
}