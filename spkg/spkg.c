#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

#include "../libspkg/libspkg.h"
#include "../libspkg/list.h"
#include "../libspkg/compat.h"
#include "../libspkg/unixabs.h"

#include "spkg.h"

int spkg_init_config(spkg_config_t* config)
{
	/* Create uname struct */
	struct utsname udata;
	if ( (uname(&udata)) != 0 )
		return -1;

	/* Create sysinfo struct */
	struct sysinfo sinfo;
	if ( (sysinfo(&sinfo)) != 0 )
		return -1;

	/* Convert kinds from data[] to *data */
	char* sys_type = malloc(sizeof(char*));
	strcpy(sys_type, udata.sysname);

	char* sys_arch = malloc(sizeof(char*));
	strcpy(sys_arch, udata.machine);

	char* kernel_version = malloc(sizeof(char*));
	strcpy(kernel_version, udata.release);


	/* Fill system default data */
	config->spkg_os_type = sys_type;
	config->spkg_system_arch = sys_arch;
	config->spkg_total_memory = sinfo.totalram;
	config->spkg_cpu_count = get_nprocs();
	config->spkg_kernel_version = kernel_version;
	config->spkg_handle_archs = spkg_new_list();

	/* Set supported architectures */
	if(config->spkg_system_arch != NULL)
	{
		spkg_append_to_list(config->spkg_handle_archs, config->spkg_system_arch);
		if( strcmp(config->spkg_system_arch, "x86_64") == 0 )
			spkg_append_to_list(config->spkg_handle_archs, "i686");
		spkg_append_to_list(config->spkg_handle_archs, "noarch");
	}

	/* Now set default values for getopt options */
	config->spkg_default_root = SPKG_DEFAULT_ROOT;
	config->spkg_runtime_command = SPKG_NONE;
	config->spkg_check_run_deps = SPKG_CHECK_RUN_DEPS;
	config->spkg_check_run_conflicts = SPKG_CHECK_RUN_CONFLICTS;
	config->spkg_check_run_suggests = SPKG_CHECK_RUN_SUGGESTS;
	config->spkg_run_pkg_script = SPKG_RUN_PKG_SCRIPT;
	config->spkg_run_force_flag = SPKG_RUN_FORCE_FLAG;
	config->spkg_run_verbose_mode = SPKG_RUN_VERBOSE_MODE;
	config->spkg_run_silent_mode = SPKG_RUN_SILENT_MODE;

	return 0;
}

spkg_status_t spkg_create_struct(spkg_config_t config)
{
	spkg_unix_path_t test_path;
	spkg_init_path(&test_path, SPKG_BASE_DIR);

	printf(
		"Raw path: %s\n" \
		"Sanity path: %s\n" \
		"Dirname: %s\n" \
		"Basename: %s\n" \
		"Unix type: %d\n", \
		test_path.spkg_raw_path, \
		test_path.spkg_san_path, \
		test_path.spkg_dir_name, \
		test_path.spkg_base_name, \
		test_path.spkg_target_type \
	);

/*
	int i;
	char* root_path = config.spkg_default_root;
	size_t root_len = strlen(root_path);
	
	char* dirs[5] = {
		SPKG_BASE_DIR,
		SPKG_DATA_DIR,
		SPKG_EXEC_DIR,
		SPKG_PKGS_DIR,
		SPKG_TEMP_DIR
	};
			
	for(i=0; i<5; i++)
	{
		size_t dir_len = strlen(dirs[i]);
		size_t path_len = root_len + dir_len + 1;
		
		char* path = (char*)malloc(path_len);
		strncat(path, root_path, root_len);
		strncat(path, dirs[i], dir_len);

		spkg_mkpath(path, 0755);
		free(path);
	}
*/
	return SPKG_SUCCESS;
}


void spkg_show_help(void)
{
	printf(t_(
			"spkg is a generic Linux and BSD package manager\n"
			"\n"
			"Usage :\n"
			"spkg [OPTIONS] [PACKAGES]\n"
			"\n"
			"-h, --help   Show this help and exit\n"
			"-I, --initdb Start database estructure\n"
	));
}
