#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
void * do_stuff(void * param)//thread function always has void * parameter and void * return type
{
	long thread_no=(long)param;//type cast it to long as void* and long are both have equal meaning
	printf("thread number %ld\n",thread_no);
	return (void*)(thread_no+1);//type cast it back to void*
}
int main()
{
	pthread_t threads[20];
	long t;
	for(t=0;t<3;t++)
	{
		pthread_create(&threads[t],NULL,do_stuff,(void *)t);
	}
	void * result;//store the return value
	for(t=0;t<3;t++)
	{
		pthread_join(threads[t],&result);
		printf("Thread %ld returned %ld\n",t,(long)result);

	}
	return 0;
}
