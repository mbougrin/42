# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.asm                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 14:40:51 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/23 14:44:39 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_tolower

section .text

_ft_tolower:
mov		rax, rdi
cmp		rdi, 0x41		; cmp >= 'A'
jge		_check			; jump _check 
ret

_check:
cmp		rdi, 0x5b		; cmp < [
jl		_leave			; jump _upper
ret

_leave:
add		rax, 32			; add 32
ret						; return 
