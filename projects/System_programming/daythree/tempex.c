#include<stdio.h>
int main()
{
	char tmpname[L_tmpname];
	char * filename;
	FILE * tmpfp;
	filename=tmpnam(tmpname);
	printf("Temporary file name %s\n",filename);
	tmpfp=tmpfile();
	if(tmpfp)
	{
		printf("Opened a temporary file OK\n");
	}
	else
		perror("tmpfile");
	exit(0);
}
