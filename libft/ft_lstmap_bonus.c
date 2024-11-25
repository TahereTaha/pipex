/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:35:58 by tatahere          #+#    #+#             */
/*   Updated: 2024/07/05 08:50:20 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*curent_node;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(lst->content);
	if (!new_list)
		return (0);
	curent_node = new_list;
	while (lst->next)
	{
		curent_node->content = (*f)(lst->content);
		curent_node->next = ft_lstnew(lst->content);
		if (!curent_node->next)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		lst = lst->next;
		curent_node = curent_node->next;
	}
	curent_node->content = (*f)(lst->content);
	return (new_list);
}
