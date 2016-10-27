/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 22:19:23 by mblet             #+#    #+#             */
/*   Updated: 2014/06/03 22:24:14 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_state_to_int(char state)
{
	if (state == 's')
		return (4);
	else if (state == 'b')
		return (5);
	else if (state == 'r')
		return (7);
	else
		return (0);
}

static int	ft_type_to_int(char type)
{
	if (type == 'b')
		return (48);
	else
		return (38);
}

char		*ft_strcolor(char *s, char type, char state, int color)
{
	char	*ic;
	char	*is;
	char	*it;
	char	*result;
	char	*result_tmp;

	result_tmp = NULL;
	if (!s)
		return (NULL);
	ic = ft_itoa(color);
	is = ft_itoa(ft_state_to_int(state));
	it = ft_itoa(ft_type_to_int(type));
	result = ft_strijoin("\033[", it, ";5;", ic, "m", s, "\033[0m", NULL);
	if (ft_state_to_int(state))
		result_tmp = ft_strijoin("\033[", is, "m", result, NULL);
	ft_stridel(&ic, &is, &it, NULL);
	if (result_tmp)
	{
		ft_strdel(&result);
		return (result_tmp);
	}
	return (result);
}
