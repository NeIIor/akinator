#include "../h/func.h"

void cleanBuff () {
    char c;
    while ((c = getchar()) != '\n');
}

char* fillBuff (FILE* file_tree){
    
    size_t size_arr = fileSize (file_tree);
    assert (file_tree);

    char* arr = (char*)calloc(size_arr + 1, sizeof(char));
    if (!arr) {
        printf("Unluck with allocating memory for arr");
    }

    fread (arr, sizeof(char), size_arr, file_tree);
    return arr;
}

size_t fileSize (FILE* file_tree) {
    assert (file_tree);

    fseek (file_tree, 0, SEEK_END);              // split files
    long int position = ftell (file_tree);
    size_t quantity_symbols = (size_t)position / sizeof(char);
    fseek (file_tree, 0, SEEK_SET);

    return quantity_symbols;
}