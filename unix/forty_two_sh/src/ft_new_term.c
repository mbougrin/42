/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 10:33:06 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/27 06:29:35 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void	ft_new_term(void)
{
	struct termios	term;
	char			buff[2048];
	char			*xterm;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	xterm = ft_strdup(getenv("TERM"));
	tgetent(buff, xterm);
	ft_strdel(&xterm);
}
