/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:58:28 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/21 08:16:52 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(int *pipe)
{
	if (pipe[0] != 1 && pipe[0] != 0)
	{
		close(pipe[0]);
		pipe[0] = 0;
	}
	if (pipe[1] != 1 && pipe[1] != 0)
	{
		close(pipe[1]);
		pipe[1] = 0;
	}
}

void	close_unused_pipe_ends(int *pipe_back, int *pipe_front)
{
	if (pipe_back[1] != 1 && pipe_back[1] != 0)
	{
		close(pipe_back[1]);
		pipe_back[1] = 0;
	}
	if (pipe_front[0] != 0 && pipe_front[0] != 0)
	{
		close(pipe_front[0]);
		pipe_front[0] = 0;
	}
}

static int	hook_stdin(int *pipe)
{
	int	dup_err;

	dup_err = 0;
	if (pipe[0] != 1 && pipe[0] != 0)
	{
		dup_err = dup2(pipe[0], 0);
		if (dup_err >= 0)
			dup_err = 0;
		close(pipe[0]);
		pipe[0] = 0;
	}
	return (dup_err);
}

static int	hook_stdout(int *pipe)
{
	int	dup_err;

	dup_err = 0;
	if (pipe[1] != 1 && pipe[1] != 0)
	{
		dup_err = dup2(pipe[1], 1);
		if (dup_err >= 0)
			dup_err = 0;
		close(pipe[1]);
		pipe[1] = 0;
	}
	return (dup_err);
}

//	this fuction hook_into_pipes can error and close the program.
void	hook_into_pipes(t_data	*data)
{
	close_unused_pipe_ends(data->pipe_back, data->pipe_front);
	if (hook_stdin(data->pipe_back))
		ft_exit(data, "the program failed to hook to the pipes or files\n", 1);
	if (hook_stdout(data->pipe_front))
		ft_exit(data, "the program failed to hook to the pipes or files\n", 1);
}
