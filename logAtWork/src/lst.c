/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 10:15:12 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/16 17:17:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static int		openDirLen(void)
{
	DIR				*dir;
	struct dirent	*ret;
	int				count = 0;

	dir = opendir("./data/");
	if (dir == NULL)
		exit(-1);
	while ((ret = readdir(dir)))
	{
		if (ret->d_name[0] != '.')
			count++;
	}
	closedir(dir);
	return (count);
}

static t_lst	*newLst(void)
{
	t_lst	*new = (t_lst *)malloc(sizeof(t_lst));

	new->next = NULL;
	new->name = NULL;
	new->day = 0;
	new->month = 0;
	new->timeWork = 0;
	new->timeBreak = 0;
	new->splitInfo = NULL;
	return (new);
}

static t_lst	*createLst(int len)
{
	t_lst	*alst = NULL;
	t_lst	*tmp = NULL;
	int		i = 0;

	while (i < len)
	{
		if (alst == NULL)
		{
			alst = newLst();
			tmp = alst;
		}
		else
		{
			tmp->next = newLst();
			tmp = tmp->next;
		}
		i++;
	}
	return (alst);	
}
/*
static void		printLst(t_lst *alst)
{
	while (alst != NULL)
	{
		ft_putstr(alst->splitInfo[0]);
		ft_putchar(' ');
		ft_putstr(alst->splitInfo[1]);
		ft_putchar(' ');
		ft_putstr(alst->splitInfo[2]);
		ft_putchar(' ');
		ft_putstr(alst->splitInfo[3]);
		ft_putchar(' ');
		ft_putnbr(alst->timeWork);
		ft_putchar(' ');
		ft_putnbr(alst->timeBreak);
		ft_putchar('\n');
		alst = alst->next;
	}
}
*/
void			initList(void)
{
	t_stc	*stc = singleton(NULL);
	int		lstLen = openDirLen();
	t_lst	*alst = createLst(lstLen);

	addInfoLst(&alst);
	sortYear(&alst);
	sortMonth(&alst);
	sortDay(&alst);
	stc->lst = alst;
}
