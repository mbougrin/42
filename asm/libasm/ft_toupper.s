# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.asm                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 12:37:17 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/23 13:05:43 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_toupper

section .text

_ft_toupper:
mov		rax, rdi
cmp		rdi, 0x61		; cmp >= 'a'
jge		_check			; jump _check 
ret

_check:
cmp		rdi, 0x7b		; cmp < {
jl		_leave			; jump _upper
ret

_leave:
sub		rax, 32
ret
