/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 20:06:41 by mblet             #+#    #+#             */
/*   Updated: 2014/06/17 17:38:29 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int			main(int argc, char **argv)
{
	extern char		**environ;

	if (environ[0] == NULL)
		return (-1);
	ft_display(argc, argv);
	return (0);
}
