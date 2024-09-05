/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:18:34 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/12 19:35:39 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len--)
		*(a++) = (unsigned char)c;
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
	char str[20] = "Hello, world!";
	printf("Antes de memset: %s\n", str);

	// Llamada a la función memset
	ft_memset(str, '*', 3);

	printf("Después de memset: %s\n", str);

	return 0;
}*/