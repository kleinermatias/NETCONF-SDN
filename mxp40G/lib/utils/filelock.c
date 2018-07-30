/*
 * filelock.c
 *
 *  Created on: 18/08/2016
 *      Author: pmartinez
 */
#include "filelock.h"

int filelock_open(const char filename[])
{
	int fd;
	fd = open(filename, O_RDWR | // open the file for both read and write access
				O_CREAT | // create file if it does not already exist
				O_CLOEXEC, // close on execute
				S_IRUSR | S_IWUSR); // // user permission: read, user permission: write, 600 here

	if (fd == -1) {
		perror("open() failed");
		exit(EXIT_FAILURE);
	}

	return fd;
}

/* lock the file*/
int filelock_lock(int fd)
{
	errno = 0;
	if (lockf( fd, F_LOCK, 0 ) == -1) {
		perror("lockf() failed");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

/* lock the file*/
int filelock_lock_timeout(int fd, int timeout)
{
	errno = 0;
	if (lockf( fd, F_TLOCK, 0 ) == -1) {
		perror("filelock_lock_timeout() wait");
		sleep(timeout);
		return -1;
	}

	return EXIT_SUCCESS;
}


int filelock_unlock(int fd)
{
	errno = 0;
	if (lockf( fd, F_ULOCK, 0 ) == -1) {
		perror("lockf() failed");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

/*  Exit the critical section.
 *  note that close() automatically releases the file lock.
 */
int filelock_close(int fd)
{
	errno = 0;
	if (close(fd) == -1) {
	    perror("close() failed");
	    exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
