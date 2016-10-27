# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/26 23:01:48 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/27 09:44:33 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_cat

extern _write, _read

section	.bss

buff: resb 1024

section .text

_ft_cat:
mov		rdx, 1024
lea		rsi, [rel buff]
call	_read
cmp		rax, 0x0
jl		_leave
push	rdi
mov		rdi, 1
mov		rdx, rax
call	_write
pop		rdi
cmp		rax, 0x0
je		_leave
jmp		_ft_cat

_leave:
ret
