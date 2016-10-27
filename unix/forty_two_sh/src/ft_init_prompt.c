/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 12:46:20 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/27 07:47:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void	ft_init_prompt(t_shell *sh)
{
	sh->hist = NULL;
	ft_list_push_back(&(sh->hist), "");
	sh->str = ft_strdup("");
	sh->pos = 0;
	ft_prompt();
	tputs(tgetstr("sc", NULL), 1, ft_iputchar);
	while (42)
	{
		ft_signal();
		ft_bzero(sh->buff, 10);
		read(0, sh->buff, 10);
		if (sh->buff[0] == 4)
			ft_exit(0, NULL);
		if (ft_key(sh) == 0)
			ft_add_char(sh);
		tputs(tgetstr("rc", NULL), 1, ft_iputchar);
		tputs(tgetstr("cd", NULL), 1, ft_iputchar);
		ft_putstr(sh->str);
		ft_repos_cursor(sh);
	}
}
