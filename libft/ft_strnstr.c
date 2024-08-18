/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:40:31 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/26 20:40:26 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (!haystack && len < 1)
		return (NULL);
	if (!*needle)
		return ((char *) haystack);
	while (*haystack && len)
	{
		i = 0;
		while (needle[i] == haystack[i] && (len - i))
			if (!needle[i++ + 1])
				return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
