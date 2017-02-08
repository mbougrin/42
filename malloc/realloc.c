#include <malloc.h>

extern t_lst 	*g_lst;

void		*realloc(void *ptr, size_t size)
{
	void	*addr;

	addr = NULL;
	if (ptr == NULL)
		return (malloc(size));
	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (ptr);
	}
	if (g_lst != NULL)
		addr = findunused(size);
	if (addr == NULL)
	{
		//size = (size - 1) / 4 * 4 + 4;
		addr = sbrk(size);
		if (addr == (void *)-1)
		{
			printf("sbrk error\n");
			return (NULL);
		}
		memcpy(addr, ptr, size);
		lstadd(size, addr);
		free(ptr);
		return (addr);
	}
	else
	{
		memcpy(addr, ptr, size);
		lstadd(size, addr);
		free(ptr);
		return (addr);
	}
	return (ptr);
}
