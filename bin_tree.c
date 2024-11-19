#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "bin_tree.h"
#include "dump.h"

node_t* createNodeAkin (char* data, node_t* node) {
    assert (data);

    node_t* new_node = (node_t*) calloc(1, sizeof(node_t));
    new_node->data_node = (char*) calloc(strlen(data) + 1, sizeof(char));
    strcpy(new_node->data_node, data);
    new_node->otets = node;
    new_node->no  = NULL;
    new_node->yes = NULL;
    return new_node;
}

void printAkin (node_t* node, FILE*  file_tree) {
    assert (node && file_tree);

    if(!node) return;

    fprintf (file_tree, "{");
    fprintf (file_tree, "%s", node->data_node);

    if (node->yes)  {printAkin (node->yes, file_tree);}
    if (node->no)   {printAkin (node->no, file_tree);}

    fprintf (file_tree, "}");
}

void destrAkin (node_t* node) {   
    if (node) {
        destrAkin   (node->yes);
        destrAkin   (node->no);
        free        (node->data_node);
        free        (node);
    }
}

void addObjectiveAkin (node_t* node, char* sing, char* object, char* parent) {

    assert (node);
    assert (sing);
    assert (object);
    assert (parent);

    node->no = createNodeAkin (parent, node);

    if (node->data_node != NULL) {
        free (node->data_node);
    }

    node->data_node = (char*) calloc(strlen(sing) + 1, sizeof(char));
    strcpy(node->data_node, sing);
    node->yes = createNodeAkin (object, node);

    return;
}

node_t* rootAkin (node_t* node) {
    assert (node);

    while (node->otets != NULL) {   
        node = node->otets;
    }

    return node;
}

node_t* readAkin (char** arr, node_t* otets) {
    assert (arr);

    char* word = (char*)calloc(SIZE_OBJECT, sizeof(char));

    readWordAkin (arr, word);
    
    node_t* node = createNodeAkin (word, otets);

    free(word);

    arr += lenWordAkin(*arr);
    
    if (**arr == '{') {
        (*arr)++; 
        node->yes = readAkin(arr, node);
        (*arr)++; 
    }

    if (**arr == '{') {
        (*arr)++; 
        node->no = readAkin (arr, node);
        (*arr)++;
    }

    return node;
}

void akinator (node_t* node) {
    assert (node);

    char answer[SIZE_ANSWER] = "";

    printf("The hidden object is %s?  ", node->data_node);

    scanf("%s", answer);
    
    if (strcmp (no, answer) == 0) {
        if (node->no == NULL && node->yes ==  NULL) {
            char sing[SIZE_SING] = "";
            char object[SIZE_OBJECT] = "";

            printf("I am very sorry if I could not meet your expectations or if there was an error in interaction.\n"
                "Please write the name of the object that was hidden: ");
            scanf("%s", object);

            printf("Please write a sign by which you can guess the object");
            
            scanf("%s", sing);

            addObjectiveAkin (node, sing, object, node->data_node);

            node = rootAkin (node); 
    
            akinator (node);
        }
        else {
            akinator (node->no);
        }    
    }

    if (strcmp (yes, answer) == 0) {
        if (node->no == NULL && node->yes ==  NULL){
            printf ("AXUENO UOUO");
            return;
        }
        else {
            akinator (node->yes);
        }
    }
}

void readWordAkin (char** arr, char* word) {
    assert (arr && word);

    char* remember_position = *arr;

    while (**arr != '{' && **arr != '}' && **arr != '\0') {
        (*arr)++;
    }
    
    strncpy(word, remember_position, *arr - remember_position);
}

int lenWordAkin (char* arr) {
    assert (arr);

    int i = 0;
    while (arr[i] != '{' && arr[i] != '}' && arr[i] != '\0') {
        i++;
    }

    return i;
}

size_t fileSize (FILE* file_tree) {
    assert (file_tree);

    fseek (file_tree, 0, SEEK_END);
    long int position = ftell (file_tree);
    size_t quentity_symbols = (size_t)position / sizeof(char);
    fseek (file_tree, 0, SEEK_SET);

    return quentity_symbols;
}

bool checkLeafAkin (node_t* node){
    assert (node);

    return node->no == NULL && node->yes ==  NULL;
}

char* fillBuffAkin (FILE* file_tree, char** arr){
    
    size_t size_arr = fileSize (file_tree);
    assert (file_tree);
    assert (arr);

    *arr = (char*)calloc(size_arr + 1, sizeof(char));
    assert (*arr);

    fread (*arr, sizeof(char), size_arr, file_tree);
    return *arr;
}