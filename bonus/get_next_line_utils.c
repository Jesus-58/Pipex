/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:18:09 by jesumore          #+#    #+#             */
/*   Updated: 2024/08/27 00:01:31 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc( size_t size, size_t count)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(size * count);
	if (!mem)
		return (0);
	while (i < (size * count))
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = ft_calloc(sizeof(char), (len_s1 + len_s2 + 1));
	i = 0;
	j = 0;
	if (new == NULL)
		return (NULL);
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		new[i + j] = s2[j];
		j++;
	}
	return (new);
}
