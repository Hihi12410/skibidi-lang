#include "fileutil.h"

FILE* openFile(const char* path, const char mode)
{
	FILE* file = fopen(path, mode);

	if (file == NULL) { perror("Couldn't open file(s)!"); handleError(); }
	return &file;
}

int closeFile(FILE* file)
{
	fileCheck(file);

	int res = fclose(file);

	if (res == EOF) { perror("Couldn't close file(s)!"); handleError();}
	gcAdd(res);
	return res;
}

long getFileLen(FILE* file) 
{
	fileCheck(file);

	long currLine = ftell(file);
	if (currLine == EOF) { perror("Error determining pointer of file!"); handleError(); }
	
	if (fseek(file, 0, SEEK_END) != 0) { perror("Error seeking EOF!"); handleError(); }
	
	long len = ftell(file);
	
	if (len < 0) { perror("Error determining length of file(s)!"); ; }
	if (fseek(file, currLine, SEEK_SET) != 0) { perror("Error restoring file's pointer!"); handleError(); }
	
	gcAdd(&currLine);
	gcAdd(&len);
	return len;
}

char* readFile(FILE* file)
{
	fileCheck(file);

	long len = getFileLen(file);
	char *expo = (char *)malloc(len + 1);

	size_t res = fread(expo, sizeof(char), len, file);
	if (res != sizeof(expo)) { perror("Error reading file(s)!"); handleError(); }
	expo[len] = '\0';
	
	gcAdd(expo);
	gcAdd(&len);
	free(res);
	
	return expo;
}

void fileCheck(FILE* file) 
{
	if (file == NULL) { perror("Requested file is null!"); handleError(); }
}

int writeFile(FILE* file, char* dat)
{
	fileCheck(file);

	if (fwrite(dat, sizeof(char), strlen(dat), file) != strlen(dat)) { perror("Error writing file(s)!"); handleError(); }
	
	return 0;

}
