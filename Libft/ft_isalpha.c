/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:08:01 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/10 21:01:22 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c;
	c = 'Q';
	printf("Resultado cuando es mayúscula: %d", isalpha(c));
	printf("\nMi resultado cuando es mayúscula: %d", ft_isalpha(c));

	c = 'q';
	printf("\nResultado cuando es minúscula: %d", isalpha(c));
	printf("\nMi resultado cuando es minúscula: %d", ft_isalpha(c));

	c='+';
	printf("\nResultado cuando no es un carácter: %d", isalpha(c));
	printf("\nMi resultado cuando no es un carácter: %d\n", ft_isalpha(c));

	return (0);
}*/