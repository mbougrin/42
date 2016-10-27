# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.asm                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 14:44:06 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/23 15:41:01 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strcat

section .text

_ft_strcat:
mov		rax, rdi			; mov rax <- dvi
jmp		_loop				; jump _loop

_loop:
cmp		[rdi], byte 0x0		; check \0
je		_loop_cpy			; jump _loop_cpy
inc		rdi					; incremente rdi
jmp		_loop				; jump _loop

_loop_cpy:
movsq						; copy rsi -> rdi
cmp		[rsi], byte 0x0		; check \0
je		_leave				; jump _leave
inc		rdi					; incremente rdi
inc		rsi					; increment rsi
jmp		_loop_cpy			; jump _loop_cpy

_leave:
ret							; return
