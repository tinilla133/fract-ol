/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:35:19 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 17:49:01 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	integer;
	double	fraction;
	double	nbr;
	int		len;
	int		sign;

	sign = 0;
	if (*str && *str == '-')
		sign = 1;
	integer = (double) ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	fraction = (double) ft_atoi(str);
	len = ft_strlen(str);
	while (len--)
		fraction /= 10;
	if (integer >= 0)
		nbr = integer + fraction;
	else
		nbr = integer - fraction;
	if (!integer && sign)
		nbr = -nbr;
	return (nbr);
}
