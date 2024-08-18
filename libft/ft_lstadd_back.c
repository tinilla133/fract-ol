/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:37:33 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/30 03:29:07 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptrlst;

	if (lst == NULL || new == NULL)
		return ;
	ptrlst = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (ptrlst->next != NULL)
		ptrlst = ptrlst->next;
	ptrlst->next = new;
}
