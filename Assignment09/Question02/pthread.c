#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *Fun(void *p)
{
    printf("Inside thread with Fun\n");
    for(int i=0;i<=500;i++) {
        printf("FUN : %d\n", i);
    }
    pthread_exit(NULL);
}

void *Gun(void *p)
{
    printf("Inside thread with Gun\n");
    for(int i=500;i>=1;i--) {
        printf("GUN : %d\n", i);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) 
{
    pthread_t thread1;
    pthread_t thread2;
    int ret;

    printf("Inside main thread\n");

    ret = pthread_create(&thread1,  
                        NULL,      
                        Fun,       
                        NULL);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread\n");
    }

    ret = pthread_create(&thread2,  
                        NULL,      
                        Gun,       
                        NULL);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread\n");
    }

    pthread_join(thread1,   
                 NULL);    

    pthread_join(thread2,   
                 NULL);    

    printf("Terminating the main thread\n");

    return 0;
}