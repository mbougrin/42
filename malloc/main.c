#include <malloc.h>
#include <string.h>
#include <stdio.h>

int		main(void)
{
	char	*ptr = (char *)malloc(sizeof(char) * 13);
	
	strcpy(ptr, "Hello World!");
	printf("%s\n", ptr);

	char	*ptr1 = (char *)malloc(sizeof(char) * 13);
	
	strcpy(ptr1, "Hello World!");
	printf("%s\n", ptr1);

	char	*ptr2 = (char *)malloc(sizeof(char) * 13);
	
	strcpy(ptr2, "Hello World!");
	printf("%s\n", ptr2);
	
	free(ptr);	

	realloc(ptr1, 26);	
	strcpy(ptr1, "Hello World! Hello World!");
	printf("%s\n", ptr1);

	printmalloc();
	return (0);
}
