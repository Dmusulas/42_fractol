/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:07:14 by dmusulas          #+#    #+#             */
/*   Updated: 2024/05/31 17:07:14 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"

/**
 * Computes the color of a pixel for the Mandelbrot set visualization.
 *
 * This function determines whether a point (cx, cy)
 * in the complex plane belongs to the Mandelbrot set
 * by iterating the function zn+1 = zn^2 + c.
 * The color of the pixel is determined based on the number
 * of iterations it takes for the magnitude of z to exceed a specified limit.
 *
 * @param f A pointer to the t_fractol structure containing
 * the image data and parameters.
 */
void	calculate_mandelbrot(t_fractol *f)
{
	int		i;
	double	x_temp;
	double	zx2;
	double	zy2;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	while (++i < MAX_ITERATIONS)
	{
		zx2 = f->zx * f->zx;
		zy2 = f->zy * f->zy;
		if (zx2 + zy2 >= DBL_MAX)
			break ;
		x_temp = zx2 - zy2 + f->cx;
		f->zy = 2.0 * f->zx * f->zy + f->cy;
		f->zx = x_temp;
	}
	if (i == MAX_ITERATIONS)
		draw_pixel(f, 0x000000);
	else
		draw_pixel(f, (f->color * i));
}

void	calculate_julia(t_fractol *f)
{
	int		i;
	double	temp;
	double	zx2;
	double	zy2;

	i = 0;
	f->zx = (f->x / f->zoom) + f->offset_x;
	f->zy = (f->y / f->zoom) + f->offset_y;
	while (++i < MAX_ITERATIONS)
	{
		zx2 = f->zx * f->zx;
		zy2 = f->zy * f->zy;
		temp = zx2 - zy2;
		f->zy = 2.0 * f->zy * f->zx + f->cy;
		f->zx = temp + f->cx;
		if (zx2 + zy2 >= DBL_MAX)
			break ;
	}
	if (i == MAX_ITERATIONS)
		draw_pixel(f, 0x000000);
	else
		draw_pixel(f, (f->color * i));
}

int	draw_image(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < WIDTH)
	{
		while (f->y < HEIGHT)
		{
			if (f->set == 0)
				calculate_mandelbrot(f);
			if (f->set == 1)
				calculate_julia(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	return (0);
}
