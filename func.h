#ifndef __FUNC_H__
#define __FUNC_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void cleanBuff     ();
char* fillBuffAkin (FILE* file_tree, char** arr);
size_t fileSize    (FILE* file_tree);

#endif // __FUNC_H__