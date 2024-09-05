/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:44:03 by jesumore          #+#    #+#             */
/*   Updated: 2024/09/05 19:03:09 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_pipex_init(t_args *pipex, char **env)
{
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmds = NULL;
	pipex->env = env;
	pipex->num_cmds = 0;
	pipex->is_here_doc = 0;
}

void	ft_open_outfile(t_args *pipex, int argc, char **argv)
{
	int	outfile_fd;

	if (pipex->is_here_doc == 1)
		outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_error(pipex, "Error: can't create or write in the outfile\n");
	close(outfile_fd);
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

char	*ft_get_command_path(t_args *pipex, char *cmd, char **env)
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
	while (paths[i++])
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
	}
	ft_free_array(paths);
	ft_error(pipex, "Error: command path NULL\n");
	return (NULL);
}
