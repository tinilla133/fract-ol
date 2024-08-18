/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:05:30 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/22 14:08:07 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_pow(double base, int exponent)
{
	double	pow;

	pow = 1;
	while (exponent--)
		pow *= base;
	return (pow);
}