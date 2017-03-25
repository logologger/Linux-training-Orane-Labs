//this program displays 20 lines at a time (Little incorrect and modification needed
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *f;
	int count=0;
	char c;
	f=fopen("file.txt","r");
	while((c=fgetc(f))!=NULL)
	{
		if(c=='\n')
		{
			count++;
		}
		if(count==20)
			exit(1);
		else
		{
			printf("%c",c);
		}
	}
	return 0;
}
