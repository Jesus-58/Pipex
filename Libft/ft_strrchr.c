/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:53:13 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/29 14:24:18 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)last);
}
/*#include <stdio.h>
#include <string.h>

int main()
{
   char s[11] = "Hola amigos";
   char c = 'a';

   printf("s = %s\n", s);
   printf("c = %c\n", c);
   printf("strrchr = %s\n", strrchr( s, c));
   printf("\n");
   printf("s = %s\n", s);
   printf("c = %c\n", c);
   printf("strrchr = %s\n", ft_strrchr( s, c));

   return (0);
}*/