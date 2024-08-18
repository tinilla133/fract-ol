/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:19:55 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 19:04:55 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		All these functions return the value of iteration on which series for 
 *		different Julia sets reaches divergence condition. If this condition 
 *		is not reached, return SERIES_TERMS.
 */

int	ft_julia(t_fractal fractal, double x, double y)
{
	int		i;
	double	zr;
	double	zi;
	double	zr_aux;

	i = 0;
	zr = x;
	zi = y;
	while (i < fractal.series_terms)
	{
		if (sqrt(zr * zr + zi * zi) > 2)
			return (i);
		zr_aux = zr;
		zr = zr * zr - zi * zi + fractal.zro;
		zi = (2 * zr_aux * zi) + fractal.zio;
		i++;
	}
	return (i);
}

int	ft_julia_three(t_fractal fractal, double x, double y)
{
	int		i;
	double	zr;
	double	zi;
	double	zr_aux;

	i = 0;
	zr = x;
	zi = y;
	while (i < fractal.series_terms)
	{
		if (zr * zr + zi * zi > 4)
			return (i);
		zr_aux = zr;
		zr = zr * zr * zr - 3 * zr * zi * zi + fractal.zro;
		zi = 3 * zr_aux * zr_aux * zi - zi * zi * zi + fractal.zio;
		i++;
	}
	return (i);
}

int	ft_julia_four(t_fractal fractal, double x, double y)
{
	int		i;
	double	zr;
	double	zi;
	double	zr_aux;

	i = 0;
	zr = x;
	zi = y;
	while (i < fractal.series_terms)
	{
		if (zr * zr + zi * zi > 4)
			return (i);
		zr_aux = zr;
		zr = ft_pow(zr, 4) + ft_pow(zi, 4) - 6 * zr * zr * zi * zi + \
			fractal.zro;
		zi = 4 * (ft_pow(zr_aux, 3) * zi - (ft_pow(zi, 3) * zr_aux)) + \
			fractal.zio;
		i++;
	}
	return (i);
}
