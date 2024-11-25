/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:11:16 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/01 06:35:12 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\v' || c == '\f' || c == '\n' || \
		c == '\r' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		nbr;
	size_t	i;
	int		sign;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr * sign);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("%i\n", ft_atoi(av[1]));
}
*/
