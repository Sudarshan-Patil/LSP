#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *Fun1(void *p)
{
    printf("Inside thread with Fun1\n");
    pthread_exit(NULL);
}

void *Fun2(void *p)
{
    printf("Inside thread with Fun2\n");
    pthread_exit(NULL);
}

void *Fun3(void *p)
{
    printf("Inside thread with Fun3\n");
    pthread_exit(NULL);
}

void *Fun4(void *p)
{
    printf("Inside thread with Fun4\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) 
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;

    int ret;

    printf("Inside main thread\n");

    ret = pthread_create(&thread1,  
                        NULL,      
                        Fun1,       
                        NULL);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread1\n");
    }

    ret = pthread_create(&thread2,  
                        NULL,      
                        Fun2,       
                        NULL);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread2\n");
    }

    ret = pthread_create(&thread3,  
                        NULL,      
                        Fun3,       
                        NULL);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread3\n");
    }

    ret = pthread_create(&thread4,  
                        NULL,      
                        Fun4,       
                        NULL);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread4\n");
    }

    pthread_join(thread1,
                 NULL);
    pthread_join(thread2,
                 NULL);
    pthread_join(thread3,
                 NULL);
    pthread_join(thread4,
                 NULL);                                  

    printf("Terminating the main thread\n");

    return 0;
}