#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int count=0;
	FILE *f;
	char c;
	char c1;
	f=fopen("file.txt","w");
	printf("Enter the file which you want to delete");
	scanf("%d",&n);
	while((c=fgetc(f))!=NULL)
	{
		if(c=='\n')
			count++;
		else if(count==n)
		{
			//while((c1=fgetc(f))=='\n')
				printf("0");
				exit(0);
		}
		else
			printf("%c",c);
				

	}
	return 0;
}
