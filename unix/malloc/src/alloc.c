/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 13:32:35 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/18 17:41:02 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

static void		*print_stc(t_stc stc[100])
{
	static size_t	len;
	int				i;

	i = 0;
	while (stc[i].use)
	{
		print_alloc_mem(stc[i].s);
		ft_putstr(" - ");
		print_alloc_mem(stc[i].s + stc[i].size);
		ft_putstr(" : ");
		ft_putnbr(stc[i].size);
		len += stc[i].size;
		ft_putstr(" octets\n");
		i++;
	}
	return ((void *)len);
}

void			*ft_len_stc(t_stc stc[], void *free)
{
	int		i;

	i = 0;
	while (stc[i].use)
	{
		if (free == stc[i].s)
			return ((void *)stc[i].size);
		i++;
	}
	return (0);
}

void			*alloc_tiny(char *s, size_t size, void *free)
{
	static t_stc	stc[100];
	static size_t	number;
	size_t			len_tiny;

	len_tiny = (getpagesize() * TINY) / 100;
	if (ft_strcmp(s, "add") == 0)
	{
		stc[number].size = size;
		stc[number].use = 1;
		if (number == 0)
			stc[number].s = alloc_mem("tiny");
		else
			stc[number].s = alloc_mem("tiny") + (len_tiny * number);
		number++;
		stc[number].number = number + 1;
		stc[number].use = 0;
		return (stc[number - 1].s);
	}
	else if (ft_strcmp(s, "print") == 0)
		return (print_stc(stc));
	else if (ft_strcmp(s, "len") == 0)
		return (ft_len_stc(stc, free));
	else if (ft_strcmp(s, "number") == 0)
		return ((void *)number);
	return (NULL);
}

void			*alloc_large(char *s, size_t size, void *free)
{
	static t_stc	stc[4096];
	static size_t	number;

	if (ft_strcmp(s, "add") == 0)
	{
		stc[number].size = size;
		stc[number].use = 1;
		if (number == 0)
			stc[number].s = mmap(alloc_mem("large"), size, \
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
		else
			stc[number].s = mmap((stc[number - 1].s + stc[number - 1].size), \
				size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
		stc[number].number = number + 1;
		number++;
		stc[0].len_mem += size;
		stc[number].use = 0;
		return (stc[number - 1].s);
	}
	else if (ft_strcmp(s, "print") == 0)
		return (print_stc(stc));
	else if (ft_strcmp(s, "len") == 0)
		return (ft_len_stc(stc, free));
	return (NULL);
}

void			*alloc_small(char *s, size_t size, void *free)
{
	static t_stc	stc[100];
	static size_t	number;
	size_t			len_small;

	len_small = (getpagesize() * SMALL) / 100;
	if (ft_strcmp(s, "add") == 0)
	{
		stc[number].size = size;
		stc[number].use = 1;
		if (number == 0)
			stc[number].s = alloc_mem("small");
		else
			stc[number].s = alloc_mem("small") + (len_small * number);
		stc[number].number = number + 1;
		number++;
		stc[number].use = 0;
		return (stc[number - 1].s);
	}
	else if (ft_strcmp(s, "print") == 0)
		return (print_stc(stc));
	else if (ft_strcmp(s, "len") == 0)
		return (ft_len_stc(stc, free));
	else if (ft_strcmp(s, "number") == 0)
		return ((void *)number);
	return (NULL);
}
