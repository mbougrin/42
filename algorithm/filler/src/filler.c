/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:03:18 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/26 09:51:26 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				ft_check_valid(char c, char b)
{
	int		i;

	i = 0;
	if (c == '*')
		i++;
	if (b >= 65 && b <= 90)
		i++;
	if (b >= 97 && b <= 122)
		i++;
	return (i);
}

static void		ft_filler(t_filler *stc)
{
	int		i;

	i = 0;
	stc->ok = 1;
	while (stc->ok == 1)
	{
		ft_strdel(&stc->line);
		get_next_line(0, &stc->line);
		ft_creat_map(stc);
		ft_creat_coor(stc);
		ft_creat_piece(stc);
		ft_player(stc);
		if (i % 2 == 0)
			ft_check_coor_first(stc);
		else
			ft_check_coor_end(stc);
		i++;
		ft_play(stc);
		ft_strdel(&stc->line);
		ft_strstrdel(stc->map);
		ft_strstrdel(stc->piece);
		stc->ok = get_next_line(0, &stc->line);
	}
}

int				main(void)
{
	t_filler	*stc;

	stc = (t_filler *)malloc(sizeof(t_filler));
	get_next_line(0, &stc->line);
	if (ft_strstr(stc->line, "p1") != NULL)
		stc->player = 1;
	else if (ft_strstr(stc->line, "p2") != NULL)
		stc->player = 2;
	ft_strdel(&stc->line);
	get_next_line(0, &stc->line);
	stc->split = ft_strsplit(stc->line, ' ');
	stc->y_map = ft_atoi(stc->split[1]);
	stc->x_map = ft_atoi(stc->split[2]);
	ft_strstrdel(stc->split);
	ft_filler(stc);
	free(stc);
	return (0);
}
