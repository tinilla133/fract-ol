/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:03:47 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/26 18:07:10 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	return_len;

	destlen = 0;
	srclen = ft_strlen(src);
	if ((src == NULL || dest == NULL) && size < 1)
		return (0);
	while (*(dest + destlen) && destlen < size)
		destlen++;
	if (size > destlen)
		return_len = destlen + srclen;
	else
		return (size + srclen);
	while (*src && (destlen + 1) < size)
		dest[destlen++] = *src++;
	dest[destlen] = '\0';
	return (return_len);
}
