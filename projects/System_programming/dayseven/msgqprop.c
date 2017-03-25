//this program displays the properties of the message queues
#include<stdio.h>
#include<stdlib.h>
#include<mqueue.h>
int main(int argc,char * argv[])
{
	mqd_t mqd;
	struct mq_attr attr;
	if(argc!=2 || strcmp(argv[1],"--help")==0)
	{
		printf("%s mq-name\n",O_RDONLY);
	}
		if(mqd==(mqd_t)-1)
		{
			printf("mq_open");
		}
		if(mq_getattr(mqd,&attr)==-1)
		{
			printf("mq_getattr");
		}
		printf("max of message on queue:%ld \n",attr.mq_maxmsg);
		printf("Maximum message size %ld",attr.mq_msgsize);
		printf("max mess size:%ld\n",attr.mq_curmsgs);
		exit(EXIT_SUCCESS);


	

}
