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
        execl("./file_open", NULL, NULL);
    }
    
    exit(0);
}
