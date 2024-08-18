/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:25:20 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/31 22:59:39 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptrlst;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		ptrlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptrlst;
	}
	*lst = NULL;
}
