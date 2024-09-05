/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:03:00 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/06 22:27:27 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = 0;
		s = (char *)s + 1;
		n--;
	}
}
/*
#include <stdio.h>
#include <string.h>

int main() {
	char str[10] = "Hello";

	printf("Antes de llamar a ft_bzero: %s\n", str);

	ft_bzero(str, sizeof(str));

	printf("Después de llamar a ft_bzero: %s\n", str);

	return 0;
}*/