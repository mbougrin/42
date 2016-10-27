/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 07:41:04 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:44:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int		ft_shift_v(t_shell *sh)
{
	(void)sh;
	ft_putstr("shift v");
	return (0);
}

int		ft_shift_c(t_shell *sh)
{
	(void)sh;
	ft_putstr("shft c");
	return (0);
}

int		ft_ctrl_r(t_shell *sh)
{
	(void)sh;
	ft_putstr("ctrl r");
	return (0);
}

int		ft_tab(t_shell *sh)
{
	(void)sh;
	ft_putstr("tab");
	return (0);
}

int		ft_ctrl_d(t_shell *sh)
{
	(void)sh;
	ft_putstr("ctrl d");
	return (0);
}
