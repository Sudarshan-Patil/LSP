#include<stdio.h>
#include<unistd.h>

int main()
{
int status;
pid_t pid;

	if(fork() == 0)
	{
		printf("Before process creation\n");
		execl("./process1","NULL",NULL);
	}
	else
	{
		printf("Inside Parent process\n");
		return 0;
	}

	return 0;
}

