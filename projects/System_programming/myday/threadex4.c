#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
int beers=2200000;
pthread_mutex_t beers_lock=PTHREAD_MUTEX_INITIALIZER;
void * drinks(void * a)
{
	int i;
	pthread_mutex_lock(&beers_lock);
	for(i=0;i<100000;i++)
	{
		beers=beers-1;
	}
	pthread_mutex_unlock(&beers_lock);
	printf("beers = %d\n",beers);
	return NULL;
}
int main()
{
	pthread_t threads[20];
	int t;
	printf("%d bottles of beers on the wall \n %d bottles of beer\n",beers,beers);
	for(t=0;t<20;t++)
	{
		pthread_create(&threads[t],NULL,drinks,NULL);
	}
	void * result;
	for(t=0;t<20;t++)
	{
		pthread_join(threads[t],&result);
	}
	printf("There are now %d bottles of beers on the wall\n",beers);
	return 0;
}
