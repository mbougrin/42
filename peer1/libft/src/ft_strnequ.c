/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:06:59 by mbougrin          #+#    #+#             */
/*   Updated: 2013/11/29 20:15:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strequ(char const *s1, char const *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	else
		return (1);
}
