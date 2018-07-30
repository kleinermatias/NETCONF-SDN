#include "posix_sem.h"

int main(int argc, char **argv)
{

	sem_t *sem_address;
	const char sem_name[100] = {"/40G_module"};
	int i = 0;
	int value;

	sem_address = sem_open(sem_name, O_CREAT | O_EXCL);

	printf("Semaphore address %x\n", sem_address);

	if (sem_address == SEM_FAILED)
	{
		sem_address = sem_open(sem_name, O_CREAT);
		printf("Semaphore already created and initialized\n");
	}
	else
	{
		sem_init(sem_address, 0, 1);
	    sem_getvalue(sem_address, &value);
	    printf("Semaphore initialized to %d\n", value);
	}

	if(argc == 3)
	{
		if (strcmp(argv[1], "sem_init") == 0)
		{

			int value = atoi(argv[2]);
			sem_init(sem_address, 0, value);
			sem_getvalue(sem_address, &value);
			printf("Semaphore forced to initial value %d\n", value);
		}
	}

	sem_wait(sem_address);

	for(i = 0; i < 7000; i++)
	{
			printf("Semaphore lock %d\n", i);
	}

	sem_post(sem_address);


	return 0;
}
