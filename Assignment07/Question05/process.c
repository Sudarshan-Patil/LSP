#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
int status;
pid_t pid;

	if(fork() == 0)
	{
		printf("Before process creation pid: %d\n", getpid());
		execl("./process1","NULL",NULL);
	}
	else
	{
		printf("Inside Parent process\n");
        kill(pid,SIGKILL);        
	}

	return 0;
}

