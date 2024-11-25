/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:42:28 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/24 16:02:14 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_here_doc(char *end_str)
{
	char	*line;
	int		here_doc_pipe[2];

	if (pipe(here_doc_pipe))
		return (-1);
	line = ft_strdup("");
	while (ft_strncmp(end_str, line, ft_strlen(end_str)))
	{
		write(here_doc_pipe[1], line, ft_strlen(line));
		free(line);
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line)
			ft_exit(NULL, "malloc error\n", 1);
	}
	free(line);
	close(here_doc_pipe[1]);
	get_next_line(-1);
	return (here_doc_pipe[0]);
}

char	**get_paths(t_data *data)
{
	char	**paths;
	char	**env;

	env = data->env;
	while (*env)
	{
		if (ft_strnstr(*env, "PATH", 4))
			break ;
		env++;
	}
	if (!*env)
		return (NULL);
	paths = ft_split(*env + 5, ':');
	if (!paths)
		ft_exit(data, "a mallac has failed\n", 1);
	return (paths);
}

void	init_cmd_list(t_data *data, int ac, char **av)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		data->cmd_len = ac - 4;
		data->cmd_list = &av[3];
	}
	else
	{
		data->cmd_len = ac - 3;
		data->cmd_list = &av[2];
	}
	data->cmd_list[ac - 3] = NULL;
}

void	init_data(t_data *data, int ac, char **av, char **env)
{
	char	*here_dock_str;

	ft_bzero(data, sizeof(t_data));
	here_dock_str = ft_strjoin(av[2], "\n");
	if (!here_dock_str)
		ft_exit(data, "pipex : malloc fail", 1);
	data->str_file_in = av[1];
	data->str_file_out = av[ac - 1];
	if (!ft_strncmp(av[1], "here_doc", 9))
		data->file_in = init_here_doc(here_dock_str);
	free(here_dock_str);
	init_cmd_list(data, ac, av);
	data->env = env;
	data->path = get_paths(data);
}
