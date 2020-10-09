#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    printf("Process2 is running with PID : %d\n",getpid());
    printf("Parent of Process2 is : %d\n", getppid());

    printf("-----------------\n");
    execl("./process3",NULL,NULL);
}
