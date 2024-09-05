/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:16:46 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/10 21:54:58 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sentence1;
	unsigned char	*sentence2;

	sentence1 = (unsigned char *)s1;
	sentence2 = (unsigned char *)s2;
	while (n--)
	{
		if (*sentence1 != *sentence2)
			return ((int)(*sentence1 - *sentence2));
		sentence1++;
		sentence2++;
	}
	return (0);
}
