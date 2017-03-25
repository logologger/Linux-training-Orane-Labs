/* Inside A process there are several threads In this simple program we have created two threads by pthred_create fucntion defined in the pthread.h header file Then after creating those threads we have used pthread_join function defined in the pthread.h header file so that we will wait for the thread to finish first before the process actually  Thus we have made our thread to finish first and then have asked our process to finish after our thread have finished*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<pthread.h>
void error(char *message)
{
	fprintf(stderr,"%s:%s\n",message,strerror(errno));
	exit(1);
}
void* does_not(void *a)
{
	int i=0;
	for(i=0;i<5;i++)
	{
		sleep(1);
		puts("Does Not !");
	}
	return NULL;
}
void* does_too(void *a)
{
	int i=0;
	for(i=0;i<5;i++)
	{
		sleep(1);
		puts("Does too !");
	}
	return NULL;
}
int main()
{
	pthread_t t0,t1;
	if(pthread_create(&t0,NULL,does_too,NULL)==-1)
		error("Cant Create thread t0");
	if(pthread_create(&t1,NULL,does_not,NULL)==-1)
		error("cant Create thread t1");
	void * result;
	if(pthread_join(t0,&result)==-1)//join function waits for a thread to finish
		error("Cant join thread t0");
	if(pthread_join(t1,&result)==-1)
		error("Cant Join thread t1");


	return 0;
}
