
#ifndef COMPAT_H_INCLUDED
#define COMPAT_H_INCLUDED

spkg_return_t spkg_mkpath(char* path, mode_t mode);
char* spkg_dirname(char* path);
char* spkg_basename(char* path);

#endif
