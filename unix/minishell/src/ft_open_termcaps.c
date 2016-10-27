/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_termcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 09:33:10 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/09 11:27:13 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_open_termcaps(struct termios term)
{
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0, 0, &term);
}

void			ft_end_termcaps(struct termios term)
{
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &term);
}
