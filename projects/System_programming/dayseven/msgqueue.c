//This concepts of IPC ,shared memory and message queue helps in the development of projects like CDROM burning , messenger,etc

#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
static void usageError(const char *progName)
{
	fprintf(stderr,"usage: %s [-cx] [-m maxmsg] [-s msgsize] mq-name " "[octal-perms]\n");
	fprintf(stderr,"-c Create queue(O_CREAT)\n");
	fprintf(stderr," -m maxmsg set maximum # of messages\n");
	fprintf(stderr," -s msgsize set maximum usage size \n");
	fprintf(stderr  ," -x create exclusively (O_EXCL)\n");
	exit(EXIT_FAILURE);
}
int main(int argc,char * argv[])
{

int flags,opt;
mode_t perms;
mqd_t mqd;
struct mq_attr attr,*attrp;
attrp=NULL;
attr.mq_maxmsg=50;
attr.mq_msgsize=2048;
flags=O_RDWR;
while((opt=getopt(argc,argv,"cm:s:x"))!=-1)
{
switch (opt)
{
	case 'c':
		flags|=O_CREAT;
		break;
	case 'm':
		attr.mq_maxmsg=atoi(optarg);
		attrp=&attr;
		break;
	case 's':
		attr.mq_msgsize=atoi(optarg);
		attrp=&attr;
		break;
	case 'x':
		flags|=O_EXCL;
		break;
	default:
		usageError(argv[0]);
		perms=(argc<=optind+1?(S_IRUSR|S_IWUSR):atoi(argv[optind+1]));
		mqd=mq_open(argv[optind],flags,perms,attr);
		if(mqd==(mqd_t)-1)
		printf("mq_open");
		exit(EXIT_SUCCESS);

}
}
}
