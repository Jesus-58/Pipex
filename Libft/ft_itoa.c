/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:09:54 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/29 13:19:51 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigit(int n)
{
	int	count;

	count = 0;
	if (n != 0)
	{
		if (n < 0)
		{
			n *= -1;
			count++;
		}
		while (n != 0)
		{
			n /= 10;
			count++;
		}
	}
	else
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = ft_countdigit(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len] = ((num % 10) + '0');
		num /= 10;
		len--;
	}
	return (str);
}
