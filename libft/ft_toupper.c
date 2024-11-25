/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:19:34 by tatahere          #+#    #+#             */
/*   Updated: 2024/06/18 15:01:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character >= 'a' && character <= 'z')
		return (character - 32);
	return (character);
}
