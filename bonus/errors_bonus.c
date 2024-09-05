/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:19:33 by jesumore          #+#    #+#             */
/*   Updated: 2024/09/05 18:57:39 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	ft_free_struct(t_args *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmds)
	{
		while (pipex->cmds[i])
		{
			ft_free_array(pipex->cmds[i]);
			i++;
		}
		free(pipex->cmds);
		pipex->cmds = NULL;
	}
}

void	ft_error(t_args *pipex, const char *str)
{
	ft_free_struct(pipex);
	perror(str);
	exit(EXIT_FAILURE);
}

void	close_fd(int fd)
{
	if (fd != -1)
		close(fd);
}
