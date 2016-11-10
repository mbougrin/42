/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:58:20 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 23:38:28 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				resetterm(void)
{
	t_opt				*opt;

	opt = singleton(NULL);
	ioctl(0, TIOCSETA, &opt->term);
}

void				initterm(void)
{
	t_opt				*opt;
	struct termios		s;

	opt = singleton(NULL);
	ioctl(0, TIOCGETA, &s);
	opt->term = s;
	s.c_lflag &= ~(ICANON | ECHO | ISIG);
	s.c_iflag &= ~(IXON | INLCR | IGNCR | ICRNL);
	s.c_cc[VMIN] = 1;
	s.c_cc[VTIME] = 0;
	ioctl(0, TIOCSETA, &s);
	opt->initterm = true;
}
