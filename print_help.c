/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:38:16 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/18 20:41:56 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_short_help(void)
{
	ft_printf("Usage: ./fractol -f <fractal set> [julia_init]\n");
	ft_printf("\tfractal set can be: m, j, j3, j4, mt3\n");
	ft_printf("\tFor a complete list of parameters use ./fractol --help\n");
}

void	ft_print_full_help(void)
{
	ft_printf("Usage: ./fractol -f <fractal> [julia_init]\n");
	ft_printf("Parameters:\n");
	ft_printf("\t-h --help: displays this message.\n");
	ft_printf("\t-f --fractal <set> establishes fractal set.\n");
	ft_printf("\t\tset:\n");
	ft_printf("\t\t\tm : Mandelbrot set.\n");
	ft_printf("\t\t\tj : Julia set.\n");
	ft_printf("\t\t\tj3 : Julia 3rd order set.\n");
	ft_printf("\t\t\tj4 : Julia 4th order set.\n");
	ft_printf("\t\t\tmt3 : Multibrot 3rd order set.\n");
	ft_printf("\t\t\tj, j3 and j4 make you able to choose initial values ");
	ft_printf("for Julia set.\n");
	ft_printf("\t\t\tI. e.: $ ./fractol -f j .285 -.1, where first number ");
	ft_printf("is real component and second, imaginary one.\n");
	ft_printf("\t\t\tIf you only specify a single number, it will be taken ");
	ft_printf("as real and imaginary will be considered zero.\n");
}

void	ft_print_commands_help(void)
{
	ft_printf("WELCOME TO FRAC-OL\n");
	ft_printf("Commands available:\n");
	ft_printf("\tSpace: changes base color set.\n");
	ft_printf("\tBackspace: changes color set, keeping base color.\n");
	ft_printf("\tTAB: changes fractal set.\n");
	ft_printf("\tUse arrows or W, S, A, D to move fractal in window.\n");
	ft_printf("\tUse plus or minus or mouse wheel to zoom in and out.\n");
	ft_printf("ENJOY!\n");
}
