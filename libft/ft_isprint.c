/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:30:19 by tatahere          #+#    #+#             */
/*   Updated: 2024/06/17 05:45:15 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character >= ' ' && character <= '~')
	{
		return (1);
	}
	return (0);
}
