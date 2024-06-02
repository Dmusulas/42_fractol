/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:34:51 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/02 20:34:51 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Handles key press events to move the image or zoom in and out.
 *
 * @param key The key that was pressed.
 * @param param A pointer to the user-defined data,
	which is the t_fractol structure.
 */
void	key_callback(mlx_key_data_t key_data, void *param)
{
	t_fractol	*f;
	double		center_x;
	double		center_y;

	center_x = WIDTH / 2.0;
	center_y = HEIGHT / 2.0;
	f = (t_fractol *)param;
	if (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
	{
		if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
			move_image(f, 0, -10);
		else if (key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
			move_image(f, 0, 10);
		else if (key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
			move_image(f, -10, 0);
		else if (key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
			move_image(f, 10, 0);
		else if (key_data.key == MLX_KEY_KP_ADD
			|| key_data.key == MLX_KEY_EQUAL)
			zoom(f, 1.1, center_x, center_y);
		else if (key_data.key == MLX_KEY_KP_SUBTRACT
			|| key_data.key == MLX_KEY_MINUS)
			zoom(f, 0.9, center_x, center_y);
	}
}
