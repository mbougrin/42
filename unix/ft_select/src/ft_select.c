/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 20:31:17 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/18 09:22:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int					t_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int			ft_read(t_lst **alst, int i, int j)
{
	char		read_char[4];

	read(0, read_char, 3);
	if (read_char[0] == 27 && read_char[1] == 0 && read_char[2] == 0)
		return (-1);
	if (read_char[0] == 10 && read_char[1] == 0 && read_char[2] == 0)
		return (-3);
	if ((read_char[0] == 127 && read_char[1] == 0 && read_char[2] == 0) \
			|| (read_char[0] == 126 && read_char[1] == 0 && read_char[2] == 0))
	{
		i = ft_delete(&*alst);
		return (i);
	}
	if (read_char[0] == 32 && read_char[1] == 0 && read_char[2] == 0)
		i = ft_space(i, j, &*alst);
	if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 65)
		i = ft_up(&*alst, i, j);
	if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 66)
		i = ft_down(&*alst, i, j);
	read_char[0] = read_char[1] = read_char[2] = 0;
	return (i);
}

static int			ft_select_b(int i, t_lst **alst)
{
	if ((*alst)->next != NULL)
		i = ft_cursor_up(i, &*alst);
	else
	{
		ft_print_cursor(&*alst);
		tputs(tgetstr("up", NULL), 1, t_putchar);
	}
	return (i);
}

void				ft_select(t_lst *alst, int i)
{
	char				buffer[BUFFER_SIZE];
	struct termios		term;
	int					j;

	if (tgetent(buffer, getenv("TERM")) < 1)
		exit(-1);
	tcgetattr(0, &term);
	term.c_lflag &= ICANON;
	term.c_lflag &= ECHO;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, t_putchar);
	if (alst->next != NULL)
		j = i = ft_lst_print(&alst);
	i = ft_select_b(i, &alst);
	while (i >= 0)
		i = ft_read(&alst, i, j);
	tputs(tgetstr("te", NULL), 1, t_putchar);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	if (i == -2)
		ft_select(alst, 0);
	else if (i == -1)
		exit(-1);
	ft_print_select_return(&alst);
}

int					main(int ac, char **av)
{
	struct winsize		win;
	t_lst				*alst;
	int					i;

	i = 1;
	ioctl(0, TIOCGWINSZ, &win);
	if (ac == 1)
		ft_putendl_fd("too few arguments", 2);
	else
	{
		while (ac > i)
		{
			ft_lst_add_next(&alst, av[i]);
			i++;
		}
		if (i < win.ws_row)
			ft_select(alst, 0);
		else
			ft_putendl_fd("you have exceeded the max number of rows", 2);
	}
	return (0);
}
