#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int child1 = 0, child2 = 0;
    
    child1 = fork();    
    
    if(child1 == 0)    // Child1 process is running
    {
        printf("Child1 process is running with PID : %d\n",getpid());
        printf("Parent of child1 process is : %d\n", getppid());
        printf("Child1 says : Value of ret is : %d\n",child1);
        printf("-----------------\n");
        child2 = fork();    

        if(child2 == 0)    // Child2 process is running
        {
            printf("Child2 process is running with PID : %d\n",getpid());
            printf("Parent of child2 process is : %d\n", getppid());
            printf("Child2 says : Value of ret is : %d\n",child2);
            printf("-----------------\n");

        }
        else                // child1 process is running
        {
            printf("Parent of child2 process is running with PID : %d\n",getpid());
            printf("Parent of parent of child2 process is (Terminal) : %d\n",getppid());
            printf("Parent of child2 says : Value of ret is : %d\n",child2);
            printf("-----------------\n");
        }


    }
    else                // Parent process is running
    {
        printf("Parent process is running with PID : %d\n",getpid());
        printf("Parent of parent process is (Terminal) : %d\n",getppid());
        printf("Parent says : Value of ret is : %d\n",child1);
        printf("-----------------\n");
    }
    
    exit(0);
}
