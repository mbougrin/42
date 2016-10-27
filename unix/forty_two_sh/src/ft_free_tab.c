/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 05:53:18 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:46:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void	ft_free_tab(char **split)
{
	unsigned int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			ft_strdel(&split[i++]);
		free(split);
		split = NULL;
	}
}
