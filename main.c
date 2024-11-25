/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:30:59 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/21 17:51:06 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//	just a auxiliar function
/*
void	print_strs(char **strs)
{
	int	i;

	if (!strs)
	{
		printf("%s\n", (char *) NULL);
		return ;
	}
	i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
}
*/
int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		ret_val;

	if (ac < 5 || (!ft_strncmp("here_doc", av[1], 8) && ac < 6))
		ft_exit(NULL, "not enough arguments\n", 1);
	init_data(&data, ac, av, env);
	ret_val = pipe_cmd_list(&data);
	ft_exit(&data, "", ret_val);
}
