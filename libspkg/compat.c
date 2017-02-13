#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <sys/stat.h>

#include "libspkg.h"
#include "compat.h"

spkg_status_t spkg_mkpath(char* path, mode_t mode)
{
	int errno;

	struct stat sb;
	if (!path)
	{
		errno = EINVAL;
		return 1;
	}

	if (!stat(path, &sb))
		return 0;

	if(spkg_mkpath(dirname(strdup(path)), mode) != SPKG_SUCCESS)
		return SPKG_FAILED;

	mkdir(path, mode);

	switch(errno)
	{
	case EACCES:
		printf( l_("Unable to write on parent directory\n"));
		return SPKG_FAILED;
	case EROFS:
		printf( l_("Failed to create directory, read-only file system\n"));
		return SPKG_FAILED;
	case EEXIST:
		printf( l_("Directory already exists\n"));
		return SPKG_FAILED;
	}

	return SPKG_SUCCESS;
}

char* spkg_sanity_path(char* path)
{	
	if(strlen(path) == 0)
		return path;

	char* strPtr1 = strdup(path);

	const char* src = strPtr1;
	char* dst = strPtr1;
 
	while ((*dst = *src) != '\0') 
	{
		do {
			src++;
		} while ((*dst == '/' || *dst == '\\')  && (*src == '/' || *src == '\\'));
			
		dst++;
	}

	char* strPtr2 = strdup(strPtr1);
	size_t len = strlen(strPtr2);

	if((len > 0) && (strPtr2[len-1] == '/'))
			strPtr2[len-1] = '\0';

	return strPtr2;
}

char* spkg_dirname(char* path)
{
	if(strlen(path) == 0)
		return path;

	char* str = strdup(path);
	char* dname = dirname(str);

	return dname;
}

char* spkg_basename(char* path)
{
	if(strlen(path) == 0)
		return path;

	char* str = strdup(path);
	char* bname = basename(str);

	return bname;
}

spkg_unix_t spkg_get_unix_type(char* str)
{
	spkg_unix_t outCode = SPKG_UNDEFINED;

    struct stat fileStat;
    if(stat(str,&fileStat) == 0)
    {
    	if(S_ISREG(fileStat.st_mode))
    		return SPKG_FILE;
    }

	return outCode;
}


