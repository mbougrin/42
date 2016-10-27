/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 11:56:41 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/10 15:04:35 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_create_l_next(t_stc stc, t_lst **lst, char *str)
{
	t_passwd		*user;
	t_group			*group;

	user = getpwuid(stc.stt.st_uid);
	group = getgrgid(stc.stt.st_gid);
	if (user != NULL)
		(*lst)->lstc->user = ft_strdup(user->pw_name);
	else
		(*lst)->lstc->user = ft_itoa(stc.stt.st_uid);
	if (group != NULL)
		(*lst)->lstc->group = ft_strdup(group->gr_name);
	else
		(*lst)->lstc->group = ft_itoa(stc.stt.st_gid);
	(*lst)->lstc->block = stc.stt.st_blocks;
	(*lst)->lstc->uid = stc.stt.st_uid;
	(*lst)->lstc->gid = stc.stt.st_gid;
	(*lst)->lstc->nb_link = stc.stt.st_nlink;
	ft_strcpy((*lst)->lstc->path, str);
}

int					ft_create_l(t_lst **lst, t_flags *flg, \
		struct dirent *dirent, char *str)
{
	t_stc			stc;
	char			*ptr;

	if (flg->a == 1 || (flg->a == 0 && dirent->d_name[0] != '.'))
	{
		ptr = ft_strstrjoin(3, str, "/", dirent->d_name);
		if (lstat(ptr, &stc.stt) == -1 && stat(ptr, &stc.stt) == -1)
			ft_putendl("error stat");
		ft_create_l_next(stc, lst, str);
		if (!ctime(&stc.stt.st_mtime))
			(*lst)->lstc->time = ft_strdup("Jan  1  10000");
		else
			(*lst)->lstc->time = ft_strdup(ctime(&stc.stt.st_mtime));
		if (stc.stt.st_mtime > 1595435455)
			(*lst)->lstc->itime = stc.stt.st_mtime * -1;
		else
			(*lst)->lstc->itime = stc.stt.st_mtime;
		(*lst)->lstc->size = stc.stt.st_size;
		(*lst)->lstc->name = ft_strdup(dirent->d_name);
		(*lst)->lstc->prot = ft_prot(stc.stt);
		(*lst)->lstc->mode = stc.stt.st_mode;
		ft_cpy_path(lst, str, ptr);
		return (0);
	}
	return (-1);
}

int					ft_create_lst_add(t_lst **lst, t_flags *flg, \
		struct dirent *dirent, char *str)
{
	t_stc	stc;
	char	*ptr;

	if (flg->l == 1)
		return (ft_create_l(lst, flg, dirent, str));
	else if (flg->a == 1 || (flg->a == 0 && dirent->d_name[0] != '.'))
	{
		ptr = ft_strstrjoin(3, str, "/", dirent->d_name);
		if (lstat(ptr, &stc.stt) == -1 && stat(ptr, &stc.stt) == -1)
			ft_putendl("error stat");
		if (!ctime(&stc.stt.st_mtime))
			(*lst)->lstc->time = ft_strdup("Jan  1  10000");
		else
			(*lst)->lstc->time = ft_strdup(ctime(&stc.stt.st_mtime));
		if (stc.stt.st_mtime > 1595435455)
			(*lst)->lstc->itime = stc.stt.st_mtime * -1;
		else
			(*lst)->lstc->itime = stc.stt.st_mtime;
		(*lst)->lstc->name = ft_strdup(dirent->d_name);
		(*lst)->lstc->mode = stc.stt.st_mode;
		free(ptr);
		return (0);
	}
	return (-1);
}

void				ft_create_lst_next(t_lst **lst)
{
	t_lst		*tmp;

	(*lst)->next = ft_lst_add();
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = tmp;
}

t_lst				*ft_create_lst(char *str, t_flags *flg)
{
	t_stc		stc;
	t_lst		*lst;
	t_lst		*new;

	lst = NULL;
	new = NULL;
	if ((stc.dir = opendir(str)) == NULL)
		return (NULL);
	while ((stc.dirent = readdir(stc.dir)))
	{
		if ((flg->a == 1 || ft_check_point(stc.dirent->d_name) == -1))
		{
			if (lst == NULL)
			{
				lst = ft_lst_add();
				new = lst;
			}
			else if (stc.ret != -1)
				ft_create_lst_next(&lst);
			stc.ret = ft_create_lst_add(&lst, flg, stc.dirent, str);
		}
	}
	closedir(stc.dir);
	return (ft_return_lst(new, lst, flg));
}
