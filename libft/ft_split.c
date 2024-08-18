/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:12:18 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/30 03:43:20 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_freemem(char **buff)
{
	int	size;

	size = 0;
	while (buff[size])
		free(buff[size++]);
	free(buff);
}

unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			count++;
		s++;
	}
	return (count);
}

void	ft_get_positions(char const *s, char c, \
						unsigned int *init, unsigned int *end)
{
	unsigned int	i;
	int				found;

	i = *end;
	found = 0;
	while (*(s + i) && !found)
	{
		if (*(s + i) == c && *(s + i + 1) != c)
			*init = i + 1;
		if (*(s + i) != c && (*(s + i + 1) == c || !*(s + i + 1)))
		{
			*end = i + 1;
			found = 1;
		}
		i++;
	}
}

char	**ft_fillbuff(char **buff, char const *s, char c, unsigned int size)
{
	unsigned int	init;
	unsigned int	end;
	unsigned int	i;

	end = 0;
	init = 0;
	i = 0;
	while (i < size)
	{
		ft_get_positions(s, c, &init, &end);
		if (end - init > 0)
		{
			buff[i] = ft_substr(s, init, end - init);
			if (buff[i] == NULL)
			{
				ft_freemem(buff);
				return (NULL);
			}
		}
		i++;
	}
	buff[i] = NULL;
	return (buff);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	n_subs;
	char			**buff;

	n_subs = ft_count_words(s, c);
	buff = (char **) malloc ((n_subs + 1) * sizeof (char *));
	if (buff == NULL)
		return (NULL);
	return (ft_fillbuff(buff, s, c, n_subs));
}
