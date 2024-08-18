/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:18:35 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 15:43:37 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Procedure. Changes fractal set and redraws it on window.
 */

void	ft_change_fractal_set(t_fractal *fractal)
{
	if (fractal->set == multibrot_three)
		fractal->set = mandelbrot;
	else
		fractal->set++;
	if (fractal->set == mandelbrot)
		ft_init_mandelbrot(fractal, fractal->set);
	else if (fractal->set == julia)
		ft_init_julia(fractal, fractal->set, JULIA_CR, JULIA_CI);
	else if (fractal->set == julia_three)
		ft_init_julia(fractal, fractal->set, JULIA_THREE_CR, 0);
	else if (fractal->set == julia_four)
		ft_init_julia(fractal, fractal->set, JULIA_FOUR_CR, 0);
	else if (fractal->set == multibrot_three)
		ft_init_multibrot(fractal, fractal->set);
	ft_draw_fractal(fractal, 1);
}
