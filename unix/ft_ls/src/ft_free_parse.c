/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:24:53 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/10 15:04:56 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_free_parse(char **tab, t_flags *flg, int res, int len)
{
	ft_loop_parse(tab, flg, res, len);
	free(flg);
	ft_strstrdel(tab);
}

void				ft_cpy_path(t_lst **lst, char *str, char *ptr)
{
	ft_strcpy((*lst)->lstc->path, str);
	free(ptr);
}

void				ft_print_ln(char *str)
{
	t_stc			stc;
	char			*prot;
	char			*time;

	if (lstat(str, &stc.stt) == -1)
		ft_putendl("lstat error");
	prot = ft_prot(stc.stt);
	time = ft_strdup(ctime(&stc.stt.st_mtime));
	ft_putstr(prot);
	ft_print_single_l(stc);
	ft_print_l_time(time, stc.stt.st_mtime);
	ft_putchar(' ');
	if (stc.stt.st_mode & S_IFLNK)
		ft_print_link(str, NULL);
	else
		ft_putendl(str);
	ft_strdel(&time);
	ft_strdel(&prot);
}

int					ft_check_ln(char *str, t_flags *flg)
{
	t_stat	stt;

	lstat(str, &stt);
	if (stt.st_mode & S_IFLNK && flg->l == 1)
	{
		ft_print_ln(str);
		return (-1);
	}
	return (0);
}
