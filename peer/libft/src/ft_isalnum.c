/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:17:40 by mbougrin          #+#    #+#             */
/*   Updated: 2013/11/20 16:24:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_isalnum(int c)
{
	if (c > 122)
		return (0);
	else if (c < 97 && c > 90)
		return (0);
	else if (c < 65 && c > 57)
		return (0);
	else if (c < 48)
		return (0);
	else
		return (1);
}
