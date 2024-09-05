/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:38:28 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/30 19:30:16 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[start], (end - start + 1));
	return (result);
}
/*
#include <stdio.h>
#include "libft.h"

int main()
{
	char *s1 = "   hello world   ";
	char *set = " ";
	char *trimmed = ft_strtrim(s1, set);
	
	printf("Original string: \"%s\"\n", s1);
	printf("Trimmed string: \"%s\"\n", trimmed);
	
	free(trimmed);
	
	return 0;
}*/