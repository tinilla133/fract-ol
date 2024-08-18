/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:40:35 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/18 20:57:07 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *		To compile higer order SETS (Multibrot 4th and 5th and Julia 5th), 
 *		set #define _HIGH_ORDER_ C preprocessor directive.
 */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include "minilibx_linux/mlx.h"

# define SERIES_TERMS 55
# define WIDTH 800
# define HEIGHT 800

# define KEY_ESC 65307
# define KEY_SPC 32
# define KEY_TAB 65289
# define KEY_BACK 65288
# define KEY_ARR_U 65362
# define KEY_ARR_L 65361
# define KEY_ARR_R 65363
# define KEY_ARR_D 65364
# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_PLUS_TK 65451
# define KEY_PLUS 43
# define KEY_MINUS_TK 65453
# define KEY_MINUS 45
# define MOUSE_WHEEL_U 4
# define MOUSE_WHEEL_D 5
# define ON_DESTROY 17
# define ON_RESIZE 25

# define MOVE_STEP .05
# define ZOOM_STEP .5

# define WHITE 0xffffff
# define BLACK 0X0
# define RED 0xcc0000
# define ORANGE 0xff8200
# define YELLOW 0xfff000
# define PINK 0xd81a8a
# define GREEN 0x008331
# define BLUE 0x0092ff
# define PURPLE 0xad76e0
# define COLOR_STEP 0xBBB
# define COLOR_STEP_SOFT 0x66
# define PALETTE_MAX_SIZE 256
# define PALETTE_DEFAULT_STEEPNESS 'H'

# define JULIA_CR .285
# define JULIA_CI -.01
# define JULIA_THREE_CR .5
# define JULIA_FOUR_CR .5

typedef enum e_set
{
	mandelbrot,
	julia,
	julia_three,
	julia_four,
	multibrot_three,
	none
}				t_set;

typedef struct s_args
{
	t_set	fractal_set;
	double	julia_cr;
	double	julia_ci;
}				t_args;

typedef struct s_fractal
{
	t_set				set;
	int					series_terms;
	double				zro;
	double				zio;
	double				r_axis_max;
	double				r_axis_min;
	double				i_axis_max;
	double				i_axis_min;
	unsigned int		base_color;
	unsigned int		color_step;
	unsigned int		color_palette[PALETTE_MAX_SIZE];
	char				palette_steepness;
	int					**values;
	char				*buff;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	void				*mlx;
	void				*window;
	void				*image;
}						t_fractal;

int			ft_arguments_parsing(t_args	*args, int argc, char **argv);
t_set		ft_fractal_set_parsing(char *argv);
int			ft_mlx_init(t_fractal *fractal);
t_fractal	*ft_init_fractal(t_fractal *fractal, t_set	set, \
				double cr, double ci);
t_fractal	*ft_init_mandelbrot(t_fractal *fractal, t_set set);
t_fractal	*ft_init_julia(t_fractal *fractal, t_set set, double cr, double ci);
t_fractal	*ft_init_multibrot(t_fractal *fractal, t_set set);
int			**ft_mem_alloc(size_t dim1, size_t dim2);
void		ft_mem_free(void **mem, size_t dim1);
void		ft_set_pixel_color(t_fractal *fractal, int x, int y, int color);
void		ft_create_color_palette(unsigned int *color_palette, int size, \
				int start, char type);
void		ft_fill_color_palette_soft(unsigned int *color_palette, int size, \
							int start);
void		ft_fill_color_palette_hard(unsigned int *color_palette, int size, \
							int start);
void		ft_calculate_fractal(t_fractal *fractal);
void		ft_set_fractal_values(t_fractal *fractal, \
								int (*f)(t_fractal, double, double));
void		ft_set_fractal_colors(t_fractal *fractal, int x, int y);
void		ft_draw_fractal(t_fractal *fractal, int calculate);
int			ft_redraw_fractal(t_fractal *fractal);
void		ft_change_fractal_color(t_fractal *fractal);
void		ft_change_fractal_set(t_fractal *fractal);
void		ft_change_palette_steepness(t_fractal *fractal);
int			ft_mandelbrot(t_fractal fractal, double x, double y);
int			ft_multibrot_three(t_fractal fractal, double x, double y);
int			ft_julia(t_fractal fractal, double x, double y);
int			ft_julia_three(t_fractal fractal, double x, double y);
int			ft_julia_four(t_fractal fractal, double x, double y);
void		ft_get_julia_init(t_args *args, int argc, char **argv);
void		ft_set_julia_defaults(t_args *args);
int			ft_key_event_handler(int key, t_fractal *fractal);
int			ft_key_event_handler_ext(int key, t_fractal *fractal);
int			ft_mouse_event_handler(int key, int x, int y, t_fractal *fractal);
int			ft_window_event_handler(t_fractal *fractal);
void		ft_move_fractal(t_fractal *fractal, char where_to, \
				double displacement);
void		ft_zoom_fractal(t_fractal *fractal, char direction);
int			ft_window_close_handler(t_fractal *fractal);
int			ft_close_fractol(int key, t_fractal *fractal);
void		ft_print_short_help(void);
void		ft_print_full_help(void);
void		ft_print_commands_help(void);
double		ft_pow(double base, int exponent);

#endif