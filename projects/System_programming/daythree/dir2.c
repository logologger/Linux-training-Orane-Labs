#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/type.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
	mkdir("test2","w");
	mkdir("test","w");
	chdir("test");
	FILE * f;
	f=fopen("file.txt","w");

	chdir("test2");
	

	return 0;
}
