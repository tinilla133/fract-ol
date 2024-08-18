/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:33:04 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/09 16:08:23 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Initialization of minilibX.
 */

int	ft_mlx_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (-1);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractal->window)
		return (free(fractal->mlx), -2);
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
	{
		(free(fractal->mlx), free(fractal->window));
		return (-3);
	}
	fractal->buff = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel, \
			&fractal->size_line, &fractal->endian);
	return (0);
}

