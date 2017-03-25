#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
int main()
{
	DIR * d;
	struct dirent * dir;
	
	mkdir("rajat","w");
	chdir("rajat");
	//d=opendir("rajat");
	FILE *f;
	f=fopen("rafile.txt","w");
	fprintf(f,"here is some content of file");
	fclose(f);


	return 0;
}
