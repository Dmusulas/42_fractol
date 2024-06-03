/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:56:46 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/03 21:17:07 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <float.h>
# include <math.h>
# include "MLX42/MLX42.h"
# define ERR_MALLOC "[ERROR] Memory allocation error"
# define ERR_ARGS "[ERROR] Wrong input provided"
# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITERATIONS 50 
# define CENTER_X WIDTH / 2.0
# define CENTER_Y HEIGHT / 2.0

typedef struct s_fractol
{
	mlx_t	*mlx;
	void	*win;
	mlx_image_t	*img;
	char	*buf;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		set;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		color;
}	t_fractol;

void		error(t_fractol *f);
void		help_msg(t_fractol *f, char *err);
t_fractol	*init_fractol(char *argv[]);
void		destroy_fractol(int exit_status, t_fractol *f);
void		calculate_mandelbrot(t_fractol *f);
int			draw_image(t_fractol *f);
void		draw_pixel(t_fractol *f, int color);
void		scroll_callback(double xoffset, double yoffset, void *param);
void		key_callback(mlx_key_data_t key_data, void *param);
void		move_image(t_fractol *f, double dx, double dy);
void		zoom(t_fractol *f, double zoom_factor, double mouse_x, double mouse_y);
#endif
