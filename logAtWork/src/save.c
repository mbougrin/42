/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 11:18:31 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/16 17:02:19 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

// load data into file into folder data today file

void			load(void)
{
	t_stc		*stc = singleton(NULL);
	int			fd;
	char		*path;
	char		**split;
	char		*line;

	path = ft_strjoin("./data/", stc->strDate);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	get_next_line(fd, &line);
	split = ft_strsplit(line, ' ');
	stc->workTime = ft_atoi(split[1]);
	ft_strstrdel(split);
	ft_strdel(&line);
	get_next_line(fd, &line);
	split = ft_strsplit(line, ' ');
	stc->breakTime = ft_atoi(split[1]);
	ft_strstrdel(split);
	ft_strdel(&line);
	close(fd);
}

// save data into file into folder data

void			save(void)
{
	t_stc		*stc = singleton(NULL);
	int			fd;
	char		*path;
	char		*time;
	char		*timeBreak;
	char		*tmp;
	
	path = ft_strjoin("./data/", stc->strDate);
	fd = open(path, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);
	if (fd == -1)
		exit(-1);
	tmp = ft_itoa(stc->workTime + (stc->clock / CLOCKS_PER_SEC));
	time = ft_strjoin("time: ", tmp); 
	ft_strdel(&tmp);
	tmp = ft_itoa(stc->notWorkTime + stc->breakTime);
	timeBreak = ft_strjoin("breakTime: ", tmp); 
	ft_strdel(&tmp);
	ft_putendl_fd(time, fd);
	ft_putendl_fd(timeBreak, fd);
	close(fd);
	ft_strdel(&path);
	ft_strdel(&timeBreak);
	ft_strdel(&time);
}
