#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	chmod("file.out",S_IXUSR | S_IWGRP);

	return 0;
}
