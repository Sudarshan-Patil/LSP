#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int child1 = 0, child2 = 0;
    
    child1 = vfork();    
    
    if(child1 == 0)    // Child1 process is running
    {
        execl("./countChar", "hello.txt", NULL);
    }
    else                // Parent process is running
    {        
        child2 = vfork();    

        if(child2 == 0)    // Child2 process is running
        {
            execl("./countChar", "demo.txt", NULL);
        }
    }
    
    exit(0);
}
