#ifndef FILEUTIL
#define FILEUTIL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gc.h"


FILE* openFile(char* path, char mode);
int closeFile(FILE* file);

FILE* readFile(FILE* file);
int writeFile(FILE* file, char* dat, int mode);



#endif // !FILEUTIL
