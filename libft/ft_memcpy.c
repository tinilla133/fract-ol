/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:02:16 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/14 20:51:22 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptrdst = (unsigned char *) dst;
	ptrsrc = (unsigned char *) src;
	while (n--)
		*ptrdst++ = *ptrsrc++;
	return (dst);
}
