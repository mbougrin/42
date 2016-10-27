/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gener_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmesas <kmesas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:01:35 by kmesas            #+#    #+#             */
/*   Updated: 2015/05/03 21:54:57 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void		ft_init_color(t_map **map, int j, int i, int nb)
{
	if (nb == 0)
	{
		map[i][j].block = 1;
		map[i][j].co[0] = 0.0f;
		map[i][j].co[1] = 0.0f;
		map[i][j].co[2] = 1.0f;
	}
	else if (nb == 1)
	{
		map[i][j].block = 3;
		map[i][j].co[0] = 0.0f;
		map[i][j].co[1] = 1.0f;
		map[i][j].co[2] = 1.0f;
	}
	else if (nb == 2)
	{
		map[i][j].block = 4;
		map[i][j].co[0] = 1.0f;
		map[i][j].co[1] = 1.0f;
		map[i][j].co[2] = 1.0f;
	}
}

static void		init_map2(t_map ***map, int i, int *j, float (*nb)[4])
{
	int		c;
	char	*line;

	c = 0;
	get_next_line(g_fd, &line);
	while (*j < 11)
	{
		(*map)[i][*j].hl = (*nb)[2];
		(*map)[i][*j].hr = (*nb)[3];
		(*map)[i][*j].right = (*nb)[1];
		(*map)[i][*j].left = (*nb)[0];
		ft_init_color(*map, *j, i, ft_atoi(&line[c]));
		c += 2;
		(*nb)[0] += 0.2f;
		(*nb)[1] += 0.2f;
		(*j)++;
	}
}

t_map			**ft_init_map(t_map **map)
{
	int		i;
	int		j;
	float	nb[4];

	i = 0;
	nb[2] = 1.0f;
	nb[3] = 0.9f;
	while (i < 3)
	{
		j = 0;
		nb[0] = -1.0f;
		nb[1] = -0.8f;
		init_map2(&map, i, &j, &nb);
		nb[2] -= 0.1f;
		nb[3] -= 0.1f;
		i++;
	}
	return (map);
}

static void		gener_block2(t_vars_d *vars, t_vars_i *vars2, t_circle **crl)
{
	while (vars2->i <= vars2->lats)
	{
		vars->lat0 = M_PI * (-0.5 + (double)(vars2->i - 1) / vars2->lats);
		vars->z0 = sin(vars->lat0);
		vars->zr0 = cos(vars->lat0);
		vars->lat1 = M_PI * (-0.5 + (double)vars2->i / vars2->lats);
		vars->z1 = sin(vars->lat1);
		vars->zr1 = cos(vars->lat1);
		glBegin(GL_QUAD_STRIP);
		vars2->j = 0;
		while (vars2->j <= vars2->longs)
		{
			vars->lng = 2 * M_PI * (double)((vars2->j)++ - 1) / vars2->longs;
			vars->x = cos(vars->lng) / 40;
			vars->y = sin(vars->lng) / 40;
			glNormal3f(vars->x * vars->zr0, vars->y * vars->zr0, vars->z0);
			glVertex3f(vars->x * vars->zr0 - (*crl)->pos_v,
				vars->y * vars->zr0 - 0.88 + (*crl)->pos, vars->z0);
			glNormal3f(vars->x * vars->zr1, vars->y * vars->zr1, vars->z1);
			glVertex3f(vars->x * vars->zr1 - (*crl)->pos_v,
				vars->y * vars->zr1 - 0.88 + (*crl)->pos, vars->z1);
		}
		glEnd();
		(vars2->i)++;
	}
}

void			gener_block(t_stc *stc, t_circle *crl)
{
	t_vars_i	vars2;
	t_vars_d	vars;

	vars2.lats = 10;
	vars2.longs = 10;
	vars2.i = 0;
	gener_block2(&vars, &vars2, &crl);
	if (crl->pos <= 0.01 && crl->pos > 0 && stc->left <= (crl->pos_v * -1) &&
			stc->right >= (crl->pos_v * -1) && stc->start == 1)
	{
		if (stc->right == (crl->pos_v * -1))
			crl->move_v = 1;
		if (stc->left == (crl->pos_v * -1))
			crl->move_v = -1;
		crl->move_h = 0;
	}
}
