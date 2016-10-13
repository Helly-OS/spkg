#!/bin/bash

export LD_LIBRARY_PATH=./libspkg
export LANG=es_ES.UTF-8

if [ -e spkg/spkg ]
then
	strace -e trace=open ./spkg/spkg $@
else
	printf '"%s" executable not found\n' 'spkg'
	exit 1
fi

exit $?
