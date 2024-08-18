/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:07:03 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/30 03:26:13 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	init;
	unsigned int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	init = 0;
	while (ft_strchr(set, s1[init]) && s1[init])
		init++;
	end = ft_strlen(s1);
	while (ft_strrchr(set, s1[end]) && end)
		end--;
	return (ft_substr(s1, init, end - init + 1));
}
