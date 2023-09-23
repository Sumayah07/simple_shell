#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

int main(void)
{
	char line[MAX_LINE_LENGTH];
	char *args[MAX_ARGS];
	int status;

	do {
		printf("shell> ");
		fgets(line, MAX_LINE_LENGTH, stdin);

		int i = 0;
		args[i] = strtok(line, " \n");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " \n");
		}
		args[i] = NULL;

		if (strcmp(args[0], "cd") == 0)
		{
			chdir(args[1]);
			continue;
		}
		else if (strcmp(args[0], "exit") == 0)
		{
			exit(0);
		}

		pid_t pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror("execve failed");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	} while (1);

	return (0);
}
