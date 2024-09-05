/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:07:16 by jesumore          #+#    #+#             */
/*   Updated: 2024/09/05 18:56:12 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_redirect_to_outfile(t_args *pipex)
{
	int	outfile_fd;

	outfile_fd = -1;
	if (pipex->is_here_doc == 1)
	{
		outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (outfile_fd == -1)
			ft_error(pipex, "Error: can't create or write in the outfile\n");
	}
	else
	{
		outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
			ft_error(pipex, "Error: can't create or write in the outfile\n");
	}
	dup2(outfile_fd, STDOUT_FILENO);
	close_fd(outfile_fd);
}

static void	ft_here_doc_input(t_args *pipex, int write_pipe)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, pipex->limiter, ft_strlen(pipex->limiter)) == 0
			&& line[ft_strlen(pipex->limiter)] == '\n')
			break ;
		write(write_pipe, line, ft_strlen(line));
		write(write_pipe, "\n", 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close_fd(write_pipe);
}

static void	ft_exec_child(t_args *pipex, int infile_fd, int *pipe_fd, int i)
{
	if (i == 0 && pipex->is_here_doc == 1)
	{
		ft_here_doc_input(pipex, pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close_fd(pipe_fd[0]);
		close_fd(pipe_fd[1]);
	}
	else
	{
		dup2(infile_fd, STDIN_FILENO);
		close_fd(infile_fd);
	}
	if (i < pipex->num_cmds - 1)
		dup2(pipe_fd[1], STDOUT_FILENO);
	else
		ft_redirect_to_outfile(pipex);
	close_fd(pipe_fd[0]);
	close_fd(pipe_fd[1]);
	if (execve(ft_get_command_path(pipex, pipex->cmds[i][0], pipex->env)
		, pipex->cmds[i], pipex->env) == -1)
		ft_error(pipex, "Error executing command\n");
}

static void	ft_principal_exec(t_args *pipex, int infile_fd, int i)
{
	int	pipe_fd[2];
	int	pid;
	int	status;

	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	if (i < pipex->num_cmds - 1 && pipe(pipe_fd) == -1)
		ft_error(pipex, "Error creating the pipe\n");
	pid = fork();
	if (pid < 0)
		ft_error(pipex, "Error creating the child process\n");
	else if (pid == 0)
		ft_exec_child(pipex, infile_fd, pipe_fd, i);
	else
	{
		close_fd(infile_fd);
		if (i < pipex->num_cmds - 1)
		{
			close_fd(pipe_fd[1]);
			ft_principal_exec(pipex, pipe_fd[0], i + 1);
		}
		if (waitpid(pid, &status, 0) == -1)
			ft_error(pipex, "Error waiting for child process\n");
	}
}

void	ft_cmd_process(t_args *pipex)
{
	int	infile_fd;

	if (pipex->is_here_doc == 1)
		infile_fd = -1;
	else
	{
		infile_fd = open(pipex->infile, O_RDONLY);
		if (infile_fd == -1)
			ft_error(pipex, "Error: can't open infile\n");
	}
	ft_principal_exec(pipex, infile_fd, 0);
}
