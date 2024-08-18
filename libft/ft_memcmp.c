/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:06:35 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/26 18:53:41 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	ptrs1 = (unsigned char *) s1;
	ptrs2 = (unsigned char *) s2;
	while (n--)
		if (*(ptrs1++) != *(ptrs2++))
			return (*(ptrs1 - 1) - *(ptrs2 - 1));
	return (0);
}
