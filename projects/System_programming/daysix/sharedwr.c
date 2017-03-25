#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/shm.h>
int main(int argc,char * argv[])
{
	int fd;
	size_t len;
	char *addr;
	//size of shared memory
	if(argc!=3 || strcmp(argv[1],"--help")==0)
	{
		printf("%s shm-name string\n",argv[0]);
		fd=shm_open(argv[1],O_RDWR,0);
		if(fd==-1)
		{
			printf("shm_open");
		}
		//open existing object
		len=strlen(argv[2]);
		if(ftruncate(fd,len)==-1)
			printf("ftrtruncate");
		//resize object to hold string
		printf("resized to %ld bytes\n",(long)len);
		addr=mmap(NULL,len,PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);
		if(addr==MAP_FAILED)
		{
			printf("mmap");
		}
		if(close(fd)==-1)
			printf("close");
		//fd is no longer needed
		printf("Copying %ld bytes\n",(long)len);
		memcpy(addr,argv[2],len);
		//copy string to shared memory
		exit(EXIT_SUCCESS);


	}
	return 0;
}
