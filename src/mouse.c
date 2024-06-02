/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:25:47 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/02 20:25:47 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Handles mouse scroll events to zoom in and out of the Mandelbrot set.
 *
 * @param xoffset The amount scrolled horizontally (unused).
 * @param yoffset The amount scrolled vertically.
 * @param param A pointer to the user-defined data,
	which is the t_fractol structure.
 */
void	scroll_callback(double xoffset, double yoffset, void *param)
{
	t_fractol	*f;
	int			mouse_x;
	int			mouse_y;

	(void)xoffset;
	f = (t_fractol *)param;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (yoffset > 0)
		zoom(f, 1.1, mouse_x, mouse_y);
	else if (yoffset < 0)
		zoom(f, 0.9, mouse_x, mouse_y);
}
