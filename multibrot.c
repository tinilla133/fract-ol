/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:23:00 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 19:06:41 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		All these functions return the value of iteration on which series for 
 *		different Multibrot sets reaches divergence condition. If this condition 
 *		is not reached, return SERIES_TERMS.
 */

int	ft_multibrot_three(t_fractal fractal, double x, double y)
{
	int		i;
	double	zr;
	double	zi;
	double	zr_aux;

	i = 0;
	zr = fractal.zro;
	zi = fractal.zio;
	while (i < fractal.series_terms)
	{
		if (zr * zr + zi * zi > 4)
			return (i);
		zr_aux = zr;
		zr = ft_pow(zr, 3) - 3 * zr * zi * zi + x;
		zi = 3 * zr_aux * zr_aux * zi - ft_pow(zi, 3) + y;
		i++;
	}
	return (i);
}

