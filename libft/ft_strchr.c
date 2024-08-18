/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:41:49 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/30 03:25:52 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptrs;

	ptrs = (char *) s;
	while (*ptrs)
	{
		if (*ptrs == (char) c)
			return (ptrs);
		ptrs++;
	}
	if (*ptrs == (char) c)
		return (ptrs);
	return (NULL);
}
