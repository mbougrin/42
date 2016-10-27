/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlistdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 15:44:52 by mblet             #+#    #+#             */
/*   Updated: 2014/03/04 18:34:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_strlistdel(char **l)
{
	size_t	i;

	i = ft_strlistlen(l);
	while (i > 0)
	{
		free(l[i - 1]);
		i--;
	}
	free(l);
}
