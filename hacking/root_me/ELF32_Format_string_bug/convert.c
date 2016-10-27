#include <stdio.h>

int decimal(char hex[])
{
	size_t	i = 0;
	int		dec = 0;
	int		temp = 0;

	while (hex[i] != '\0')
	{
		const int isHEXA = (hex[i] >= 'A') && (hex[i] <= 'F');
		const int ishexa = (hex[i] >= 'a') && (hex[i] <= 'f');
		const int isdigit = (hex[i] >= '0') && (hex[i] <= '9');
		if (ishexa)
			temp = hex[i] - 'a' + 10;
		else if (isHEXA)
			temp = hex[i] - 'A' + 10;
		else if (isdigit)
			temp = hex[i] - '0';
		dec = dec * 16 + temp;

		i++;
	}
	return (dec);
}

int			main(int ac, char **av)
{
	if (ac < 17)
	{
		printf("example ./a.out 39 61 70 44 28 29 36 64 6d 61 70 45 b7 00 0a 64\n")
		return (0);
	}
	char c = decimal(av[4]);
	printf("%c", c);
	c = decimal(av[3]);
	printf("%c", c);
	c = decimal(av[2]);
	printf("%c", c);
	c = decimal(av[1]);
	printf("%c", c);

	c = decimal(av[8]);
	printf("%c", c);
	c = decimal(av[7]);
	printf("%c", c);
	c = decimal(av[6]);
	printf("%c", c);
	c = decimal(av[5]);
	printf("%c", c);

	c = decimal(av[12]);
	printf("%c", c);
	c = decimal(av[11]);
	printf("%c", c);
	c = decimal(av[10]);
	printf("%c", c);
	c = decimal(av[9]);
	printf("%c", c);

	c = decimal(av[16]);
	printf("%c\n", c);
	return (0);
}
