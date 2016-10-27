/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:35:22 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/27 04:31:19 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_write_historic(t_list *hist)
{
	mode_t			mode;
	int				fd;
	t_list			*ptr;
	static int		i = 1;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd = open("hist.txt", O_WRONLY | O_CREAT | O_APPEND, mode);
	ptr = hist;
	ft_putstr_fd("Line ", fd);
	ft_putnbr_fd(i++, fd);
	ft_putstr_fd(": ", fd);
	ft_putendl_fd(ptr->str, fd);
	close(fd);
}

int				ft_ret(t_shell *sh)
{
	ft_putchar('\n');
	ft_list_push_back(&(sh->hist), sh->str);
	ft_reset_term();
	ft_forty_two_sh(sh->str);
	ft_new_term();
	free(sh->str);
	sh->str = ft_strdup("");
	while (sh->hist->next)
		sh->hist = sh->hist->next;
	ft_prompt();
	sh->pos = 0;
	tputs(tgetstr("sc", NULL), 1, ft_iputchar);
	ft_write_historic(sh->hist);
	return (0);
}
