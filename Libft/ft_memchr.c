/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:17:29 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/30 18:44:15 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (n--)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main() {
    char buffer[] = "Hello, World!";
    char *result = ft_memchr(buffer, 0, sizeof(buffer));

    if (result != NULL) {
        printf("Encontró el byte 0 en la posición %ld\n", result - buffer);
    } else {
        printf("No se encontró el byte 0 en el buffer.\n");
    }

    return 0;
}
*/