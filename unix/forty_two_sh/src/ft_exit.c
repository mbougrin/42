/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 04:05:36 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:46:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int		ft_term_exit(int nb)
{
	tputs(tgetstr("rc", NULL), 1, ft_iputchar);
	tputs(tgetstr("cd", NULL), 1, ft_iputchar);
	ft_putendl("42sh : Exiting");
	ft_reset_term();
	exit(nb);
	return (nb);
}
