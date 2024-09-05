/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:24:07 by jesumore          #+#    #+#             */
/*   Updated: 2024/08/27 00:01:15 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_text(int fd, char *text)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(text, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(text, buffer);
		free(text);
		text = tmp;
	}
	free(buffer);
	return (text);
}

static char	*ft_get_line(char *text)
{
	int		i;
	char	*first_line;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	first_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!first_line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		first_line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		first_line[i] = text[i];
		i++;
	}
	first_line[i] = '\0';
	return (first_line);
}

static char	*ft_update_text(char *text)
{
	char	*updated_text;
	int		i;
	int		j;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	updated_text = (char *)malloc(sizeof(char) * ft_strlen(text) - i + 1);
	if (!updated_text)
		return (NULL);
	i++;
	j = 0;
	while (text[i])
		updated_text[j++] = text[i++];
	updated_text[j] = '\0';
	free(text);
	return (updated_text);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (text)
			free(text);
		text = NULL;
		return (NULL);
	}
	text = ft_get_text(fd, text);
	if (!text)
		return (NULL);
	line = ft_get_line(text);
	text = ft_update_text(text);
	return (line);
}
