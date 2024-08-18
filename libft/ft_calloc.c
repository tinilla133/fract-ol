/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:22:18 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/01 14:20:35 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*buff;
	unsigned char	*ptrbuff;
	size_t			szmem;

	if (count != 0 && SIZE_MAX / count < size)
		szmem = SIZE_MAX;
	szmem = (unsigned int)count * size;
	buff = (void *) malloc(szmem);
	if (buff == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptrbuff = (unsigned char *) buff;
	while (szmem--)
		*ptrbuff++ = 0;
	return (buff);
}
