/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 18:24:46 by mblet             #+#    #+#             */
/*   Updated: 2014/06/17 18:40:24 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *s)
{
	char	*tmp;

	tmp = ft_strijoin("error: ", s, ".", NULL);
	ft_putendl_fd(tmp, 2);
	ft_strdel(&tmp);
}
