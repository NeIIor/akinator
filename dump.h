#ifndef DUMPNAHUY_H
#define DUMPNAHUY_H
#include "bin_tree.h"
#include <stdio.h>
#include <stdint.h>

const char yes[] = "yes";
const char no[] = "no";

const char adding_html_first[] = "\n"
                                "digraph structs {\n"
                                "charset = \"UTF-8\";\n"
                                "rankdir=TB;\n"
                                "bgcolor = \"#0000aa\";\n"
                                "fontcolor = black;\n"
                                "fontsize = 18;\n"
                                "style = \"rounded\";\n"
                                "margin = 0.3;\n"
                                "ranksep = 1.0;\n"
                                "nodesep = 0.9;\n"
                                "bgcolor = \"#78FFDB\";\n"
                                "edge [color=\"#FF69B4\"];\n"
                                "\n";

void dumpAkin               (node_t* node);
void printDotAkin           (node_t* node, FILE* file);
void printNodeAkin          (node_t* node, FILE* file);

#endif // DUMPNAHUY_H