#include <malloc.h>

extern t_lst   *g_lst;

void		printmalloc(void)
{
	t_lst *tmp;
	int	i;

	i = 0;
	tmp = g_lst;
	while (tmp != NULL)
	{
		printf("malloc nb %d addr %p size %zu used %d\n", \
			i, tmp->addr, tmp->size, tmp->used);
		tmp = tmp->next;
		i++;
	}
}

void		lstadd(size_t size, void *addr)
{
	t_lst	*tmp;
	t_lst	*read;

	tmp = sbrk(sizeof(*tmp));
	if (tmp == (void*)-1)
	{
		printf("sbrk error\n");
		return ;
	}
	tmp->size = size;
	tmp->addr = addr;
	tmp->used = USED;
	tmp->next = NULL;
	if (g_lst == NULL)
		g_lst = tmp;
	else
	{
		read = g_lst;
		while (read->next != NULL)
			read = read->next;
		if (read->next == NULL)
			read->next = tmp;
	}
}
