/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 13:40:23 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/27 21:43:15 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

void				ft_print_sym(t_stc *stc, struct mach_header_64 *mh)
{
	int		i;
	int		nsyms;

	i = 0;
	nsyms = stc[0].nsyms;
	ft_sort(&stc, nsyms);
	while (i < nsyms)
	{
		if (!(stc[i].type & N_STAB))
		{
			if (stc[i].value != 0)
			{
				ft_print_addr(stc[i].value > 32, "0123456789abcdef");
				ft_print_addr(stc[i].value, "0123456789abcdef");
			}
			else
				ft_putstr("                ");
			ft_putchar(' ');
			ft_putchar(ft_sym_char(&stc[i], mh));
			ft_putchar(' ');
			ft_putstr(stc[i].name);
			ft_putchar('\n');
		}
		i++;
	}
}

void				ft_add_sym(int nsyms, int symoff, int stroff, char *ptr)
{
	int				i;
	char			*str;
	struct nlist_64	*elem;
	t_stc			*stc;

	elem = (void *)ptr + symoff;
	str = (void *)ptr + stroff;
	i = 0;
	stc = (t_stc *)malloc(sizeof(t_stc) * nsyms);
	while (i < nsyms)
	{
		stc[i].nsyms = nsyms;
		stc[i].name = str + elem[i].n_un.n_strx;
		stc[i].type = elem[i].n_type;
		stc[i].sect = elem[i].n_sect;
		stc[i].value = elem[i].n_value;
		i++;
	}
	ft_print_sym(stc, (struct mach_header_64 *)ptr);
}

void				ft_handle_64(char *ptr)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	i = 0;
	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			ft_add_sym(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}

void				ft_check_mh_magic(char *ptr)
{
	unsigned int			magic_number;

	ft_putstr(":\n");
	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
		ft_handle_64(ptr);
}

int					main(int ac, char **av)
{
	char			*ptr;
	int				fd;
	struct stat		size;
	int				i;

	i = 1;
	if (ac < 2)
		return (ft_arg_error());
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			return (ft_open_error());
		if ((fstat(fd, &size)) < 0)
			return (ft_stat_error());
		if ((ptr = mmap(0, size.st_size, PROT_READ, MAP_PRIVATE, \
					fd, 0)) == MAP_FAILED)
			return (ft_mmap_error());
		ft_putchar('\n');
		ft_putstr(av[i]);
		ft_check_mh_magic(ptr);
		i++;
	}
	if (munmap(ptr, size.st_size) < 0)
		return (ft_munmap_error());
	return (0);
}
