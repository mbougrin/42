/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 13:18:02 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/18 16:41:07 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void			print_hexa(int n, char *base)
{
	if (n < 16)
	{
		ft_putchar(base[n]);
		return ;
	}
	else
	{
		print_hexa(n / 16, base);
		ft_putchar(base[(n % 16)]);
	}
}

void			print_alloc_mem(void *ptr)
{
	int		nb;

	nb = *((int *)&ptr);
	ft_putstr("0x");
	print_hexa(nb, "0123456789ABCDEF");
}

void			*alloc_mem(char *s)
{
	static void		*tiny;
	static void		*small;
	static void		*large;

	if (ft_strcmp(s, "add") == 0)
	{
		tiny = mmap(0, ((getpagesize() * TINY)), PROT_READ | PROT_WRITE, \
				MAP_ANON | MAP_SHARED, -1, 0);
		small = mmap(tiny + (getpagesize() * TINY), ((getpagesize() * \
				SMALL)), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		large = small + ((getpagesize() * SMALL) + 1);
	}
	if (ft_strcmp(s, "tiny") == 0)
		return (tiny);
	else if (ft_strcmp(s, "small") == 0)
		return (small);
	else if (ft_strcmp(s, "large") == 0)
		return (large);
	return (NULL);
}

void			show_alloc_mem(void)
{
	size_t	len;

	ft_putstr("TINY : ");
	print_alloc_mem(alloc_mem("tiny"));
	ft_putchar('\n');
	alloc_tiny("print", 0, NULL);
	ft_putstr("SMALL : ");
	print_alloc_mem(alloc_mem("small"));
	ft_putchar('\n');
	alloc_small("print", 0, NULL);
	ft_putstr("LARGE : ");
	print_alloc_mem(alloc_mem("large"));
	ft_putchar('\n');
	len = (size_t)alloc_large("print", 0, NULL);
	ft_putstr("Total : ");
	ft_putnbr(len);
	ft_putstr(" octets\n");
}
