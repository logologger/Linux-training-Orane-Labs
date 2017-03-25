#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_t ntid;
void printids(const char * s)
{
	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	printf("%s pid %lu tid %lu (ox%lx)\n",(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);

}
void *thr_fn(pid * arg)
{
	printids("New Thread");
	return ((void *)0);
}
int main()
{
	int err;
	err=pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err!=0)
	{
		err_exit(err,"CAnt Create Thread");
		printids("Main thread");
		sleep(1);
		exit(0);
	}
}
