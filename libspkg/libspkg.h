#include "i18n.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#ifndef LIBSPKG_H_INCLUDED
#define LIBSPKG_H_INCLUDED

typedef enum
{
	SPKG_FALSE,
	SPKG_TRUE
} spkg_bool_t;

typedef enum
{
	SPKG_SUCCESS,
	SPKG_FAILED,
	SPKG_PERM_DENIED,
	SPKG_FILE_NOT_FOUND,
	SPKG_DIR_NOT_FOUND,
	SPKG_FAILED_TO_CREATE,
	SPKG_FAILED_TO_REMOVE
} spkg_return_t;

#define SPKG_BASE_DIR	"/var/spkg"
#define SPKG_DATA_DIR	"/var/spkg/data"
#define SPKG_PKGS_DIR	"/var/spkg/pkgs"
#define SPKG_TEMP_DIR	"/var/spkg/tmp"
#define SPKG_EXEC_DIR	"/var/spkg/exec"

#endif
