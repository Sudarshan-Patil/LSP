#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int child = 0;
    int status;
    pid_t pid;
    
    child = fork();    
    
    if(child == 0)    // child process is running
    {
        printf("child process is running with PID : %d\n",getpid());
        printf("Parent of child process is : %d\n", getppid());
        printf("child says : Value of ret is : %d\n",child);
        printf("-----------------\n");        
    }
    else                // Parent process is running
    {
        pid = wait(&status);
        printf("Parent process is running with PID : %d\n",getpid());
        printf("Parent of parent process is (Terminal) : %d\n",getppid());
        printf("Parent says : Value of ret is : %d\n",child);
        printf("-----------------\n");
    }
    
    exit(0);
}
