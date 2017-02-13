/*
 * unixabs.c
 *
 *  Created on: 02/11/2016
 *      Author: thebeast
 */

#include <stdio.h>
#include <string.h>

#include "libspkg.h"
#include "compat.h"
#include "i18n.h"
#include "unixabs.h"
#include "compat.h"

void spkg_init_path(spkg_unix_path_t* path, char* raw_path)
{
	path->spkg_raw_path = raw_path;
	path->spkg_san_path = spkg_sanity_path(path->spkg_raw_path);
	path->spkg_dir_name = spkg_dirname(path->spkg_san_path);
	path->spkg_base_name = spkg_basename(path->spkg_san_path);

	if (strlen(path->spkg_san_path) > 0 )
	{
		path->spkg_target_type = spkg_get_unix_type(path->spkg_san_path);
	} else {
		path->spkg_target_type = SPKG_UNDEFINED;
	}
}
