/*You have created here 20 threads that are all made to reduce the value of the variable beers from 2lakhs Now every thread wants to decerease the value of the variable but all acts on the same variable so the ouptut is not defined..THE CODE IS  NOT THREAD SAFE .All the threads have access to the same shared piece of memory .So the result is unpredictable .Thus for this reason  we use MUTEX --Mutually exclusive */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
int beers=2000000;
void * drinks(void *a)
{
	int i;
	for(i=0;i<10000;i++)
		beers=beers-1;
	return NULL;
}
int main()
{
	pthread_t threads[20];
	int t;
	printf("%d bottles of beer on the wall \n %d bottles of bear\n",beers,beers);
	for(t=0;t<20;t++)
	{
		pthread_create(&threads[t],NULL,drinks,NULL);
	}
	void * result;
	for(t=0;t<20;t++)
	{
		pthread_join(threads[t],&result);
	}
	printf("There are now %d bottles of beer on the wall\n",beers);
	return 0;
}
