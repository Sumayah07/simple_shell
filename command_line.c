#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10
/**
 * main - UNIX command line interpreter.
 * You have to handle the “end of file” condition (Ctrl+D)
 * The prompt is displayed again each time a command has been executed.
 * execve will be the core part of your Shell
 *
 * Return: Always 0
 */
int main(void)
{
	char line[MAX_LINE_LENGTH];
	char *args[MAX_ARGS];
	int status;
	int i;

	do {
		printf("shell> ");
		fgets(line, MAX_LINE_LENGTH, stdin);

		i = 0;
		args[i] = strtok(line, " \n");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " \n");
		}
		args[i] = NULL;

		pid_t pid;

		pid = fork();
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
