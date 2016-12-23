#include <sys/stat.h>

#ifndef COMPAT_H_INCLUDED
#define COMPAT_H_INCLUDED

spkg_status_t spkg_mkpath(char* path, mode_t mode);
char* spkg_sanity_path(char* path);
char* spkg_dirname(char* path);
char* spkg_basename(char* path);

#endif
