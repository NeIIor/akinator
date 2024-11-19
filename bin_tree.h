#ifndef __BIN_TREE__
#define __BIN_TREE__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

const int SIZE_FILENAME = 100;
const int SIZE_COMMAND  = 256;
const int SIZE_ANSWER   = 4;
const int SIZE_SING     = 100;
const int SIZE_OBJECT   = 25;

struct a{
    char* data_node;
    struct a* no;
    struct a* yes;
    struct a* otets;
} typedef node_t;

node_t* createNodeAkin         (char* data, node_t* node);
void printAkin                 (node_t* node, FILE* file_tree);
void destrAkin                 (node_t* node);
void akinator                  (node_t* node);
void addObjectiveAkin          (node_t* node, char* sing, char* object, char* parent);
node_t* rootAkin               (node_t* node);
node_t* readAkin               (char** arr, node_t* otets);
void readWordAkin              (char** arr, char* word);
int lenWordAkin                (char* arr);
char* fillBuffAkin             (FILE* file_tree, char** arr);
bool checkLeafAkin             (node_t* node);
size_t fileSize                (FILE* file_tree);

#endif //__BIN_TREE__