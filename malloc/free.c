#include <malloc.h>

extern t_lst	*g_lst;

void		free(void *ptr)
{
	t_lst	*read;

	if (g_lst == NULL)
		return ;
	read = g_lst;
	while (read != NULL)
	{
		if (read->addr == ptr && read->used == USED)
		{
			read->used = UNUSED;
			bzero(read->addr, read->size);
			break ;
		}
		read = read->next;
	}
}
