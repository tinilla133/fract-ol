/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:10:47 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 19:20:24 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Initializes some parameters of t_fractal *fractal it receives as 
 *		parameter. 
 *		Returns pointer to t_fractal fractal received as parameter.
 */


t_fractal	*ft_init_fractal(t_fractal *fractal, t_set	set, \
				double cr, double ci)
{
	fractal->values = ft_mem_alloc(WIDTH, HEIGHT);
	if (fractal->values == NULL)
		return (NULL);
	fractal->base_color = BLACK;
	fractal->color_step = COLOR_STEP;
	fractal->palette_steepness = PALETTE_DEFAULT_STEEPNESS;
	ft_create_color_palette(fractal->color_palette, PALETTE_MAX_SIZE, \
			fractal->base_color, fractal->palette_steepness);
	fractal->mlx = NULL;
	fractal->window = NULL;
	fractal->image = NULL;
	if (set == mandelbrot)
		return (ft_init_mandelbrot(fractal, set));
	else if (set == julia || set == julia_three || set == julia_four)
		return (ft_init_julia(fractal, set, cr, ci));
	else if (set == multibrot_three)
		return (ft_init_multibrot(fractal, set));
	return (NULL);
}

/*
 *		Initializes some particular values required for Mandelbrot set 
 *		of t_fractal *fractal it receives as parameter. 
 *		Returns pointer to t_fractal fractal received as parameter.
 */

t_fractal	*ft_init_mandelbrot(t_fractal *fractal, t_set set)
{
	fractal->series_terms = 100;
	fractal->set = set;
	fractal->zro = 0;
	fractal->zio = 0;
	fractal->r_axis_max = 1;
	fractal->r_axis_min = -2.2;
	fractal->i_axis_max = 1.5;
	fractal->i_axis_min = -1.5;
	return (fractal);
}

/*
 *		Initializes some particular values required for Julia set 
 *		of t_fractal *fractal it receives as parameter. 
 *		Returns pointer to t_fractal fractal received as parameter.
 */

t_fractal	*ft_init_julia(t_fractal *fractal, t_set set, double cr, double ci)
{
	fractal->set = set;
	fractal->zro = cr;
	fractal->zio = ci;
	if (fractal->set == julia_three || fractal->set == julia_four)
	{
		fractal->series_terms = 100;
		fractal->r_axis_max = 1.3;
		fractal->r_axis_min = -1.3;
		fractal->i_axis_max = 1.3;
		fractal->i_axis_min = -1.3;
	}
	else
	{
		fractal->series_terms = 60;
		fractal->r_axis_max = 2;
		fractal->r_axis_min = -2;
		fractal->i_axis_max = 2;
		fractal->i_axis_min = -2;
	}
	return (fractal);
}

/*
 *		Initializes some particular values required for Multibrot set 
 *		of t_fractal *fractal it receives as parameter. 
 *		Returns pointer to t_fractal fractal received as parameter.
 */

t_fractal	*ft_init_multibrot(t_fractal *fractal, t_set set)
{
	fractal->series_terms = 50;
	fractal->set = set;
	fractal->zro = 0;
	fractal->zio = 0;
	fractal->r_axis_max = 1.5;
	fractal->r_axis_min = -1.5;
	fractal->i_axis_max = 1.5;
	fractal->i_axis_min = -1.5;
	return (fractal);
}
