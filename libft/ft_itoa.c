/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:36:26 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/03/30 03:30:54 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_aux_count_digits(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*buff;
	long int	nbr;
	int			len;

	nbr = (long int) n;
	if (nbr < 0)
		nbr = -nbr;
	len = ft_aux_count_digits(nbr);
	if (n < 0)
		len = len + 1;
	buff = malloc(len * sizeof (char) + 1);
	if (buff == NULL)
		return (NULL);
	*(buff + len--) = '\0';
	if (n == 0)
		*buff = '0';
	while (nbr)
	{
		*(buff + len--) = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		buff[0] = '-';
	return (buff);
}
