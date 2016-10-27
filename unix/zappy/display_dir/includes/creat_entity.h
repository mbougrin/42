/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 02:24:19 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 02:24:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREAT_ENTITY_H
# define CREAT_ENTITY_H

unsigned int	ft_listlen(t_entity **e);
t_entity		**ft_creat_entity(t_display *d, char *n, char **spt);

#endif
