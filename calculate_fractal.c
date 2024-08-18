/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:59:54 by tinilla           #+#    #+#             */
/*   Updated: 2024/08/08 15:46:49 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Procedure. Calculates fractal values depending on the set selected.
 *		Calls to ft_set_fractal_values(...) in order to do this.
 */

void	ft_calculate_fractal(t_fractal *fractal)
{
	if (fractal->set == mandelbrot)
		ft_set_fractal_values(fractal, ft_mandelbrot);
	else if (fractal->set == julia)
		ft_set_fractal_values(fractal, ft_julia);
	else if (fractal->set == julia_three)
		ft_set_fractal_values(fractal, ft_julia_three);
	else if (fractal->set == julia_four)
		ft_set_fractal_values(fractal, ft_julia_four);
	else if (fractal->set == multibrot_three)
		ft_set_fractal_values(fractal, ft_multibrot_three);
}

/*
 *		Procedure. Stores values in each position of matrix values[][], 
 *		which is a member of t_fractal (struct) fractal. For this task, 
 *		uses a function specific for each set that receives as parameter 
 *		(*f)(t_fractal, double, double).
 */

void	ft_set_fractal_values(t_fractal *fractal, \
								int (*f)(t_fractal, double, double))
{
	int		x;
	int		y;
	double	x_mapped;
	double	y_mapped;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x_mapped = fractal->r_axis_min + y * \
				(fractal->r_axis_max - fractal->r_axis_min) / WIDTH;
			y_mapped = fractal->i_axis_max + x * \
				(fractal->i_axis_min - fractal->i_axis_max) / HEIGHT;
			fractal->values[x][y] = f(*fractal, x_mapped, y_mapped);
			y++;
		}
		x++;
	}
}

