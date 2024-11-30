#include "bin_tree.h"

node_t* BIG_BOSS;

void printAkin (node_t* node, FILE* file_tree) {
    assert (node && file_tree);

    if(!node) return;

    fprintf (file_tree, "{%s", node->data_node);

    if (node->yes)  {printAkin (node->yes, file_tree);}
    if (node->no)   {printAkin (node->no,  file_tree);}

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

void addObjectiveAkin (node_t* node, char* sign, char* object, char* parent) {

    assert (node);
    assert (sign);
    assert (object);
    assert (parent);

    node->no = createNode (parent, node);

    if (node->data_node != NULL) {
        free (node->data_node);
    }

    node->data_node = (char*) calloc(strlen(sign) + 1, sizeof(char));
    strcpy(node->data_node, sign);
    node->yes = createNode (object, node);

    return;
}

node_t* readAkin (char** arr, node_t* otets) {
    assert (arr);

    (*arr)++; 
    int len = lenWordAkin(*arr);
    char* word = (char*) calloc (len + 1, sizeof(char));

    readWordAkin (arr, word);
    printf("%s", word);
    
    node_t* node = createNode (word, otets);
    
    if (!otets) {
        BIG_BOSS = node;
    }

    //(*arr) += len;
    
    if (**arr == '{') {
        node->yes = readAkin(arr, node);
    }

    if (**arr == '{') {
        node->no = readAkin (arr, node);
    }
    (*arr)++;

    return node;
}

void akinator (node_t* node) {
    char answer[SIZE_ANSWER + 1] = "";

    while (true) {
        printf("The hidden object is %s?  ", node->data_node);
        fgets (answer, SIZE_ANSWER + 1, stdin);
        answer[SIZE_ANSWER] = '\0';

        if (!node->yes & !node->no) {
            if (!strcmp (no, answer)) {
                char* sign = (char*) calloc (SIZE_SING, sizeof(char));
                char* object = (char*) calloc (SIZE_OBJECT, sizeof(char));

                printf("I am very sorry if I could not meet your expectations or if there was an error in interaction.\n"
                    "Please write the name of the object that was hidden: ");

                scanf("%[^\n]", object);
                object[SIZE_SING - 1] = 3;
                cleanBuff();

                printf("Please write a sign by which you can guess the object: ");
                scanf("%[^\n]", sign);
                cleanBuff();

                addObjectiveAkin (node, sign, object, node->data_node);

                free (sign);
                free (object);

                akinator (BIG_BOSS);
                return;
            } else if (!strcmp(yes, answer)){
                printf ("KAAAAAYYYYYF");
                return;
            } else {
                cleanBuff();
                printf("Answer only yes or no\n");
            }
        } else {
            if (!strcmp (no, answer)) {
                node = node->no;
            } else if (!strcmp (yes, answer)) {
                node = node->yes;
            } else {
                cleanBuff();
                printf("Answer only yes or no\n");
            } 
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

int defAkin (node_t* node, char* object) {
    if (strcmp(object, node->data_node)) {
        if (node->yes) {
            if (defAkin (node->yes, object)) {
                printf(", %s", node->data_node);
                return 1;
            }
        }
        if (node->no) {   
            if (defAkin (node->no, object)) {
                printf(", not %s", node->data_node);
                return 1;
            }
        }
        return 0;
    } else {  
        printf("%s -", node->data_node);
        return 1;
    }
}


int compAkin  (node_t* node, char* object1, char* object2, path_t* path1, path_t* path2) {
    int i1 = 0, i2 = 0;
    if (!defSaveAkin (node, object1, path1, &i1)) {
        return 0;
    } 

    for (int i = 0; i < i1; i++) {
        printf("%s\n", path1[i].data);
    }

    if (!defSaveAkin (node, object2, path2, &i2)) {
        return 0;
    } 

    for (int i = 0; i < i2; i++) {
        printf("%s\n", path2[i].data);
    }

    printf("%s and %s are both", path1[0].data, path2[0].data);
    for (int i = 0; i < i1; i++) {
        for (int j = 0; j < i2; j++) {
            if (!strcmp(path1[i].data, path2[j].data) && path1[i].flag && path2[j].flag) {
                printf(" %s", path1[i].data);
            } else if (!strcmp(path1[i].data, path2[j].data) && !path1[i].flag && !path2[j].flag) {
                printf(" not %s", path2[i].data);
            }
        }
    }
    int i = 0;
    for (; i < MIN(i1, i2); i++) {
        if (path1[i1 - 1 -i].flag != path2[i2 - 1 - i].flag) {
            break;
        }
    }
    printf(", but %s --", path1[0].data);
    for (int j = i1 - 1 - i; j >= 1; j--) {
        if (!path1[j].flag)
            printf(", not %s", path1[j].data);
        else 
            printf(", %s", path1[j].data);
    }

    printf(", in addition %s --", path2[0].data);
    for (int j = i2 - 1 - i; j >= 1; j--) {
        if (!path2[j].flag)
            printf(", not %s", path2[j].data);
        else
            printf(", %s", path2[j].data);
    }
    return 1;
}

void optionAkin (node_t* node) {
    assert(node);
    char option[SIZE_OPTION + 1] = "";
    printf("Choose only one option from these: define/compare/akinator ");

    while (true) {
        fgets(option, SIZE_OPTION + 1, stdin);
        option[SIZE_OPTION] = '\0';

        if (!strcmp(akin, option)) {
            akinator(node);
            break;
        } else if (!strcmp(define, option)) {
            char object[SIZE_OBJECT + 1] = "";
            printf("Write smth that u want to be defined: ");

            // fgets (object, SIZE_OBJECT, stdin);
            // object[SIZE_OBJECT] = '\0';
            scanf("%[^\n]", object);

            if (!defAkin (node, object)) {
                printf("No such phrase in my data\n");
            }

            break;
        } else if (!strcmp(compare, option)) {
            printf("Write 2 objects that u want to be compared, separated by \\n ");
            char object1[SIZE_OBJECT + 1] = "";
            char object2[SIZE_OBJECT + 1] = "";

            scanf("%[^\n]", object1);
            scanf("%*c");
            printf("%s\n", object1);
            scanf("%[^\n]", object2);
            scanf("%*c");
            printf("%s\n", object2);

            path_t* path1 = (path_t*) calloc (MAX_DEPTH, sizeof(path_t));
            path_t* path2 = (path_t*) calloc (MAX_DEPTH, sizeof(path_t));

            for (int i = 0; i < MAX_DEPTH; i++) {
                path1[i].data = (char*) calloc (SIZE_OBJECT, sizeof(char));
                path2[i].data = (char*) calloc (SIZE_OBJECT, sizeof(char));
            }
            
            if (!compAkin (node, object1, object2, path1, path2)) {
                printf("No at least one of 2 objects\n");
            }
            
            for (int i = 0; i < MAX_DEPTH; i++) {
                free(path1[i].data);
                free(path2[i].data);
            }

            free(path1);
            free(path2);

            break;
        } else {
            cleanBuff();
            printf("Write only define/compare/akinator ");
        }
    }
}

int defSaveAkin (node_t* node, char* object, path_t* path, int* i) {
    if (strcmp(object, node->data_node)) {
        if (node->yes) {
            if (defSaveAkin (node->yes, object, path, i)) {
                path[*i].data = node->data_node;
                path[*i].flag = true;
                (*i)++;
                return 1;
            }
        }
        if (node->no) {   
            if (defSaveAkin (node->no, object, path, i)) {
                path[*i].data = node->data_node;
                path[*i].flag = false;
                (*i)++;
                return 1;
            }
        }
        return 0;
    } else {  
        path[*i].data = node->data_node;
        (*i)++;
        return 1;
    }
}