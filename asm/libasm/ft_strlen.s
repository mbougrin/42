# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.asm                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 16:27:20 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/26 13:40:38 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	_ft_strlen

section .text

_ft_strlen:
mov		rax, 0
mov		rcx, -1
cld
repnz	scasb
not		rcx
lea 	rax, [rcx - 1]
ret
