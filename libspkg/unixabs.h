/*
 * unixabs.h
 *
 *  Created on: 02/11/2016
 *      Author: thebeast
 */

#ifndef LIBSPKG_UNIXABS_H_
#define LIBSPKG_UNIXABS_H_

typedef struct
{
	char* spkg_raw_path;
	char* spkg_san_path;
	char* spkg_dir_name;
	char* spkg_base_name;
	spkg_unix_t spkg_target_type;
	spkg_status_t spkg_target_status;
}spkg_unix_path_t;

void spkg_init_path(spkg_unix_path_t* path, char* raw_path);

#endif /* LIBSPKG_UNIXABS_H_ */
