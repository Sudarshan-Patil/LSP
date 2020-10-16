#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *Fun(void *p)
{
    printf("Inside thread with Fun\n");
    printf("From the Fun function, the thread id = %d\n", pthread_self()); //get current thread id
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) 
{
    pthread_t thread;
    int ret;

    printf("Inside main thread\n");

    ret = pthread_create(&thread,  
                        NULL,      
                        Fun,       
                        NULL);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread\n");
    }

    pthread_join(thread,   
                 NULL);    
    
    printf("Terminating the main thread\n");

    return 0;
}