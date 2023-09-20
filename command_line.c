#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_process_id;

	my_process_id = getpid();
	printf("%u\n", my_pid);
	return (0);
}
