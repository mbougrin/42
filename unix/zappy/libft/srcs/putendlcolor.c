/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendlcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 22:21:26 by mblet             #+#    #+#             */
/*   Updated: 2014/06/03 22:21:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendlcolor(char *s, char type, char state, int color)
{
	char	*tmp;

	tmp = ft_strcolor(s, type, state, color);
	ft_putendl(tmp);
	ft_strdel(&tmp);
}
