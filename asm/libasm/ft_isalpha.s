# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.asm                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 18:17:15 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/22 20:10:29 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isalpha

section .text

_ft_isalpha:
mov		rax, 1			; ret value
cmp		rdi, 0x41		; cmp 'A' <
jl		_leave			; jump _leave
cmp		rdi, 0x5b		; cmp '[' >=
jge		_next			; jump _next
ret						; return

_next:
cmp		rdi, 0x61		; cmp 'a' <
jl		_leave			; jump _leave
cmp		rdi, 0x7b		; cmp '{' >=
jge		_leave			; jump _leave
ret						; return

_leave:
mov		rax, 0			; ret value
ret						; return
