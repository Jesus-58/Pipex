/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:07:16 by jesumore          #+#    #+#             */
/*   Updated: 2024/08/23 20:50:33 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child_process1(t_args *pipex, int pipe_fd[2])
{
	int		infile_fd;
	char	*cmd_path_1;

	cmd_path_1 = ft_get_command_path(pipex->cmd_1[0], pipex->env);
	if (!cmd_path_1)
		ft_error(pipex, "Error: command 1 not found\n");
	infile_fd = open(pipex->infile, O_RDONLY);
	if (infile_fd == -1)
		ft_error(pipex, "Error opening infile in child process 1\n");
	close(pipe_fd[0]);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (execve(cmd_path_1, pipex->cmd_1, pipex->env) == -1)
		ft_error(pipex, "Error executing command 1\n");
	free(cmd_path_1);
}

static void	ft_child_process2(t_args *pipex, int pipe_fd[2])
{
	int		outfile_fd;
	char	*cmd_path_2;

	cmd_path_2 = ft_get_command_path(pipex->cmd_2[0], pipex->env);
	if (!cmd_path_2)
		ft_error(pipex, "Error: command 2 not found\n");
	outfile_fd = open(pipex->outfile, O_WRONLY);
	if (outfile_fd == -1)
		ft_error(pipex, "Error opening outfile in child process 2\n");
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	if (execve(cmd_path_2, pipex->cmd_2, pipex->env) == -1)
		ft_error(pipex, "Error executing command 2\n");
	free(cmd_path_2);
}

static void	ft_parent_process(t_args *pipex, int pipe_fd[2], int pid1, int pid2)
{
	int	status_pid1;
	int	status_pid2;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (waitpid(pid1, &status_pid1, 0) == -1)
		ft_error(pipex, "Error waiting for child process 1\n");
	if (waitpid(pid2, &status_pid2, 0) == -1)
		ft_error(pipex, "Error waiting for child process 2\n");
}

void	ft_cmd_process(t_args *pipex)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;

	if (pipe(pipe_fd) == -1)
		ft_error(pipex, "Error creating the pipe\n");
	pid1 = fork();
	if (pid1 < 0)
		ft_error(pipex, "Error creating the frist child process\n");
	else if (pid1 == 0)
		ft_child_process1(pipex, pipe_fd);
	pid2 = fork();
	if (pid2 < 0)
		ft_error(pipex, "Error creating the second child process\n");
	else if (pid2 == 0)
		ft_child_process2(pipex, pipe_fd);
	ft_parent_process(pipex, pipe_fd, pid1, pid2);
}
