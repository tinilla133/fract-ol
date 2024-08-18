/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:02:37 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/26 21:58:15 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	bufflen;
	char	*buff;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	bufflen = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	buff = (char *) malloc(bufflen * sizeof (char) + 1);
	if (buff == NULL)
		return (NULL);
	while (*s1)
		*buff++ = *s1++;
	while (*s2)
		*buff++ = *s2++;
	*buff = '\0';
	return (buff - bufflen);
}
/*
#include <stdio.h>

int main(void)
{
	char s1[] = "Hola Mundo ";
	char s2[] = "Hola Manolo";

	printf("ft_strjoin(%s, %s): %s\n", \
			s1, s2, ft_strjoin(s1, s2));
}
*/
