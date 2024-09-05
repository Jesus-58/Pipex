/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:07:16 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/12 19:07:57 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	int result;

	c = '0';
	result = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);

	c = 'A';
	result = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);

	c = 'a';
	result = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);

	c = '+';
	result = ft_isalnum(c);
	printf("When %c is passed, return value is %d\n", c, result);

	return 0;
}*/