/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 18:36:26 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/27 07:00:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

char				*ft_tab(int nb)
{
	if (nb == 0)
		return ("feed");
	if (nb == 1)
		return ("linemate");
	if (nb == 2)
		return ("deraumere");
	if (nb == 3)
		return ("sibur");
	if (nb == 4)
		return ("mendiane");
	if (nb == 5)
		return ("phiras");
	if (nb == 6)
		return ("thystame");
	return (NULL);
}

void				ft_drop_next(t_stc *stc)
{
	while (1)
	{
		if (stc->phiras > 0)
		{
			ft_laying(stc->sock, "phiras");
			stc->phiras--;
		}
		else if (stc->thystame > 0)
		{
			ft_laying(stc->sock, "thystame");
			stc->thystame--;
		}
		else if (stc->mendiane > 0)
		{
			ft_laying(stc->sock, "mendiane");
			stc->mendiane--;
		}
		else
			break ;
	}
}

void				ft_drop(t_stc *stc)
{
	while (1)
	{
		if (stc->linemate > 0)
		{
			ft_laying(stc->sock, "linemate");
			stc->linemate--;
		}
		else if (stc->deraumere > 0)
		{
			ft_laying(stc->sock, "deraumere");
			stc->deraumere--;
		}
		else if (stc->sibur > 0)
		{
			ft_laying(stc->sock, "sibur");
			stc->sibur--;
		}
		else
			break ;
	}
	ft_drop_next(stc);
}

void				ft_algo(int sock, t_stc *stc)
{
	static int	count;

	count++;
	ft_take(stc->sock, "food");
	if (count % 12 == 0)
		ft_right(stc->sock);
	else if (count % 5 == 0)
		ft_left(stc->sock);
	else
		ft_top(sock);
	ft_take(stc->sock, "food");
	ft_top(sock);
	ft_inventory(sock, stc);
	stc->find = ft_check_level_up(stc);
	if (stc->find != -2 && stc->find != -1 && stc->find != 0)
		ft_take(stc->sock, ft_tab(stc->find));
	if (stc->find == -1 && stc->feed > 25)
	{
		ft_drop(stc);
		ft_spell(sock, stc);
		stc->find = 0;
	}
	ft_take(stc->sock, "food");
}
