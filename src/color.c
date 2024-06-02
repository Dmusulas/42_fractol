/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:29:07 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/02 19:29:07 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdint.h>

/**
 * @brief Splits a 32-bit integer color into its RGBA components.
 *
 * This function takes a 32-bit integer representing a color in the format
 * 0xRRGGBBAA and splits it into its red, green, blue, and alpha components.
 * This is done using bit-shifting and bitwise AND both of them mask other
 * parts of color and only leave necessary part.
 *
 */

/**
 * @brief  Draws a pixel with the specified color at the current
 * coordinates.
 *
 * This function sets the pixel at the coordinates specified by `f->x` and
 * `f->y` in the image referenced by `f->img` to the given color. The color
 * is split into its RGBA components before being assigned to the pixel.
 * We can get pixel by offset because all pixels are stored in row-major order
 * meaning all pixels in row N are stored consequently. We multiple by 4 because
 * that's the size of 4 bytes (32-bit system).
 *
 * @param f A pointer to the t_fractol structure containing
 * the image and coordinates.
 * @param color A 32-bit integer representing the color to set the pixel to.
 */
void	draw_pixel(t_fractol *f, int color)
{
	uint8_t	*pixel;

	pixel = &f->img->pixels[(f->y * f->img->width + f->x) * 4];
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}
