#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    printf("Process3 is running with PID : %d\n",getpid());
    printf("Parent of Process3 is : %d\n", getppid());

    printf("-----------------\n");    
}
