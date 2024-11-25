/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:56:32 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/24 15:45:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_file_output(t_data *data)
{
	if (data->str_file_out && !data->pipe_front[0])
		data->file_out = open(data->str_file_out, \
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (!data->pipe_front[0])
		data->file_out = open(data->str_file_out, \
				O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (data->file_out < 0)
	{
		ft_exit(data, "pipex : unable to create the output file\n", 1);
	}
}

void	init_file_input(t_data *data)
{
	if (!data->file_in && !data->pipe_back[0])
		data->file_in = open(data->str_file_in, O_RDONLY);
	if (data->file_in != -1)
		return ;
	perror(data->str_file_in);
	exit(1);
}

static int	hook_stdio(t_data *data)
{
	if (data->pipe_front[0] == 0)
		if (dup2(data->file_out, 1) < 0)
			return (1);
	close(data->file_out);
	data->file_out = 0;
	if (data->pipe_back[0] == 0)
		if (dup2(data->file_in, 0) < 0)
			return (1);
	close(data->file_in);
	data->file_in = 0;
	return (0);
}

void	hook_into_files(t_data *data)
{
	init_file_output(data);
	init_file_input(data);
	if (hook_stdio(data))
		ft_exit(data, "the program failed to hook to the input file\n", 1);
}
