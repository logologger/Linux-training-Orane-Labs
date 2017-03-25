#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int  main(int argc,char * argv[])
{
	char opt;
	while((opt=getopt(argc,argv,"if:lr"))!=-1)
	{
		switch(opt)
		{
			case 'i':
			case 'l':
			case 'r':
				printf("options %c",opt);
				break;
			case 'f':
				printf("Filename %s\n",optarg);
				break;
			case ':':
				printf("Options needs a value");
				break;
			case '?':
				printf("Unknow option %s",optopt);
				break;


		}
	}
	for(;optind<argc;optind++)
	{
		printf("Argument %s",argv[optind]);
	}
	return 0;
}
