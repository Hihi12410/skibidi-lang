#include "fileutil.h"

FILE* openFile(const char* path,const char* mode)
{
	FILE* file = fopen(path, mode);
	
	if (file == NULL) { perror("Couldn't open file(s)!"); handleError(); exit(1); }
	return &file;
}

int closeFile(FILE* file)
{
	int res = fclose(file);

	if (res == EOF) { perror("Couldn't close file(s)!"); handleError(); exit(1); }
	gcAdd(res);
	return res;
}

long getFileLen(FILE* file) 
{

	long currLine = ftell(file);
	if (currLine == EOF) { perror("Error determining pointer of file!"); handleError();exit(1); }
	
	if (fseek(file, 0, SEEK_END) != 0) { perror("Error seeking EOF!"); handleError(); exit(1); }
	
	long len = ftell(file);
	
	if (len < 0) { perror("Error determining length of file(s)!"); exit(1); }
	if (fseek(file, currLine, SEEK_SET) != 0) { perror("Error restoring file's pointer!"); handleError();exit(1); }
	
	gcAdd(&currLine);
	gcAdd(&len);
	return len;
}

char* readFile(FILE* file)
{
	long len = getFileLen(file);
	char *expo = (char *)malloc(len + 1);

	size_t res = fread(expo, sizeof(char), len, file);
	if (res != sizeof(expo)) { perror("Error reading file(s)!"); handleError(); exit(1); }
	expo[len] = '\0';
	
	gcAdd(expo);
	gcAdd(&len);
	free(res);
	
	return expo;
}

int writeFile(FILE* file, char* dat, char mode)
{
	


	return 0;
}
