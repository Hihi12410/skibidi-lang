#ifndef FILEUTIL
#define FILEUTIL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gc.h"

#ifndef FILEMODES
#define FILEMODES

#define READ 'r'
#define WRITE 'w'
#define APPEND 'a'
#define READWRITE 'r+'
#define WRITEREAD 'w+'
#define APPENDREAD 'a+'
#define BINREAD 'rb'
#define BINWRITE 'wb'
#define BINAPPEND 'ab'
#define BINREADWRITE 'rb+'
#define BINWRITEREAD 'wb+'
#define BINAPPENDREAD 'ab+'

#endif // !FILEMODES

FILE* openFile(const char* path,const char mode);
int closeFile(FILE* file);

FILE* readFile(FILE* file);
int writeFile(FILE* file, char* dat);

void fileCheck(FILE* file);

#endif // !FILEUTIL
