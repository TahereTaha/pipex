/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:02:38 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/25 10:22:06 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	clean_data(t_data *data)
{
	free_strs(data->path);
	free_strs(data->argv);
	close_pipe(data->pipe_back);
	close_pipe(data->pipe_front);
	if (data->file_in != 0)
		close(data->file_in);
	if (data->file_out != 0)
		close(data->file_out);
}

void	ft_exit(t_data *data, char *message, int exit_status)
{
	if (data)
		clean_data(data);
	if (exit_status)
		write(2, message, ft_strlen(message));
	else
		write(1, message, ft_strlen(message));
	exit(exit_status);
}
