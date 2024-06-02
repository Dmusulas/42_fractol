/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:35:30 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/02 20:35:30 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Adjusts the zoom level and redraws the Mandelbrot set.
 *
 * This function zooms in or out at the given mouse position,
	adjusting the offsets
 * to ensure that the point under the mouse remains stationary.
 *

	* @param f A pointer to the t_fractol structure containing the image data and parameters.
 * @param zoom_factor The factor by which to zoom in or out.
 * @param mouse_x The x-coordinate of the mouse position.
 * @param mouse_y The y-coordinate of the mouse position.
 */
void	zoom(t_fractol *f, double zoom_factor, double mouse_x, double mouse_y)
{
	double	new_zoom;

	new_zoom = f->zoom * zoom_factor;
	f->offset_x = f->offset_x + (mouse_x / f->zoom - mouse_x / new_zoom);
	f->offset_y = f->offset_y + (mouse_y / f->zoom - mouse_y / new_zoom);
	f->zoom = new_zoom;
	draw_image(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}

void	move_image(t_fractol *f, double dx, double dy)
{
	f->offset_x += dx / f->zoom;
	f->offset_y += dy / f->zoom;
	draw_image(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
