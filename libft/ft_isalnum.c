/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:22:21 by tatahere          #+#    #+#             */
/*   Updated: 2024/06/17 05:35:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if ((character >= 'A' && character <= 'Z') || \
		(character >= 'a' && character <= 'z') || \
		(character >= '0' && character <= '9'))
		return (1);
	return (0);
}
