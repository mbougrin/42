/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 16:42:06 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/09 16:13:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_ls_perm(char *str)
{
	int				i;
	int				result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '/')
			result++;
		i++;
	}
	ft_putstr_fd("ft_ls: ", 2);
	if (result == 1 && str[0] == '/')
		ft_putstr_fd(&str[1], 2);
	else
		ft_putstr_fd(str, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void				ft_ls_not_found(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void				ft_print_single_l(t_stc stc)
{
	t_passwd		*user;
	t_group			*group;

	user = getpwuid(stc.stt.st_uid);
	group = getgrgid(stc.stt.st_gid);
	ft_putstr("  ");
	ft_putnbr(stc.stt.st_nlink);
	ft_putchar(' ');
	if (user != NULL)
		ft_putstr(user->pw_name);
	else
		ft_putnbr(stc.stt.st_uid);
	ft_putstr("  ");
	if (group != NULL)
		ft_putstr(group->gr_name);
	else
		ft_putnbr(stc.stt.st_gid);
	ft_putstr("  ");
	ft_putnbr(stc.stt.st_size);
	ft_putchar(' ');
}

void				ft_print_single(char *str, t_flags *flg)
{
	t_stc			stc;
	char			*prot;
	char			*time;

	if (flg->l == 0)
		ft_putendl(str);
	else
	{
		if (stat(str, &stc.stt) == -1)
			lstat(str, &stc.stt);
		prot = ft_prot(stc.stt);
		time = ft_strdup(ctime(&stc.stt.st_mtime));
		ft_putstr(prot);
		ft_print_single_l(stc);
		ft_print_l_time(time, stc.stt.st_mtime);
		ft_putchar(' ');
		if (prot[0] == 'l')
			ft_print_link(str, NULL);
		else
			ft_putendl(str);
		ft_strdel(&time);
		ft_strdel(&prot);
	}
}

int					ft_ls_error(char *str, t_flags *flg)
{
	t_stc		stc;

	if ((stc.dir = opendir(str)) == NULL)
	{
		if (stat(str, &stc.stt) == -1 && lstat(str, &stc.stt) == -1)
			ft_ls_not_found(str);
		else if (stc.stt.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO) \
				&& (!S_ISDIR(stc.stt.st_mode)))
			ft_print_single(str, flg);
		else
			ft_ls_perm(str);
		return (-1);
	}
	closedir(stc.dir);
	if (stat(str, &stc.stt) != -1 && S_ISDIR(stc.stt.st_mode) \
			&& stc.stt.st_nlink == 2)
	{
		if (stc.stt.st_nlink == 2 && flg->gr == 1)
			return (1);
		else
			return (-1);
	}
	return (1);
}
