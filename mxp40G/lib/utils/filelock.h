/*
 * filelock.h
 *
 *  Created on: 18/08/2016
 *      Author: pmartinez
 */

#ifndef FILELOCK_H_
#define FILELOCK_H_

// semaphore flags: O_* constants
#include <fcntl.h>
// semaphore modes: S_* constants
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#ifndef O_CLOEXEC
#define O_CLOEXEC 02000000
#endif

int filelock_open(const char filename[]);
int filelock_lock(int fd);
int filelock_lock_timeout(int fd, int timeout);
int filelock_unlock(int fd);
int filelock_close(int fd);
int filelock_locknb(int fd);

#endif /* FILELOCK_H_ */
