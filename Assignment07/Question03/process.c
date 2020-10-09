#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    printf("Main process is running with PID : %d\n",getpid());
    printf("Parent of main process is : %d\n", getppid());

    printf("-----------------\n");
    execl("./process1",NULL,NULL);
}
