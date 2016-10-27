/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_func.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 18:32:10 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 18:32:10 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CMD_FUNC_H
# define READ_CMD_FUNC_H

int		ft_read_cmd_seg(t_display *d, char **spt);
int		ft_read_cmd_sgt(t_display *d, char **spt);
int		ft_read_cmd_bct(t_display *d, char **spt);
int		ft_read_cmd_ppos(t_display *d, char **spt);

#endif
