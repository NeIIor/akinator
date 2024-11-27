#include "bin_tree.h"

node_t* createNode (char* data, node_t* node) {
    assert (data);

    node_t* new_node = (node_t*) calloc(1, sizeof(node_t));
    new_node->data_node = data;
    new_node->otets = node;
    new_node->no  = NULL;
    new_node->yes = NULL;
    return new_node;
}
