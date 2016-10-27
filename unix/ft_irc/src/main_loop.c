/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:16:19 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/23 17:16:38 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

void	main_loop(t_env *e)
{
	while (1)
	{
		init_fd(e);
		do_select(e);
		check_fd(e);
	}
}
