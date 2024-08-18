/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:28:28 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/09 16:04:48 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Parses arguments from command line establishing the main flow  of program.
 *		Returns 0 if arguments are invalid or 1 otherwise.
 */

int	ft_arguments_parsing(t_args	*args, int argc, char **argv)
{
	args->fractal_set = none;
	
	if (argc < 2)
		return (ft_print_short_help(), 0);
	if (ft_strcmp(argv[1], "--help") && ft_strcmp(argv[1], "-h") && \
		ft_strcmp(argv[1], "--fractal") && ft_strcmp(argv[1], "-f"))
		return (ft_print_short_help(), 0);
	if (!ft_strcmp(argv[1], "--help") || !ft_strcmp(argv[1], "-h"))
		return (ft_print_full_help(), 0);
	if ((!ft_strcmp(argv[1], "--fractal") || !ft_strcmp(argv[1], "-f")) && \
		argc < 3)
		return (ft_print_short_help(), 0);
	if (argv[2])
		args->fractal_set = ft_fractal_set_parsing(argv[2]);
	if (args->fractal_set >= julia && args->fractal_set <= julia_four)
		ft_get_julia_init(args, argc, argv);
	if (args->fractal_set == none)
	{
		ft_printf("Please, specify a valid fractal set.\n");
		ft_print_short_help();
		return (0);
	}
	return (1);
}

/*
 *		Parses arguments from command line and returns the tupe of fractal 
 *		set in a enum of type t_set.
 */

t_set	ft_fractal_set_parsing(char *argv)
{
	if (!argv)
		return (none);
	if (!ft_strcmp(argv, "m"))
		return (mandelbrot);
	if (!ft_strcmp(argv, "j"))
		return (julia);
	if (!ft_strcmp(argv, "j3"))
		return (julia_three);
	if (!ft_strcmp(argv, "j4"))
		return (julia_four);
	if (!ft_strcmp(argv, "mt3"))
		return (multibrot_three);
	return (none);
}

/*
 *		Procedure. Parses Julia set init values from command line to 
 *		t_args args struct members julia_cr and julia_ci.
 */

void	ft_get_julia_init(t_args *args, int argc, char **argv)
{
	if (argc < 4)
	{
		ft_printf("No coeficients for Julia. Using defaults.\n");
		ft_printf("Use --help for help.\n");
		ft_set_julia_defaults(args);
	}
	else
	{
		args->julia_cr = ft_atof(argv[3]);
		if (argc >= 5)
			args->julia_ci = ft_atof(argv[4]);
		else
			args->julia_ci = 0;
	}
}

/*
 *		Procedure. Set Julia init values in case of none are provided by 
 *		user through command line.
 */

void	ft_set_julia_defaults(t_args *args)
{
	if (args->fractal_set == julia)
	{
		args->julia_cr = JULIA_CR;
		args->julia_ci = JULIA_CI;
	}
	else if (args->fractal_set == julia_three)
	{
		args->julia_cr = JULIA_THREE_CR;
		args->julia_ci = 0;
	}
	else if (args->fractal_set == julia_four)
	{
		args->julia_cr = JULIA_FOUR_CR;
		args->julia_ci = 0;
	}
}
