#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    printf("Process1 is running with PID : %d\n",getpid());
    printf("Parent of Process1 is : %d\n", getppid());

    printf("-----------------\n");
    execl("./process2",NULL,NULL);
}
