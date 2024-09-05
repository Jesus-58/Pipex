/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:17:44 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/29 14:11:10 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dest;

	dest = dst;
	if ((!dst && !src) || dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else
	{
		while (len--)
			*(char *)dst++ = *(char *)src++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char src[] = "Hello, World!";
	char dst[20];

	// Copiar src a dst usando ft_memmove
	ft_memmove(dst, src, strlen(src));
	printf("\n");
	memmove(dst, src, strlen(src));

	// Imprimir el resultado
	printf("dst: %s\n", dst);

	return 0;
}*/