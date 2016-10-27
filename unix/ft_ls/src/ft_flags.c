/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:55:31 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/08 15:15:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void		ft_flags_error(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ft_ls [-Ralrt] [file ...]", 2);
	exit(0);
}

static t_flags	*ft_init_flags_default(void)
{
	t_flags		*flg;

	flg = (t_flags *)malloc(sizeof(t_flags));
	flg->a = 0;
	flg->t = 0;
	flg->r = 0;
	flg->l = 0;
	flg->gr = 0;
	return (flg);
}

static void		ft_check_flags(char *str, t_flags *flg, int i)
{
	if (str[i] == 'a')
		flg->a = 1;
	else if (str[i] == 't')
		flg->t = 1;
	else if (str[i] == 'r')
		flg->r = 1;
	else if (str[i] == 'l')
		flg->l = 1;
	else if (str[i] == 'R')
		flg->gr = 1;
	else if (str[i] != '1')
		ft_flags_error(str[i]);
}

static t_flags	*ft_init_flags(char *str)
{
	t_flags		*flg;
	int			i;
	static int	count;

	i = 1;
	if (count == 0)
		flg = ft_init_flags_default();
	count++;
	if (str == NULL)
		return (flg);
	while (str[i])
	{
		ft_check_flags(str, flg, i);
		i++;
	}
	return (flg);
}

t_flags			*ft_flags(char *str)
{
	static	t_flags		*flg;

	if (str == NULL)
		flg = ft_init_flags(NULL);
	else if (str[0] == '-')
		flg = ft_init_flags(str);
	else if (ft_strcmp(str, "ret") == 0)
		return (flg);
	return (flg);
}
