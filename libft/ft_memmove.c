/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:40:44 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/01 06:30:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <aio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (dest > src)
			((unsigned char *)dest)[(n - 1) - i] = \
			((unsigned char *)src)[(n - 1) - i];
		else
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
	char a[20] = "1234567890";

	printf("%s\n", a);
	printf("%s\n", (char *)ft_memmove(a, &a[2], 5));
	printf("%s\n", a);
	char b[20] = "1234567890";

	printf("%s\n", b);
	printf("%s\n", (char *)ft_memmove(&b[2], b, 5));
	printf("%s\n", b);
}

*/
