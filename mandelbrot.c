/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:03:45 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 19:29:40 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		All these functions return the value of iteration on which series for 
 *		different Mandelbrot sets reaches divergence condition. If this 
 *		condition is not reached, return SERIES_TERMS.
 */

int	ft_mandelbrot(t_fractal fractal, double x, double y)
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
			return (++i);
		zr_aux = zr;
		zr = zr * zr - zi * zi + x;
		zi = (2 * zr_aux * zi) + y;
		i++;
	}
	return (i);
}
