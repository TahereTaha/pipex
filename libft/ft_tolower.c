/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:35:58 by tatahere          #+#    #+#             */
/*   Updated: 2024/06/18 15:02:22 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character >= 'A' && character <= 'Z')
		return (character + 32);
	return (character);
}
