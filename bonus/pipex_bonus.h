/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:13:57 by jesumore          #+#    #+#             */
/*   Updated: 2024/09/05 18:55:17 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define INFILE_ERROR "Error: infile not exist or don't have read permision\n"
#define VOID_ERROR "Error: Command can't be empty or with only spaces\n"

typedef struct s_args
{
	int		is_here_doc;
	char	*limiter;
	char	*infile;
	char	*outfile;
	char	**env;
	char	***cmds;
	int		num_cmds;
}			t_args;

/*Pipex init*/

void	ft_pipex_init(t_args *pipex, char **env);

/*Args parse*/

void	ft_parse_args(t_args *pipex, int argc, char **argv);
void	ft_parse_here_doc(t_args *pipex, int argc, char **argv);
void	ft_open_outfile(t_args *pipex, int argc, char **argv);
int		ft_is_void(char *av);

/*Errors management*/

void	ft_error(t_args *pipex, const char *str);
void	ft_free_struct(t_args *pipex);
void	ft_free_array(char **array);
void	close_fd(int fd);

/*Execute pipex*/

void	ft_cmd_process(t_args *pipex);
char	*ft_get_command_path(t_args *pipex, char *cmd, char **env);