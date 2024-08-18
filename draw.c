/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:13:40 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 20:55:28 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Procedure. Draws fractal into  window. If int calculate values not equal
 *		to 0, it will (re)calculate fractal values, otherwise proceed without 
 *		calculation. After this, calls ft_set_fractal_colors(...), to set color
 *		for echa pixel as function of calculated fractal values. 
 */

void	ft_draw_fractal(t_fractal *fractal, int calculate)
{
	int				x;
	int				y;

	if (calculate)
		ft_calculate_fractal(fractal);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ft_set_fractal_colors(fractal, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, \
			fractal->image, 0, 0);
}

/*
 *		Set color for each pixel as function of calculated values 
 *		and some other considerations to get a good looking draw.
 */

void	ft_set_fractal_colors(t_fractal *fractal, int x, int y)
{
	if (fractal->set == julia_three && fractal->values[x][y] < 6)
		ft_set_pixel_color(fractal, x, y, BLACK);
	if (fractal->set == julia_three && fractal->values[x][y] >= 6)
		ft_set_pixel_color(fractal, x, y, \
			fractal->color_palette[fractal->values[x][y]]);
	if (fractal->set != julia_three && fractal->values[x][y] < 10)
		ft_set_pixel_color(fractal, x, y, BLACK);
	if (fractal->values[x][y] == fractal->series_terms)
		ft_set_pixel_color(fractal, x, y, fractal->base_color);
	if (fractal->set != julia_three && fractal->values[x][y] >= 10)
		ft_set_pixel_color(fractal, x, y, \
			fractal->color_palette[fractal->values[x][y]]);
	if (fractal->values[x][y] == fractal->series_terms)
		ft_set_pixel_color(fractal, x, y, fractal->base_color);
}
