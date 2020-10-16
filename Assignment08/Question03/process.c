#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int child = 0;
    
    child = vfork();    
    
    if(child == 0)    // Child1 process is running
    {
        execl("./file_open", "input", NULL);
    }
    
    exit(0);
}
