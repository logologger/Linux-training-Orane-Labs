#include<stdio.h>
#include<stdlib.h>
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
static void usageError(const char * progName)
{
	fprintf(stderr,"usage:%s [-n] name \n",progName);
	fprintf(stderr,"-n use O_NONBLOCK flag\n");
	exit(EXIT_FAILURE);
}
int main(int argc,char *argv[])
{
	int flags,opt;
	mqd_t mqd;
	unsigned int prio;
	void *buffer;
	struct mq_attr attr;
	ssize_t numRead;
	flags=O_RDONLY;
	while((opt=getopt(argc,argv,"n"))!=-1)
	{
		switch(opt)
		{
			case 'n':
				flags|=O_NONBLOCK;
				break;

			default:
				usageError(argv[0]);

		}
	}
	if(optind>=argc)
		usageError(argv[0]);
	mqd=mq_open(argv[optind],flags);
	if(mqd==(mqd_t)-1)
		printf("mq_open\n");
	if(mq_getattr(mqd,&attr)==-1)
		printf("mq_attr\n");
	buffer = malloc(attr.mq_msgsize);
	if(buffer==NULL)
		printf("malloc\n");
	numRead = mq_receive(mqd,buffer,attr.mq_msgsize,&prio);
	if(numRead==-1)
		printf("mq_recieve\n");
	printf("read %ld bytes;priority =%u",(long)numRead,prio);
	if(write(STDOUT_FILENO,buffer,numRead)==-1)
		printf("write");
	write(STDOUT_FILENO,"\n",1);
	exit(EXIT_SUCCESS);


}
