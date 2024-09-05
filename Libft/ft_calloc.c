/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:05:26 by jesumore          #+#    #+#             */
/*   Updated: 2024/01/10 21:36:29 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*memasigned;

	total_size = count * size;
	memasigned = malloc (total_size);
	if (memasigned == NULL)
		return (NULL);
	ft_bzero(memasigned, total_size);
	return (memasigned);
}
