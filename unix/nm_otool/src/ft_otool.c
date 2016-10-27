/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:07:09 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/27 21:42:20 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

t_stc_64		*ft_seg_64(char *segname, char *sectname, t_header *header, \
				unsigned int i)
{
	t_sc_64		*sc_64;
	t_stc_64	*s_64;

	sc_64 = (t_sc_64 *)((char *)header + sizeof(t_header));
	while (i < header->ncmds)
	{
		if (sc_64->cmd == LC_SEGMENT_64)
		{
			if (ft_strncmp(sc_64->segname, segname, sizeof(sc_64->segname)) \
					== 0 || header->filetype == MH_OBJECT)
			{
				s_64 = (t_stc_64 *)((char *)sc_64 + sizeof(t_sc_64));
				if (ft_seg64(sectname, segname, s_64, sc_64) != NULL)
					return (ft_seg64(sectname, segname, s_64, sc_64));
			}
		}
		sc_64 = (t_sc_64 *)((char *)sc_64 + sc_64->cmdsize);
		i++;
	}
	return ((t_stc_64 *)0);
}

t_stc_64		*ft_segment_64(char *ptr, char *segname, char *sectname)
{
	t_header		*header;

	header = (t_header *)ptr;
	return (ft_seg_64(segname, sectname, header, 0));
}

void			ft_print(t_stc_64 *ft_seg_64, char *ptr)
{
	unsigned int		i;
	unsigned int		size;

	i = 0;
	size = 16;
	while (i < ft_seg_64->size)
	{
		if (i == 0)
		{
			ft_print_addr((int)ft_seg_64->addr > 32, "0123456789abcdef");
			ft_print_addr((int)ft_seg_64->addr + i, "0123456789abcdef");
			ft_putchar(' ');
		}
		if (i == size)
		{
			size += 16;
			ft_putchar('\n');
			ft_print_addr((int)ft_seg_64->addr > 32, "0123456789abcdef");
			ft_print_addr((int)ft_seg_64->addr + i, "0123456789abcdef");
			ft_putchar(' ');
		}
		ft_print_hexa(ptr[(ft_seg_64->offset + i)]);
		ft_putchar(' ');
		i++;
	}
}

void			magic_number(char *ptr)
{
	unsigned int		magic_number;
	t_stc_64			*ft_seg_64;

	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
	{
		ft_seg_64 = ft_segment_64(ptr, "__TEXT", "__text");
		ft_print(ft_seg_64, ptr);
		ft_putchar('\n');
	}
}

int				main(int ac, char **av)
{
	char			*ptr;
	int				fd;
	t_stat			stat;
	int				i;

	i = 1;
	if (ac < 2)
		return (ft_arg_error());
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			return (ft_open_error());
		if ((fstat(fd, &stat)) < 0)
			return (ft_stat_error());
		if ((ptr = mmap(0, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) \
				== MAP_FAILED)
			return (ft_mmap_error());
		ft_putstr(av[i]);
		ft_putstr(":\n(__TEXT,__text) section\n");
		magic_number(ptr);
		i++;
	}
	if (munmap(ptr, stat.st_size) < 0)
		return (ft_munmap_error());
	return (0);
}
