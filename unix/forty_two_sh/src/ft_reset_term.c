/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_term.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:00:11 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:47:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void	ft_reset_term(void)
{
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag |= (ECHO | ICANON);
	tcsetattr(0, TCSADRAIN, &term);
}
