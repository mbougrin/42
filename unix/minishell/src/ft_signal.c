/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:07:05 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/12 13:14:24 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char		**ft_stock_envp(char **envp)
{
	static char		**tmp_envp;

	if (envp == NULL)
		return (tmp_envp);
	else
		tmp_envp = envp;
	return (tmp_envp);
}

void			ft_sig_handler(int sig)
{
	char	**envp;

	if (sig == SIGINT)
	{
		envp = ft_stock_envp(NULL);
		ft_putchar('\n');
		ft_prompt(envp);
		(void)sig;
		tputs(tgetstr("sc", NULL), 1, t_putchar);
	}
}

void			ft_signal(char **envp)
{
	if (envp != NULL)
		ft_stock_envp(envp);
	signal(SIGINT, ft_sig_handler);
}
