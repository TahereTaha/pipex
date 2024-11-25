/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:19:14 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/31 08:33:52 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	ft_lintlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(long n)
{
	char	*str;
	long	nbr;
	int		i;

	i = ft_lintlen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	nbr = n;
	while (nbr)
	{
		str[i--] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("%s\n", ft_itoa(ft_atoi(av[1])));
}

*/
