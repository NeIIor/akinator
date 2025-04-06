#ifndef __FUNC_H__
#define __FUNC_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void cleanBuff     ();
char* fillBuff     (FILE* file_tree);
size_t fileSize    (FILE* file_tree);

#endif // __FUNC_H__