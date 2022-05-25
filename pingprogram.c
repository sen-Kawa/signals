#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int	main(int argc, char *argv[])
{
	int	pid;
	int	err;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	//child process
	{
		err = execlp("pings", "ping", "-c", "3", "archlinux.org", NULL);
		if (err == -1)
		{
			printf("Could not execute...\n");
			return (2);
		}
	}
	else
	//parent process
	{
		int	wstatus;

		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int	statuscode;
			
			statuscode = WEXITSTATUS(wstatus);
			if (statuscode == 0)
				printf("Success!\n");
			else
				printf("Failure!\n");
		}
	}
	return (0);
}
