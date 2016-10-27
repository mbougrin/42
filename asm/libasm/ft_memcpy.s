# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/26 14:08:55 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/26 14:42:41 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_memcpy

section .text

_ft_memcpy:
push	rdi
mov		rcx, rdx
cld
rep		movsb
pop		rax
ret
