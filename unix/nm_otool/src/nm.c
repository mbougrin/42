/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 20:53:28 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/27 21:23:35 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

char				ft_sect_symbol(t_s64 *section)
{
	if (!ft_strcmp(section->sectname, "__text"))
		return ('T');
	if (!ft_strcmp(section->sectname, "__data"))
		return ('D');
	if (!ft_strcmp(section->sectname, "__bss"))
		return ('B');
	return ('S');
}

t_s64				*ft_getsect(struct mach_header_64 *mh, uint32_t off, \
					uint32_t i)
{
	uint32_t		j;
	uint32_t		cnt;
	t_sc_64			*sg;
	t_s64			*sp;

	cnt = 0;
	sg = (t_sc_64 *)((char *)mh + sizeof(struct mach_header_64));
	while (i < mh->ncmds)
	{
		if (sg->cmd == LC_SEGMENT_64 && !(j = 0))
		{
			sp = (t_s64 *)((char *)sg + sizeof(t_sc_64));
			while (j < sg->nsects)
			{
				cnt++;
				if (cnt == off)
					return (sp);
				sp = (t_s64 *)((char *)sp + sizeof(t_s64));
				j++;
			}
		}
		sg = (t_sc_64 *)((char *)sg + sg->cmdsize);
		i++;
	}
	return (NULL);
}

char				ft_sym_char(t_stc *stc, struct mach_header_64 *mh)
{
	char	c;

	if ((stc->type & N_TYPE) == N_UNDF)
	{
		c = 'U';
		if (stc->value != 0)
			c = 'C';
	}
	else if ((stc->type & N_TYPE) == N_ABS)
		c = 'A';
	else if ((stc->type & N_TYPE) == N_SECT)
		c = ft_sect_symbol(ft_getsect(mh, stc->sect, 0));
	else if ((stc->type & N_TYPE) == N_INDR)
		c = 'I';
	else
		c = 'S';
	if (stc->type & N_EXT)
		return (c);
	return (c + 32);
}

void				ft_print_addr(int n, char *base)
{
	char			*addr;
	int				i;

	addr = ft_strdup("00000000\0");
	i = 7;
	while (1)
	{
		if (n < 16)
			break ;
		addr[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	addr[i] = base[n];
	ft_putstr(addr);
	ft_strdel(&addr);
}

void				ft_sort(t_stc **stc, int nsyms)
{
	t_stc	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nsyms)
	{
		j = i;
		while (j < nsyms)
		{
			if (ft_strcmp(stc[0][i].name, stc[0][j].name) > 0)
			{
				tmp = stc[0][i];
				stc[0][i] = stc[0][j];
				stc[0][j] = tmp;
			}
			j++;
		}
		i++;
	}
}
