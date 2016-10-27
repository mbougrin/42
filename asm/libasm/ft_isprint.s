# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.asm                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 12:13:46 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/23 12:16:53 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isprint

section .text

_ft_isprint:
mov		rax, 1		; ret value
cmp		rdi, 0x20	; cmp  32 <
jl		_leave		; jump _leave
cmp		rdi, 0x7f	; cmp 127 >=
jge		_leave		; jump _leave
ret					; return

_leave:
mov		rax, 0		; ret value
ret					; return
