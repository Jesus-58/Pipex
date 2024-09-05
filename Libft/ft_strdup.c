/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:02:37 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/29 18:22:36 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		len;
	int		i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

/*#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const char *s = "Hello, world!";
	char *duplicate = ft_strdup(s);

	if (duplicate == NULL) {
		printf("Error: Memory allocation failed.\n");
		return 1;
	}

	printf("Original string: %s\n", s);
	printf("Duplicate string: %s\n", duplicate);

	free(duplicate);

	return 0;
}*/