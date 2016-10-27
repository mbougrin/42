/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 20:13:40 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/26 20:19:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

int				ft_arg_error(void)
{
	ft_putstr_fd("too few arguments\n", 2);
	return (1);
}

int				ft_open_error(void)
{
	ft_putstr_fd("open error\n", 2);
	return (1);
}

int				ft_stat_error(void)
{
	ft_putstr_fd("size error\n", 2);
	return (1);
}

int				ft_mmap_error(void)
{
	ft_putstr_fd("mmap error", 2);
	return (1);
}

int				ft_munmap_error(void)
{
	ft_putstr_fd("munmap error\n", 2);
	return (1);
}
