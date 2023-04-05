#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int valThread1 = 0;
int valThread2 = 0;
char thread1Name[] = "Thread 1";
char thread2Name[] = "Thread 2";

void *threadRoutine(void *threadName){
    // thread id  is "thread 1" or "thread 2"

    char *thread = (char *)threadName;

    
    int i;
    for(i =0; i<5; i++){
        printf("%s: %d\n", thread, i);

    }
    pthread_exit(NULL);
}

int main()
{
    printf("launching threads\n");
    pthread_t thread1, thread2;

    pthread_create(&thread1,NULL, threadRoutine, thread1Name);
    pthread_create(&thread2,NULL, threadRoutine, thread2Name);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("threads finished\n");
    

    return 0;

    
}
