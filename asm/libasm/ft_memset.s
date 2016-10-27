# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/26 11:32:42 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/26 13:40:32 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_memset

section .text

_ft_memset:
push		rdi
mov		 	rcx, rdx
mov			rax, rsi
cld
rep			stosb
pop			rax
ret
