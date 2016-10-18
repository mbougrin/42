/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstInfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 11:05:52 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/16 18:08:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

const char *nameDayRet[] = {"Dimanche", "Lundi", "Mardi", \
									"Mercredi", "Jeudi", "Vendredi", \
																		"Samedi"};

const char *nameMonthRet[] = {"janvier", "fevrier", "mars" ,"avril", "mai", "juin", \
		                          	"juillet", "aout", "septembre", "octobre", "novembre", \
																		"decembre"};

static int		retMonth(char *str)
{
	int		i = 0;

	while (i < 12)
	{
		if (ft_strcmp(str, nameMonthRet[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int		retDay(char *str)
{
	int		i = 0;

	while (i < 7)
	{
		if (ft_strcmp(str, nameDayRet[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void		splitInfo(struct dirent *ret, t_lst *alst)
{
	int		fd = 0;
	char	path[256];
	char	*line;
	char	**split;

	ft_strcat(path, "./data/");
	ft_strcat(path, ret->d_name);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(0);
	alst->name = ft_strdup(ret->d_name);
	alst->splitInfo = ft_strsplit(ret->d_name, ' ');
	get_next_line(fd, &line);
	split = ft_strsplit(line, ' ');
	alst->timeWork = ft_atoi(split[1]);
	ft_strdel(&line);
	ft_strstrdel(split);
	get_next_line(fd, &line);
	split = ft_strsplit(line, ' ');
	alst->timeBreak = ft_atoi(split[1]);
	ft_strdel(&line);
	ft_strstrdel(split);
	alst->month = retMonth(alst->splitInfo[2]);
	alst->day = retDay(alst->splitInfo[0]);
	ft_strclr(path);
	close(fd);
}

static void		swapLst(t_lst *src, t_lst *dst)
{
	char		**split = NULL;
	int			i = 0;
	char		*str;
	
	split = src->splitInfo;
	src->splitInfo = dst->splitInfo;
	dst->splitInfo = split;
	i = src->timeWork;
	src->timeWork = dst->timeWork;
	dst->timeWork = i;
	i = src->timeBreak;
	src->timeBreak = dst->timeBreak;
	dst->timeBreak = i;
	i = src->month;
	src->month = dst->month;
	dst->month = i;
	i = src->day;
	src->day = dst->day;
	dst->day = i;
	str = src->name;
	src->name = dst->name;
	dst->name = str;
}

void			sortDay(t_lst **alst)
{
	t_lst	*tmp = *alst;
	t_lst	*check = NULL;

	while (tmp)
	{
		check = tmp;
		while (check)
		{
			if (ft_strcmp(tmp->splitInfo[1], check->splitInfo[1]) < 0\
					&& tmp->month <= check->month \
					&& ft_strcmp(tmp->splitInfo[3], check->splitInfo[3]) == 0)
				swapLst(tmp, check);
			check = check->next;
		}
		tmp = tmp->next;
	}

}

void			sortMonth(t_lst **alst)
{
	t_lst	*tmp = *alst;
	t_lst	*check = NULL;

	while (tmp)
	{
		check = tmp;
		while (check)
		{
			if (tmp->month < check->month && \
					ft_strcmp(tmp->splitInfo[3], check->splitInfo[3]) == 0)
				swapLst(tmp, check);
			check = check->next;
		}
		tmp = tmp->next;
	}

}

void			sortYear(t_lst **alst)
{
	t_lst	*tmp = *alst;
	t_lst	*check = NULL;

	while (tmp)
	{
		check = tmp;
		while (check)
		{
			if (ft_strcmp(tmp->splitInfo[3], check->splitInfo[3]) < 0)
				swapLst(tmp, check);
			check = check->next;
		}
		tmp = tmp->next;
	}
}

void			addInfoLst(t_lst	**alst)
{
	DIR				*dir;
	struct dirent	*ret;
	t_lst			*tmp;

	tmp = (*alst);
	dir = opendir("./data/");
	if (dir == NULL)
		exit(-1);
	while ((ret = readdir(dir)))
	{
		if (ret->d_name[0] != '.')
		{
			splitInfo(ret, tmp);
			tmp = tmp->next;
		}
	}
	closedir(dir);
}
