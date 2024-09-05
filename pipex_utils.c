/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:44:03 by jesumore          #+#    #+#             */
/*   Updated: 2024/08/23 20:50:30 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_struct(t_args *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd_1)
	{
		while (pipex->cmd_1[i])
		{
			free(pipex->cmd_1[i]);
			i++;
		}
		free(pipex->cmd_1);
	}
	i = 0;
	if (pipex->cmd_2)
	{
		while (pipex->cmd_2[i])
		{
			free(pipex->cmd_2[i]);
			i++;
		}
		free(pipex->cmd_2);
	}
}

void	ft_error(t_args *pipex, const char *str)
{
	ft_free_struct(pipex);
	perror(str);
	exit(EXIT_FAILURE);
}

int	ft_is_void(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != 32 && !(str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*ft_get_command_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free_array(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_array(paths);
	return (NULL);
}
