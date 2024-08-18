/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_z_factor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:58:10 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/07/19 20:47:55 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Procedure. Moves fractal in direction char where_to, double displacement 
 *		quantity, by adjusting the extreme values of axis.
 */

void	ft_move_fractal(t_fractal *fractal, char where_to, double displacement)
{
	double	r_mid;
	double	i_mid;

	r_mid = fractal->r_axis_max - fractal->r_axis_min;
	i_mid = fractal->i_axis_max - fractal->i_axis_min;
	if (where_to == 'U')
	{
		fractal->i_axis_min -= i_mid * displacement;
		fractal->i_axis_max -= i_mid * displacement;
	}
	else if (where_to == 'L')
	{
		fractal->r_axis_min += r_mid * displacement;
		fractal->r_axis_max += r_mid * displacement;
	}
	else if (where_to == 'R')
	{
		fractal->r_axis_min -= r_mid * displacement;
		fractal->r_axis_max -= r_mid * displacement;
	}
	else if (where_to == 'D')
	{
		fractal->i_axis_min += i_mid * displacement;
		fractal->i_axis_max += i_mid * displacement;
	}
}

/*
 *		Procedure. Zooms fractal in or out, depending on char direction,
 *
 */

void	ft_zoom_fractal(t_fractal *fractal, char direction)
{
	double	r_axis_mid;
	double	i_axis_mid;
	float	z_factor;

	if (direction == 'I')
		z_factor = ZOOM_STEP;
	else
		z_factor = 1 / ZOOM_STEP;
	r_axis_mid = fractal->r_axis_min - fractal->r_axis_max;
	i_axis_mid = fractal->i_axis_max - fractal->i_axis_min;
	fractal->r_axis_max = fractal->r_axis_max + \
		(r_axis_mid - z_factor * r_axis_mid) / 2;
	fractal->r_axis_min = fractal->r_axis_max + z_factor * r_axis_mid;
	fractal->i_axis_min = fractal->i_axis_min + \
		(i_axis_mid - z_factor * i_axis_mid) / 2;
	fractal->i_axis_max = fractal->i_axis_min + z_factor * i_axis_mid;
}


