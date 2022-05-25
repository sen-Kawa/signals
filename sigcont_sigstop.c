#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	pid;
	int	t;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			printf("hello\n");
			usleep(50000);
		}
	}
	else
	{
		kill(pid, SIGSTOP);
		do
		{
			printf ("Time in seconds for execution: ");
			scanf ("%d", &t);
			if (t > 0)
			{
				kill(pid, SIGCONT);
				sleep(t);
				kill(pid, SIGSTOP);
			}
		} while (t > 0);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
