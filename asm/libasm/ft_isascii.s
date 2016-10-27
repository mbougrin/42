# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.asm                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 11:59:43 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/23 12:04:44 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isascii

section .text

_ft_isascii:
mov		rax, 1		; ret value
cmp		rdi, 0x00 	; cmp 0 <
jl		_leave		; jump _leave
cmp		rdi, 0x80	; cmp >= 128
jge		_leave		; jump _leave
ret

_leave:
mov		rax, 0		; ret value
ret
