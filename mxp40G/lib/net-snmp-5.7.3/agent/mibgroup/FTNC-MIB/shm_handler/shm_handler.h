#ifndef SHM_HANDLER_H_
#define SHM_HANDLER_H_

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "../../../../../hl_configs/definitions.h"

static int shm_fd;

void shm_handler_init(Monitor *pt_monitor_struct)
{
    shm_fd = shm_open(SHMOBJ_PATH, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
	if (shm_fd < 0)
	{
		printf("Error in SHM_OPEN () \n");
		perror("In shm_open()");
		exit(1);
	}

	size_t SHM_SIZE = sizeof(Monitor);

	ftruncate(shm_fd, SHM_SIZE);

	pt_monitor_struct = (Monitor *) mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

	if (pt_monitor_struct == NULL)
	{
		printf("Error in mmap() \n");
		perror("In mmap()");
		exit(1);
	}

//	close (shm_fd);
}

void shm_handler_create(Monitor *pt_monitor_struct)
{
    if (!shm_fd)
    	shm_handler_init(pt_monitor_struct);
}


#endif /* SHM_HANDLER_H_ */
