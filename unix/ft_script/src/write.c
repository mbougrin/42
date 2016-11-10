/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:03:02 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 23:27:35 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				writeend(void)
{
	t_opt			*opt;
	struct timeval	tm;

	opt = singleton(NULL);
	if (gettimeofday(&tm, NULL) == -1)
		gettimeerror();
	if (opt->q == false)
	{
		ft_putstr("Script done, output file is ");
		ft_putendl(opt->filename);
	}
	ft_putstr_fd("\nScript done on ", opt->fd);
	ft_putstr_fd(ctime(&tm.tv_sec), opt->fd);
	close(opt->fd);
}

void				writebegin(void)
{
	int				fd;
	t_opt			*opt;
	struct timeval	tm;

	opt = singleton(NULL);
	if (gettimeofday(&tm, NULL) == -1)
		gettimeerror();
	if ((fd = open(opt->filename, O_RDWR | O_CREAT | O_TRUNC, \
					0644)) == -1)
		openerror();
	if (opt->q == false)
	{
		ft_putstr("Script started, output file is ");
		ft_putendl(opt->filename);
	}
	ft_putstr_fd("Script started on ", fd);
	ft_putstr_fd(ctime(&tm.tv_sec), fd);
	close(fd);
	if ((opt->fd = open(opt->filename, O_RDWR | O_CREAT | O_APPEND, \
					0644)) == -1)
		openerror();
}
