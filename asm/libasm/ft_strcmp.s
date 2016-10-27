# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 00:42:49 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/27 09:24:54 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strcmp

section .text

_ft_strcmp:
xor		eax, eax
xor		ecx, ecx
xor		rdx, rdx
push	rsi
push	rdi

_loop:
mov		cl, [rsi]
mov		al, [rdi]
cmp		cl, 0x0
jz		_ret
cmp		al, 0x0
jz		_ret
sub		ax, cx
jne		_leave
inc		rdi
inc		rsi
jmp		_loop

_leave:
pop		rdi
pop		rsi
cwde
cdqe
ret

_ret:
pop		rdi
pop		rsi
ret
