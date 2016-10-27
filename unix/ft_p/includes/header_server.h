/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_server.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 12:46:19 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/17 12:46:36 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_SERVER_H
# define HEADER_SERVER_H

# include "../libft/includes/libft.h"
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h>

int				ft_read(int cs);
void			ft_ls(int cs);
void			ft_pwd(int cs, char *s);

#endif
