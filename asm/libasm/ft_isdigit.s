# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.asm                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 19:51:44 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/22 20:10:28 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isdigit

section .text

_ft_isdigit:
mov		rax, 1			; ret value
cmp		rdi, 0x30		; cmp '0' <
jl		_leave			; jump leave
cmp		rdi, 0x3a		; cmp ':' >=
jge		_leave			; jump leave
ret						; return

_leave:
mov		rax, 0			; ret value
ret						; return
