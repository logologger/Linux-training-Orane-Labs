#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
static void 
usageError(const char *progName)
{
	fprintf(stderr,"Usage %s [-cx] name size[octal-param]\n",progName);
	fprintf(stderr,"-c Create a shared memory [O_CREAT]
}
