/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:18:35 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/11 19:47:07 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*#include <stdio.h>

int main()
{
   char s[11] = "Hola amigos";
   char c = 'a';

   printf( "s=%s\t", s );
   printf( "c=%c\n", c );
   printf( "strchr=%s\n", strchr( s, c ) );

   return 0;
}*/