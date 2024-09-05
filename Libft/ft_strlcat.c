/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:19:29 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/10 21:19:10 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;
	size_t	i;

	dsize = 0;
	while (dst[dsize] != '\0' && dsize < dstsize)
		dsize++;
	i = dsize;
	while (src[dsize - i] && dsize + 1 < dstsize)
	{
		dst[dsize] = src[dsize - i];
		dsize++;
	}
	if (i < dstsize)
		dst[dsize] = '\0';
	return (i + ft_strlen(src));
}
