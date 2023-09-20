#include <stdio.h>
#include <unistd.h>

/**
 * main - Interpreting the pid_t command line
 *
 * Return: Always 0.
 */
int main(void)
{
	int num = 27;

	pid_t my_process_id;

	my_process_id = getpid();

	printf("%d\n", num);
	printf("The child process id is %u", my_process_id);

	return (0);
}
