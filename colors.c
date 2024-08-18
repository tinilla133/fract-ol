/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:28:39 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/09 15:13:12 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Procedure. Set color received as parameter for pixel x, y of image,
 *	manipulated using char *buff = mlx_get_data_addr(...)
 */

void	ft_set_pixel_color(t_fractal *fractal, int x, int y, int color)
{
	int	pixel;

	pixel = (x * fractal->size_line) + (y * 4);
	if (!fractal->endian)
	{
		fractal->buff[pixel + 0 ] = color & 0xFF;
		fractal->buff[pixel + 1] = color >> 8 & 0xFF;
		fractal->buff[pixel + 2] = color >> 16 & 0XFF;
		fractal->buff[pixel + 3] = color >> 24 & 0xFF;
	}
	else
	{
		fractal->buff[pixel + 0] = color >> 24;
		fractal->buff[pixel + 1] = color >> 16 & 0xFF;
		fractal->buff[pixel + 2] = color >> 8 & 0XFF;
		fractal->buff[pixel + 3] = color & 0xFF;
	}
}

/*
 *	Procedure. Fills an array of integers with 24 bit color codes that 
 *	receives as parameter, using int size as size of array, int start 
 *	as start color, and char type to determine the gradient of palette.
 */

void	ft_create_color_palette(unsigned int *color_palette, int size, \
							int start, char type)
{
	if (type == 'H')
		ft_fill_color_palette_hard(color_palette, size, start);
	else if (type == 'S')
		ft_fill_color_palette_soft(color_palette, size, start);
}

/*
 *	Procedure. Fills an array of integers with 24 bit color codes that 
 *	receives as parameter, using int size as size of array, int start 
 *	as start color with a determined kind of color gradient.
 */

void	ft_fill_color_palette_soft(unsigned int *color_palette, int size, \
							int start)
{
	int			i;
	long int	color;

	i = size - 1;
	while (i >= 0)
	{
		if (i == size)
			color = start;
		if (color > 0xFFFFFF)
			color = start;
		color_palette[i] = (unsigned int) color;
		color += COLOR_STEP_SOFT;
		i--;
	}
}

/*
 *	Procedure. Fills an array of integers with 24 bit color codes that 
 *	receives as parameter, using int size as size of array, int start 
 *	as start color with a determined kind of color gradient.
 */

void	ft_fill_color_palette_hard(unsigned int *color_palette, int size, \
							int start)
{
	int			i;
	long int	color;

	color = 0x0;
	i = size - 1;
	while (i >= 0)
	{
		if (i == size)
			color = start;
		else if (i % 2)
			color += COLOR_STEP;
		else if (i % 3)
			color += 1.5 * COLOR_STEP;
		else if (i % 4)
			color += 2 * COLOR_STEP;
		else if (i % 5)
			color += 2.5 * COLOR_STEP;
		else
			color += 4 * COLOR_STEP;
		if (color > 0xFFFFFF)
			color = start;
		color_palette[i] = (unsigned int) color;
		i--;
	}
}
