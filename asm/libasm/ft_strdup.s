# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/26 14:48:11 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/26 23:20:20 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strdup

extern _malloc, _ft_strlen, _ft_memcpy

section .text

_ft_strdup:
push	rdi
call	_ft_strlen
mov		rdi, rax
push	rdi
call	_malloc
pop		rdx
pop		rsi
mov		rdi, rax
call	_ft_memcpy
ret
