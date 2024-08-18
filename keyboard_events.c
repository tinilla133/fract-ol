/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:59:42 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/09 16:07:43 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Handler for keyboard events.
 */

int	ft_key_event_handler(int key, t_fractal *fractal)
{
	if (key == KEY_ESC)
		ft_close_fractol(key, fractal);
	else if (key == KEY_W || key == KEY_ARR_U)
		ft_move_fractal(fractal, 'U', MOVE_STEP);
	else if (key == KEY_A || key == KEY_ARR_L)
		ft_move_fractal(fractal, 'L', MOVE_STEP);
	else if (key == KEY_D || key == KEY_ARR_R)
		ft_move_fractal(fractal, 'R', MOVE_STEP);
	else if (key == KEY_S || key == KEY_ARR_D)
		ft_move_fractal(fractal, 'D', MOVE_STEP);
	else if (key == KEY_PLUS || key == KEY_PLUS_TK)
		ft_zoom_fractal(fractal, 'I');
	else if (key == KEY_MINUS || key == KEY_MINUS_TK)
		ft_zoom_fractal(fractal, 'O');
	else if (key == KEY_SPC)
		ft_change_fractal_color(fractal);
	else if (key == KEY_BACK)
		ft_change_palette_steepness(fractal);
	ft_key_event_handler_ext(key, fractal);
	return (0);
}

/*
 *	Calls needed functions depending on int key parameter,
 *	corresponding to a keyboard event.
 */

int	ft_key_event_handler_ext(int key, t_fractal *fractal)
{
	if (key == KEY_W || key == KEY_ARR_U || key == KEY_A || key == KEY_ARR_L || \
		key == KEY_D || key == KEY_ARR_R || key == KEY_S || key == KEY_ARR_D || \
		key == KEY_PLUS || key == KEY_PLUS_TK || key == KEY_MINUS || \
		key == KEY_MINUS_TK)
		ft_draw_fractal(fractal, 1);
	else if (key == KEY_SPC || key == KEY_BACK)
		ft_draw_fractal(fractal, 0);
	else if (key == KEY_TAB)
		ft_change_fractal_set(fractal);
	return (0);
}
