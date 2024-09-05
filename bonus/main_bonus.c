/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:15:28 by jesumore          #+#    #+#             */
/*   Updated: 2024/09/05 18:51:38 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_env_path(t_args *pipex, char **env)
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
		ft_error(pipex, "Error path not found for commands\n");
}

void	ft_parse_here_doc(t_args *pipex, int argc, char **argv)
{
	int	i;

	pipex->limiter = argv[2];
	pipex->num_cmds = argc - 4;
	ft_open_outfile(pipex, argc, argv);
	pipex->outfile = argv[argc - 1];
	if (ft_is_void(argv[2]) == 1 || ft_is_void(argv[3]) == 1)
		ft_error(pipex, VOID_ERROR);
	pipex->cmds = malloc(sizeof(char **) * (pipex->num_cmds + 1));
	if (pipex->cmds == NULL)
		ft_error(pipex, "Error allocating memory for commands\n");
	i = 0;
	while (i < pipex->num_cmds)
	{
		pipex->cmds[i] = ft_split(argv[i + 3], ' ');
		if (pipex->cmds[i] == NULL || ft_is_void(pipex->cmds[i][0]) == 1)
			ft_error(pipex, "Error: command is empty or invalid\n");
		i++;
	}
	pipex->cmds[pipex->num_cmds] = NULL;
	ft_env_path(pipex, pipex->env);
}

void	ft_parse_args(t_args *pipex, int argc, char **argv)
{
	int	i;

	if (access(argv[1], R_OK) == -1)
		ft_error(pipex, INFILE_ERROR);
	pipex->infile = argv[1];
	ft_open_outfile(pipex, argc, argv);
	pipex->outfile = argv[argc - 1];
	pipex->num_cmds = argc - 3;
	pipex->cmds = malloc(sizeof(char **) * (pipex->num_cmds + 1));
	if (pipex->cmds == NULL)
		ft_error(pipex, "Error allocating memory for commands\n");
	i = 0;
	while (i < pipex->num_cmds)
	{
		pipex->cmds[i] = ft_split(argv[i + 2], ' ');
		if (ft_is_void(pipex->cmds[i][0]) == 1)
			ft_error(pipex, "Error: command is empty or invalid\n");
		i++;
	}
	pipex->cmds[pipex->num_cmds] = NULL;
	ft_env_path(pipex, pipex->env);
}

int	main(int argc, char **argv, char **env)
{
	t_args	pipex;

	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6))
	{
		write(2, "Error with the number of arguments\n", 36);
		return (EXIT_FAILURE);
	}
	else
	{
		ft_pipex_init(&pipex, env);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			pipex.is_here_doc = 1;
			ft_parse_here_doc(&pipex, argc, argv);
		}
		else
			ft_parse_args(&pipex, argc, argv);
		ft_cmd_process(&pipex);
		ft_free_struct(&pipex);
		return (EXIT_SUCCESS);
	}
}
