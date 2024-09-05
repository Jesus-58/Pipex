/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:13:57 by jesumore          #+#    #+#             */
/*   Updated: 2024/08/22 15:57:17 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define INFILE_ERROR "Error: infile not exist or don't have read permision\n"

typedef struct s_args
{
	char	*infile;
	char	*outfile;
	char	**cmd_1;
	char	**cmd_2;
	char	**env;
}			t_args;

/*Args parse*/

void	ft_parse_args(t_args *pipex, char **argv);
int		ft_is_void(char *av);
//void	ft_env_path(char **env);

/*Errors management*/

void	ft_error(t_args *pipex, const char *str);
void	ft_free_struct(t_args *pipex);
void	ft_free_array(char **array);

/*Execute pipex*/

void	ft_cmd_process(t_args *pipex);
char	*ft_get_command_path(char *cmd, char **env);