#include <stdlib.h>
int main(int ac, char **av, char **env)
{
	env[0] = "PATH=/tmp/tmp1";
	env[1] = "PWD=/challenge/binary/binary2";
	env[2] = "SHLVL=1";
	env[3] = "HOME=/challenge/binary/binary2";
	env[4] = "LOGNAME=binary2";
	env[5] = "SSH_CONNECTION=62.210.34.47 61247 192.168.166.151 22";
	env[6] = "LC_CTYPE=UTF-8";
	env[7] = "_=/usr/bin/env";
	env[8] = "OLDPWD=/tmp/tmp1";
	env[10] = NULL;
	av[0] = "binary2";
	av[1] = NULL;
	execve("/challenge/binary/binary2/binary2", av, env);
	return 0;
}
