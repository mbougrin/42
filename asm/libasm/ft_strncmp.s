# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strncmp.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 03:34:23 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/27 09:49:06 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strncmp

section .text

_ft_strncmp:
mov		rbx, rdx
xor		eax, eax
xor		ecx, ecx
xor		rdx, rdx
push	rsi
push	rdi
cmp		rbx, 0
je		_ret_zero

_loop1:
mov		cl, [rsi]
mov		al, [rdi]
cmp		rbx, 0x0
je		_check
cmp		cl, 0x0
jz		_ret
cmp		al, 0x0
jz		_ret
sub		ax, cx
jne		_leave
inc		rdi
inc		rsi
dec		rbx
jmp		_loop1

_check:
cmp		cl, 0x0
jz		_ret
cmp		al, 0x0
jz		_ret
sub		ax, cx
jne		_leave

_ret_zero:
pop		rdi
pop		rsi
mov		rax, 0
ret

_leave:
cmp		cl, 0x0
jz		_ret
cmp		al, 0x0
jz		_ret
pop		rdi
pop		rsi
cwde
cdqe
ret

_ret:
pop		rdi
pop		rsi
ret

