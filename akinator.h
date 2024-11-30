#ifndef __AKINATOR_H__
#define __AKINATOR_H__

#include "gen.h"
#include "func.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

const char yes[] = "yes\n";
const char no [] = "no\n";
const char define[] = "define\n";
const char compare[] = "compare\n";
const char akin[] = "akinator\n";

const int SIZE_ANSWER   =   4;
const int SIZE_SING     = 100;
const int SIZE_OBJECT   = 100; 
const int SIZE_OPTION   = 100;
const int MAX_DEPTH     =  10;

typedef struct {
    char* data;
    bool  flag;
} path_t;

node_t* createNodeAkin         (data_t data, node_t* node);
void printAkin                 (node_t* node, FILE* file_tree);
void destrAkin                 (node_t* node);
void akinator                  (node_t* node);
void addObjectiveAkin          (node_t* node, char* sign, char* object, char* parent);
node_t* readAkin               (char** arr, node_t* otets, node_t** root);
void readWordAkin              (char** arr, char* word);
int lenWordAkin                (char*  arr);
int defAkin                    (node_t* node, char* object);
int compAkin                   (node_t* node, char* object1, char* object2, path_t* path1, path_t* path2);
void optionAkin                (node_t* node, node_t* root);
int defSaveAkin                (node_t* node, char* object, path_t* path, int* i);

#endif //__AKINATOR_H__