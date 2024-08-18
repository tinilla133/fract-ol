/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:18:54 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/31 23:14:40 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*fst_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	fst_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(lst->content);
		if (new_node == NULL)
		{
			ft_lstclear(&fst_node, del);
			return (NULL);
		}
		new_node->content = f(new_node->content);
		ft_lstadd_back(&fst_node, new_node);
		lst = lst->next;
	}
	return (fst_node);
}
