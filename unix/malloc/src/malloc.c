/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:10:36 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/18 18:19:03 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void			*realloc_tiny(void *ptr, size_t len, size_t size)
{
	void	*ptr1;

	ptr1 = alloc_large("add", size, NULL);
	ft_memcpy(ptr1, ptr, len);
	free(ptr);
	return (ptr1);
}

void			*realloc_small(void *ptr, size_t len, size_t size)
{
	void	*ptr1;

	ptr1 = alloc_large("add", size, NULL);
	ft_memcpy(ptr1, ptr, len);
	free(ptr);
	return (ptr1);
}

void			*realloc(void *ptr, size_t size)
{
	void	*ptr1;
	size_t	len;
	size_t	len_tiny;
	size_t	len_small;

	len_tiny = (getpagesize() * TINY) / 100;
	len_small = (getpagesize() * SMALL) / 100;
	if ((len = (size_t)alloc_tiny("len", 0, ptr)) != 0)
	{
		if (size >= len_tiny)
			ptr1 = realloc_tiny(ptr, len, size);
	}
	else if ((len = (size_t)alloc_small("len", 0, ptr)) != 0)
	{
		if (size >= len_small)
			ptr1 = realloc_small(ptr, len, size);
	}
	else if ((len = (size_t)alloc_large("len", 0, ptr)) != 0)
	{
		ptr1 = alloc_large("add", size, NULL);
		ft_memcpy(ptr1, ptr, len);
		free(ptr);
	}
	return (ptr1);
}

void			free(void *ptr)
{
	size_t	len;

	len = 0;
	if (ptr == NULL)
		return ;
	len = (size_t)alloc_tiny("len", 0, ptr);
	if (len == 0)
		len = (size_t)alloc_small("len", 0, ptr);
	if (len == 0)
		len = (size_t)alloc_large("len", 0, ptr);
	munmap(ptr, len);
}

void			*malloc(size_t size)
{
	void	*ptr1;
	size_t	len_tiny;
	size_t	len_small;

	len_tiny = (getpagesize() * TINY) / 100;
	len_small = (getpagesize() * SMALL) / 100;
	if (alloc_mem("tiny") == NULL)
		alloc_mem("add");
	if (size < len_tiny && (size_t)alloc_tiny("number", 0, NULL) < 100)
		ptr1 = alloc_tiny("add", size, NULL);
	else if (size < len_small && (size_t)alloc_small("number", 0, NULL) < 100)
		ptr1 = alloc_small("add", size, NULL);
	else
		ptr1 = alloc_large("add", size, NULL);
	if (((void *)-1) == ptr1)
		return (NULL);
	return (ptr1);
}
