/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:13:09 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/24 15:41:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_pathname(t_data *data, char *cmd)
{
	char	*pathname;
	char	*tmp;
	int		i;

	if (!data->path)
		ft_exit(data, "no such file or directory\n", 127);
	i = 0;
	while (data->path[i])
	{
		tmp = ft_strjoin(data->path[i], "/");
		if (!tmp)
			ft_exit(data, "malloc error unable to continue\n", 1);
		pathname = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!pathname)
			ft_exit(data, "malloc error unable to continue\n", 1);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		if (access(pathname, F_OK) == 0)
			ft_exit(data, ": command has no permision\n", 126);
		free(pathname);
		i++;
	}
	ft_exit(data, ft_strjoin(cmd, ": comand not fonund\n"), 127);
	return (NULL);
}

void	execute_cmd(t_data *data, int index)
{
	char	*pathname;

	data->argv = ft_split(data->cmd_list[index], ' ');
	if (!data->argv)
		ft_exit(data, "malloc error unable to continue\n", 1);
	pathname = find_pathname(data, data->argv[0]);
	hook_into_files(data);
	hook_into_pipes(data);
	execve(pathname, data->argv, data->env);
}

pid_t	fork_child_proses(t_data *data, int index)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		ft_exit(data, "fork error unable to continue\n", 1);
	if (child != 0)
		return (child);
	execute_cmd(data, index);
	return (child);
}

int	wait_children(pid_t *child_list)
{
	int	exit_status;
	int	i;

	i = 0;
	while (child_list[i])
	{
		waitpid(child_list[i], &exit_status, 0);
		i++;
	}
	free(child_list);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	return (exit_status);
}

int	pipe_cmd_list(t_data *data)
{
	int		index;
	pid_t	*child_list;

	child_list = ft_calloc(sizeof(pid_t *), data->cmd_len + 1);
	if (!child_list)
		ft_exit(data, "malloc error unable to continue\n", 1);
	index = 0;
	while ((index + 1) < data->cmd_len)
	{
		if (pipe(data->pipe_front))
			ft_exit(data, "pipe error unable to continue\n", 1);
		child_list[index] = fork_child_proses(data, index);
		close_pipe(data->pipe_back);
		ft_memmove(data->pipe_back, data->pipe_front, sizeof(int) * 2);
		index++;
	}
	ft_bzero(data->pipe_front, sizeof(int) * 2);
	child_list[index] = fork_child_proses(data, index);
	close_pipe(data->pipe_back);
	return (wait_children(child_list));
}
