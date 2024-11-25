/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:17:07 by tatahere          #+#    #+#             */
/*   Updated: 2024/06/17 05:45:27 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if ((character >= '0' && character <= '9'))
	{
		return (1);
	}
	return (0);
}
