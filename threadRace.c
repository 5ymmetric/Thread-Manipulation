#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Replace Firstname and Lastname with your real name
#define NAME "Karthik Reddy Pagilla"

// Number of threads to create
#define NUMBER_OF_THREADS 8

// Increment and decrement loop bounds
#define MAX_COUNT 2000000

// initialize the global variable sharedCounter to 0
int sharedCounter=0;


void MyCounterPlus() {
	int i;
		for (i = 0; i < MAX_COUNT; i++)
			sharedCounter++;
}
void MyCounterMinus() {
	int i;
		for (i = 0; i < MAX_COUNT; i++)
			sharedCounter--;
}

int main(void)
{
	char * myName;
	int i;
	strcpy(myName,NAME);
	pthread_t thread[NUMBER_OF_THREADS];
	for (i = 0; i < NUMBER_OF_THREADS; i++)
	{
		if ((i % 2) != 0)
			pthread_create(&thread[i], NULL, (void *) MyCounterMinus, NULL);
		else
			pthread_create(&thread[i], NULL, (void *) MyCounterPlus, NULL);
	}
	for (i = 0; i < NUMBER_OF_THREADS; i++)
	{
		pthread_join(thread[i], NULL);
	}
	printf ("sharedCounter = %d\n", sharedCounter);
	return 0;
}
