/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:34:10 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/09 15:52:32 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_args		args;

	if (argv)
		;
	if (!ft_arguments_parsing(&args, argc, argv))
		return (0);
	if (!ft_init_fractal(&fractal, args.fractal_set, args.julia_cr, \
		args.julia_ci))
		return (1);
	if (ft_mlx_init(&fractal) < 0)
		exit (1);
	ft_draw_fractal(&fractal, 1);
	ft_print_commands_help();
	mlx_hook(fractal.window, ON_DESTROY, 0, ft_window_close_handler, &fractal);
	mlx_key_hook(fractal.window, ft_key_event_handler, &fractal);
	mlx_mouse_hook(fractal.window, ft_mouse_event_handler, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}

int	ft_close_fractol(int key, t_fractal *fractal)
{
	if (key)
		;
	mlx_destroy_image(fractal->mlx, fractal->image);
	fractal->image = NULL;
	mlx_destroy_window(fractal->mlx, fractal->window);
	fractal->window = NULL;
	mlx_loop_end(fractal->mlx);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	fractal->mlx = NULL;
	ft_mem_free((void **) fractal->values, WIDTH);
	exit (0);
}
int	ft_cantar_evento(int key, t_fractal *fractal)
{
	if (fractal)
		;
	ft_printf("Tecla: %d\n", key);
	return (0);
}