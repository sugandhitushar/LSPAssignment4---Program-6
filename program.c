#include"program.h"

void *ThreadProc(void *arg)
{
	int argument = *((int *) arg), i;
	printf("THREAD %d\n",argument);
	if(1 == argument)
	{
		for(i=0;i<5;i++)
			printf("Thread 1: Count=%d\n",i);
	}
	else if(2 == argument)
	{
		for(i=5;i>0;i--)
			printf("Thread 2: Count=%d\n",i);		
	}
	else if(3 == argument)
	{
		for(i=6;i<=10;i++)
			printf("Thread 3: Count=%d\n",i);
	}
	else if(4 == argument)
	{
		for(i=10;i>5;i--)
			printf("Thread 4: Count=%d\n",i);		
	}	
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1,thread2,thread3,thread4;
	int ret,val[4]={1,2,3,4};
	
	ret = pthread_create(&thread1, NULL, ThreadProc,(void *) &val[0]);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	
	ret = pthread_create(&thread2, NULL, ThreadProc,(void *) &val[1]);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	
	ret = pthread_create(&thread3, NULL, ThreadProc,(void *) &val[2]);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	
	ret = pthread_create(&thread4, NULL, ThreadProc,(void *) &val[3]);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	pthread_join(thread4,NULL);
	
	printf("All Threads terminated. Terminating main thread.\n");
	
	pthread_exit(NULL);
	return 0;
}

