#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *Fun(void *p)
{
    printf("Inside thread with Fun\n");
    int num=p;
    for(int i=0;i<=(int)p;i++) {
        printf("FUN : %d\n", i);
    }
    pthread_exit(num);
}


int main(int argc, char *argv[]) 
{
    pthread_t thread;
    int ret;
    int num=atoi(argv[1]);    
    int result = 0;

    printf("Inside main thread\n");

    ret = pthread_create(&thread,  
                        NULL,      
                        Fun,       
                        (void *)num);     
    
    if (ret != 0)  
    {
        printf("Unable to create thread\n");
    }

    pthread_join(thread,   
                 &result);    

    printf("Return value of thread is %d\n", result);
    printf("Terminating the main thread\n");

    return 0;
}