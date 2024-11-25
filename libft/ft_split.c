/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:55:38 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/05 08:08:03 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_separation_amount(const char *str, char c)
{
	size_t	i;
	size_t	separation_count;

	i = 0;
	separation_count = 0;
	if (str[0] == '\0')
		return (0);
	while ((i + 1) < ft_strlen(str))
	{
		if ((str[i] != c) && (str[i + 1] == c))
			separation_count++;
		i++;
	}
	if (str[i] != c)
		separation_count++;
	return (separation_count);
}

static char	**ft_freestrs(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;
	int		j;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_separation_amount(s, c) + 1));
	if (!strs)
		return (0);
	i = 0;
	j = 0;
	while (j < ft_separation_amount(s, c))
	{
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(s, &s[i] - s, ft_strchr(&s[i], c) - &s[i]);
		if (!strs[j])
			return (ft_freestrs(strs, j));
		i += ft_strchr(&s[i], c) - &s[i];
		j++;
	}
	strs[j] = 0;
	return (strs);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	char	**strs;

	if (ac != 3)
		return (1);
	i = 0;
	strs = ft_split(av[1], av[2][0]);
	while (strs[i])
		printf("%s\n", strs[i++]);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);

}

*/
