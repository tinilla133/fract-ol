/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:58:30 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/30 03:26:30 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	slen;
	unsigned int	i;
	char			*buff;

	if (s == NULL || f == NULL)
		return (NULL);
	slen = (unsigned int) ft_strlen(s);
	buff = (char *) malloc (slen * sizeof (char) + 1);
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (*s)
		*buff++ = f(i++, *s++);
	*buff = '\0';
	return (buff - slen);
}
