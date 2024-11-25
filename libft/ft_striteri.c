/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:47:35 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/05 08:14:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, (char *)&s[i]);
		i++;
	}
	return ;
}
