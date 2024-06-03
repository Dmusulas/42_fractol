/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:06:20 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/03 21:17:54 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	*f;

	f = init_fractol(argv);
	if (argc <= 2)
		help_msg(f, ERR_ARGS);
	mlx_set_setting(MLX_MAXIMIZED, true);
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!f->mlx)
		error(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		error(f);
	draw_image(f);
	mlx_scroll_hook(f->mlx, scroll_callback, f);
	mlx_key_hook(f->mlx, key_callback, f);
	mlx_loop(f->mlx);
	destroy_fractol(EXIT_SUCCESS, f);
	return (EXIT_SUCCESS);
}
