/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:14:35 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/26 16:38:17 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;
	size_t				i;

	ptrdst = (unsigned char *) dst;
	ptrsrc = (const unsigned char *) src;
	i = 0;
	if ((ptrdst == NULL && ptrsrc == NULL) || ptrdst == ptrsrc)
		return (dst);
	if (ptrdst > ptrsrc && ptrdst - ptrsrc < (long int) len)
		while (len--)
			*(ptrdst + len) = *(ptrsrc + len);
	else if (ptrsrc > ptrdst && ptrsrc - ptrdst < (long int) len)
	{
		while (i < len)
		{
			*ptrdst++ = *ptrsrc++;
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
