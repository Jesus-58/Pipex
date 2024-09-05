/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:12:43 by jesumore          #+#    #+#             */
/*   Updated: 2024/02/02 13:10:45 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <stdio.h>
#include <string.h>

int main()
{
   char s1[9] = "artista";
   char s2[8] = "arbol";
   int i;
   int j;

   printf( "s1 = %s\t", s1);
   printf( "s2 = %s\n", s2);

   i = strncmp(s1, s2, 3);
   j = ft_strncmp(s1, s2, 3);
   printf("%i\t%i\n", i, j);
   return (0);
}*/