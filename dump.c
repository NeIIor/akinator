#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <assert.h>

#include "dump.h"

void dumpAkin  (node_t* node) {
    assert (node);
    
    struct timeval tv;
    gettimeofday (&tv, NULL);
    long seconds = tv.tv_sec;
    long microseconds = tv.tv_usec;

    char filename[SIZE_FILENAME] = {0};
    snprintf (filename, sizeof(filename), "file_%ld_%06ld.dot",  seconds, microseconds);
    
    FILE* file_html = fopen ("dump.html", "a+");
    assert (file_html && "file open err");

    FILE* file_dump = fopen (filename, "a+");
    assert (file_dump && "file open err");

    fprintf (file_dump, "%s", adding_html_first);

    printNodeAkin (node, file_dump);
    
    printDotAkin (node, file_dump);

    char command[SIZE_COMMAND] = {};
    snprintf (command, sizeof(command), "dot -Tpng %s -o %.22s.png", filename, filename);
    snprintf (filename, sizeof(filename), "file_%ld_%06ld.png",  seconds, microseconds);
    fprintf  (file_html, "\t<img src=\"%s\"/>\n", filename);
    fprintf  (file_dump, "}\n");
    fclose   (file_dump);   
    system   (command);
    fclose   (file_html);

    return;
}

void printDotAkin (node_t* node, FILE* file) {
    assert (node);

    if(!node) return; 

    if (node->yes) {
        fprintf   (file, "\"%s\":<f2> -> \"%s\"\n", node->data_node, node->yes->data_node);
        printDotAkin (node->yes, file);
    }
    if (node->no) {
        fprintf   (file, "\"%s\":<f1> -> \"%s\"\n", node->data_node, node->no->data_node);
        printDotAkin (node->no, file);
    }
}

void printNodeAkin (node_t* node, FILE* file) {
    assert (node);

    if(!node) return; 
    void* pointer = (void*)(uintptr_t)node->data_node; 
    fprintf (file, "\"%s\"[shape=record, label= \"{ip: %p | data: %s | {<f1> no | <f2> yes}}\"];\n", 
    node->data_node, pointer, node->data_node);

    if (node->no)   {printNodeAkin (node->no, file);}
    if (node->yes)  {printNodeAkin (node->yes, file);}
}