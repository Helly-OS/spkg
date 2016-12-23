/*
 * unixabs.c
 *
 *  Created on: 02/11/2016
 *      Author: thebeast
 */

#include <stdio.h>

#include "libspkg.h"
#include "compat.h"
#include "i18n.h"
#include "unixabs.h"

void spkg_init_path(spkg_unix_path_t* path, char* raw_path)
{
	path->spkg_raw_path = raw_path;
	path->spkg_san_path = spkg_sanity_path(path->spkg_raw_path);
	path->spkg_dir_name = spkg_dirname(path->spkg_san_path);
	path->spkg_base_name = spkg_basename(path->spkg_san_path);
}
