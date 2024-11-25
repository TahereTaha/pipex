/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 06:23:30 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/24 07:11:38 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_data
{
	int		file_in;
	int		file_out;
	int		pipe_back[2];
	int		pipe_front[2];
	int		cmd_len;
	char	*str_file_in;
	char	*str_file_out;
	char	**cmd_list;
	char	**path;
	char	**env;
	char	**argv;
}	t_data;

void	ft_exit(t_data *data, char *message, int exit_status);
void	init_data(t_data *data, int ac, char **av, char **env);

void	close_pipe(int *pipe);

void	close_unused_pipe_ends(int *pipe_back, int *pipe_front);
void	hook_into_pipes(t_data	*data);
void	hook_into_files(t_data *data);

int		pipe_cmd_list(t_data *data);
#endif
