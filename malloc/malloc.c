#include <malloc.h>

t_lst		*g_lst;

void		*malloc(size_t size)
{
	void	*addr;

	addr = NULL;
	if (size == 0)
		return (NULL);
	//size = (size - 1) / 4 * 4 + 4;	
	if (g_lst != NULL)
		addr = findunused(size);
	if (addr != NULL)
		return (addr);
	addr = sbrk(size);
	if (addr == (void*)-1)
	{
		printf("sbrk error\n");
		return (NULL);
	}
	lstadd(size, addr);
	return (addr);
}

void		*findunused(size_t size)
{
	t_lst	*read;

	read = g_lst;
	while (read != NULL)
	{
		if (read->used == UNUSED && size <= read->size)
			return (read->addr);
		read = read->next;
	}
	return (NULL);
}
