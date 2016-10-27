/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:27:51 by mbougrin          #+#    #+#             */
/*   Updated: 2013/11/29 15:47:38 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_striter(char *s, void (*f)(char *))
{
	while (*s != '\0')
	{
		f(&*s);
		s++;
	}
}