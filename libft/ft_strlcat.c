/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 06:05:30 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/01 08:35:55 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (size > dst_len)
		return (dst_len + src_len);
	return (src_len + size);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char	a[20] = "hello 1234567890";

	printf("testing strlcat with the first string being \"hello \" \
			and the second string being the first parameter, \
			and the size is 20\n");
	printf("%zu\n%s\n", ft_strlcat(a, av[1], 5), a);
}
*/
