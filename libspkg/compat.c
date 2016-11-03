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

char* spkg_remove_trailing_slash(char* path)
{
	size_t len = strlen(path);
	if((len > 0) && (path[len-1] == '/'))
		path[len-1] = '\0';

	return path;
}

char* spkg_dirname(char* path)
{
	char* str = path;

	return str;
}

char* spkg_basename(char* path)
{
	char* str = path;
	
	return str;
}

