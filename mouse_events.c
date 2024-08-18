/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:59:19 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/08 19:32:59 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Handles mouse events.
 */

int	ft_mouse_event_handler(int key, int x, int y, t_fractal *fractal)
{
	double	correction_in;
	double	correction_out;

	correction_in = 1;
	correction_out = -.5;
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (key == MOUSE_WHEEL_U)
	{
		if (fractal->series_terms + 2 < PALETTE_MAX_SIZE)
			fractal->series_terms += 2;
		ft_zoom_fractal(fractal, 'I');
		ft_move_fractal(fractal, 'U', y * correction_in / HEIGHT);
		ft_move_fractal(fractal, 'L', x * correction_in / WIDTH);
	}
	if (key == MOUSE_WHEEL_D)
	{
		if (fractal->series_terms - 2 <= 0)
			fractal->series_terms -= 2;
		ft_zoom_fractal(fractal, 'O');
		ft_move_fractal(fractal, 'U', y * correction_out / HEIGHT);
		ft_move_fractal(fractal, 'L', x * correction_out / WIDTH);
	}
	ft_draw_fractal(fractal, 1);
	return (0);
}
