# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.asm                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 14:54:23 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/26 11:11:57 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_puts


section .text

_ft_puts:
mov		rsi, rdi			; assign rsi <- rdi

_write_char:
cmp		[rsi], byte 0x0		; check \0
je		_leave				; jmp _leave rsi == 0x0
mov     rax, 0x2000004 		; write
mov     rdi, 1 				; init rdi stdout
mov     rdx, 1				; len write
syscall						; call write
inc		rsi					; incremente rsi
jmp		_write_char			; jump _write_char

_leave:

push	0x0A				; push on the stack \n
mov		rsi, rsp			; assign rsi <- rsp
mov     rax, 0x2000004 		; write
mov     rdi, 1 				; stdout
mov     rdx, 1				; len write
syscall						; call write

pop		rsi					; pop \n on the stack
mov     rax, 0x0A			; ret value
mov		rdi,0				; init rdi stdin
ret							; return
