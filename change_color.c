/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:50:54 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/09 16:05:56 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Procedure. Change set base color of a set and creates new color palette 
 * 		by calling ft_create_color_palette(...) based on that color.
 */

void	ft_change_fractal_color(t_fractal *fractal)
{
	if (fractal->base_color == BLACK)
		fractal->base_color = RED;
	else if (fractal->base_color == RED)
		fractal->base_color = ORANGE;
	else if (fractal->base_color == ORANGE)
		fractal->base_color = YELLOW;
	else if (fractal->base_color == YELLOW)
		fractal->base_color = PINK;
	else if (fractal->base_color == PINK)
		fractal->base_color = GREEN;
	else if (fractal->base_color == GREEN)
		fractal->base_color = BLUE;
	else if (fractal->base_color == BLUE)
		fractal->base_color = PURPLE;
	else if (fractal->base_color == PURPLE)
		fractal->base_color = BLACK;
	ft_create_color_palette(fractal->color_palette, PALETTE_MAX_SIZE, \
		fractal->base_color, fractal->palette_steepness);
}
/*
 *		Procedure. Changes de "character" of color palette.
 */

void	ft_change_palette_steepness(t_fractal *fractal)
{
	if (fractal->palette_steepness == 'H')
		fractal->palette_steepness = 'S';
	else
		fractal->palette_steepness = 'H';
	ft_create_color_palette(fractal->color_palette, PALETTE_MAX_SIZE, \
		fractal->base_color, fractal->palette_steepness);
}


