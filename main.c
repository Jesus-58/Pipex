/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:15:28 by jesumore          #+#    #+#             */
/*   Updated: 2024/08/22 18:33:54 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_env_path(char **env)
{
	int	i;
	int	path_found;

	i = 0;
	path_found = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_found = 1;
			break ;
		}
		i++;
	}
	if (path_found == 0)
	{
		write(2, "Error path not found for commands\n", 35);
		exit(EXIT_FAILURE);
	}
}

void	ft_parse_args(t_args *pipex, char **argv)
{
	int	outfile_fd;

	if (access(argv[1], R_OK) == -1)
		ft_error(pipex, INFILE_ERROR);
	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_error(pipex, "Error: can't create or write in the outfile\n");
	close(outfile_fd);
	if (ft_is_void(argv[2]) == 1 || ft_is_void(argv[3]) == 1)
	{
		write(2, "Error: Command can't be empty or with only spaces\n", 51);
		ft_free_struct(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->infile = argv[1];
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	pipex->outfile = argv[4];
	ft_env_path(pipex->env);
}

int	main(int argc, char **argv, char **env)
{
	t_args	pipex;

	if (argc != 5)
	{
		write(2, "Error with the number of arguments\n", 36);
		return (EXIT_FAILURE);
	}
	else
	{
		pipex.infile = NULL;
		pipex.cmd_1 = NULL;
		pipex.cmd_2 = NULL;
		pipex.outfile = NULL;
		pipex.env = env;
		ft_parse_args(&pipex, argv);
		ft_cmd_process(&pipex);
		ft_free_struct(&pipex);
		return (EXIT_SUCCESS);
	}
}
