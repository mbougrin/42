# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.asm                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 11:47:17 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/23 12:02:27 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isalnum

section .text

_ft_isalnum:
mov		rax, 1			; ret value
cmp		rdi, 0x30		; cmp '0' <
jl		_leave			; jump _leave
cmp		rdi, 0x3a		; cmp ':' >=
jge		_next			; jump _next
ret						; return

_next:
cmp		rdi, 0x41		; cmp 'A' <
jl		_leave			; jump _leave
cmp		rdi, 0x5b		; cmp '[' >=
jge		_next_cmp		; jump _next_cmp
ret						; return

_next_cmp:
cmp		rdi, 0x61		; cmp 'a' <
jl		_leave			; jump _leave
cmp		rdi, 0x7b		; cmp '{' >=
jge		_leave			; jump _leave
ret						; return

_leave:
mov		rax, 0			; ret value
ret						; return
