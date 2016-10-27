/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmesas <kmesas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 07:32:13 by mbougrin          #+#    #+#             */
/*   Updated: 2015/05/03 21:58:14 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void		init_ogl(GLFWwindow **window, t_stc **stc, t_circle **crl,
				t_map ***map)
{
	srand(time(NULL));
	if (!glfwInit())
		exit(EXIT_FAILURE);
	*window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);
	if (!(*window))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	*stc = (t_stc *)malloc(sizeof(t_stc));
	*crl = (t_circle *)malloc(sizeof(t_circle));
	(*stc)->left = -0.1f;
	(*stc)->right = 0.1f;
	(*stc)->start = 0;
	(*crl)->pos = 0;
	(*crl)->pos_v = 0;
	(*crl)->move_h = 0;
	(*crl)->move_v = 0;
	ft_stc(*stc);
	ft_crl(*crl);
	*map = (t_map **)malloc(sizeof(t_map*) * 4);
	(*map)[0] = (t_map*)malloc(sizeof(t_map) * 11);
	(*map)[1] = (t_map*)malloc(sizeof(t_map) * 11);
	(*map)[2] = (t_map*)malloc(sizeof(t_map) * 11);
}

static void		laod_window(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void			loop_window(t_stc *stc, t_circle *crl)
{
	if (stc->start == 1)
	{
		if (crl->pos > 1.82f)
			crl->move_h = 1;
		if (crl->pos_v <= -1.0f)
			crl->move_v = -1;
		else if (crl->pos_v >= 1.0f)
			crl->move_v = 1;
		if (crl->move_h == 0)
			crl->pos += 0.01f;
		else
			crl->pos -= 0.01f;
		if (crl->move_v == 1)
			crl->pos_v -= 0.01f;
		else if (crl->move_v == -1)
			crl->pos_v += 0.01f;
	}
	laod_window();
	gener_block(&(*stc), &(*crl));
}

static void		call_gl(GLFWwindow **window, t_stc *stc)
{
	glBegin(GL_QUADS);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(stc->left, -0.9f, 0.f);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(stc->right, -0.9f, 0.f);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(stc->right, -1.0f, 0.f);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(stc->left, -1.0f, 0.f);
	glEnd();
	glfwSwapBuffers(*window);
	glfwSetKeyCallback(*window, key_callback);
	glfwPollEvents();
}

int				main(int ac, char **av)
{
	GLFWwindow		*window;
	t_stc			*stc;
	t_circle		*crl;
	t_map			**map;

	g_fd = open(av[1], O_RDONLY);
	if (ac == 1 || g_fd == -1)
		return (0);
	init_ogl(&window, &stc, &crl, &map);
	map = ft_init_map(map);
	while (!glfwWindowShouldClose(window))
	{
		loop_window(&(*stc), &(*crl));
		ft_check_col(map, crl);
		ft_print_rect(map);
		call_gl(&window, &(*stc));
		if (crl->pos < -0.5)
			break ;
	}
	free(stc);
	free(crl);
	free(map);
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
