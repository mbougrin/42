/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 19:08:01 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/27 06:33:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNC_H
# define FT_FUNC_H

static const t_tab	g_func[16] =
{
	{"\033[A", &ft_up},
	{"\033[B", &ft_down},
	{"\033[C", &ft_right},
	{"\033[D", &ft_left},
	{"V", &ft_shift_v},
	{"C", &ft_shift_c},
	{"\x12", &ft_ctrl_r},
	{"\t", &ft_tab},
	{"\033[H", &ft_home},
	{"\033[F", &ft_end},
	{"\033[1;2D", &ft_shift_l},
	{"\033[1;2C", &ft_shift_r},
	{"\177", &ft_del},
	{"\n", &ft_ret},
	{"\004", &ft_ctrl_d},
	{NULL, NULL}
};

#endif
