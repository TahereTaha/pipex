/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:24:19 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/05 08:05:39 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;

	if (ac != 3)
		return (printf("please provide only 2 strings, no more no les\n"));
	str = ft_strjoin(av[1], av[2]);
	if (!str)
		return (printf("the malloc in strjoin failed\n"));
	printf("the string is\n>>%s<<\n", str);
}
*/
