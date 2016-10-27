/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmesas <kmesas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:04:58 by kmesas            #+#    #+#             */
/*   Updated: 2015/05/03 21:16:34 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void		key_callback2(int key, int action, t_stc **tmp, t_circle **crl)
{
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		if ((*tmp)->left <= -1.0f)
			return ;
		(*tmp)->left -= 0.1f;
		(*tmp)->right -= 0.1f;
		if ((*tmp)->start == 0)
			(*crl)->pos_v += 0.1f;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		if ((*tmp)->right == 1.0f)
			return ;
		(*tmp)->left += 0.1f;
		(*tmp)->right += 0.1f;
		if ((*tmp)->start == 0)
			(*crl)->pos_v -= 0.1f;
	}
}

void			key_callback(GLFWwindow *window, int key, int scancode,
					int action, int mods)
{
	t_stc		*tmp;
	t_circle	*crl;

	tmp = ft_stc(NULL);
	crl = ft_crl(NULL);
	scancode /= 1;
	mods /= 1;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	key_callback2(key, action, &tmp, &crl);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		tmp->start = 1;
}

static void		print_rect2(t_map ***map, int i, int j)
{
	if ((*map)[i][j].block > 0)
	{
		glColor3f((*map)[i][j].co[0], (*map)[i][j].co[1], (*map)[i][j].co[2]);
		glVertex3f((*map)[i][j].left, (*map)[i][j].hr, 0.f);
		glColor3f((*map)[i][j].co[0], (*map)[i][j].co[1], (*map)[i][j].co[2]);
		glVertex3f((*map)[i][j].right, (*map)[i][j].hr, 0.f);
		glColor3f((*map)[i][j].co[0], (*map)[i][j].co[1], (*map)[i][j].co[2]);
		glVertex3f((*map)[i][j].right, (*map)[i][j].hl, 0.f);
		glColor3f((*map)[i][j].co[0], (*map)[i][j].co[1], (*map)[i][j].co[2]);
		glVertex3f((*map)[i][j].left, (*map)[i][j].hl, 0.f);
	}
	else
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f((*map)[i][j].left, (*map)[i][j].hr, 0.f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f((*map)[i][j].right, (*map)[i][j].hr, 0.f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f((*map)[i][j].right, (*map)[i][j].hl, 0.f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f((*map)[i][j].left, (*map)[i][j].hl, 0.f);
	}
}

void			ft_print_rect(t_map **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 11)
		{
			glBegin(GL_QUADS);
			print_rect2(&map, i, j);
			glEnd();
			j++;
		}
		i++;
	}
}
