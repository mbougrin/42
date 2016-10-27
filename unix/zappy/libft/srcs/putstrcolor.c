/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 22:22:16 by mblet             #+#    #+#             */
/*   Updated: 2014/06/03 22:22:32 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrcolor(char *s, char type, char state, int color)
{
	char	*tmp;

	tmp = ft_strcolor(s, type, state, color);
	ft_putstr(tmp);
	ft_strdel(&tmp);
}
