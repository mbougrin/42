/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool_64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 21:15:18 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/26 21:20:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

t_stc_64		*ft_seg64(char *sectname, char *segname, t_stc_64 *s_64, \
				t_sc_64 *sc_64)
{
	unsigned int		j;

	j = 0;
	while (j < sc_64->nsects)
	{
		if (ft_strncmp(s_64->sectname, sectname, \
		sizeof(s_64->sectname)) == 0 && ft_strncmp(s_64->segname, \
		segname, sizeof(s_64->segname)) == 0)
			return (s_64);
		j++;
	}
	return (NULL);
}
