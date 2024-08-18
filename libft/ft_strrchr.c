/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:25:04 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/26 19:59:39 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*ptrs;
	size_t		len;

	len = ft_strlen(s);
	ptrs = (char *) s;
	while (len)
		if (ptrs[len--] == (char) c)
			return (&ptrs[len + 1]);
	if (ptrs[len] == (char) c)
		return (&ptrs[len]);
	return (NULL);
}
