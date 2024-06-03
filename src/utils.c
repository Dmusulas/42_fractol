/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:56:28 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/03 22:01:40 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <errno.h>
#include <stdint.h>

/**
 * MLX42 specific error helper, displays error according to mlx_errno
 *
 */
void	error(t_fractol *f)
{
	perror(mlx_strerror(mlx_errno));
	destroy_fractol(EXIT_FAILURE, f);
}

void	destroy_fractol(int exit_status, t_fractol *f)
{
	if (!f)
		exit(exit_status);
	if (f->mlx)
		mlx_terminate(f->mlx);
	if (exit_status)
		exit(exit_status);
}

void	help_msg(t_fractol *f, char *err)
{
	if (err)
	{
		errno = 5;
		perror(err);
	}
	ft_putendl_fd("============== Fract-ol help ===============", 1);
	ft_putendl_fd("Render fractals, usage: ./fractol <name_of_set>", 1);
	ft_putendl_fd("Available fractal options options: ", 1);
	ft_putendl_fd("\t1. mandelbrot args: <color_hex>", 1);
	ft_putendl_fd("\t2. julia args: <const_x> <const_y> <color_hex>", 1);
	ft_putendl_fd("const_x - represents real const part of Julia set", 1);
	ft_putendl_fd("const_y - represents imaginary const part of Julia set", 1);
	ft_putendl_fd("color_hex- color for rendering in hex format,\
		default #AB44E3", 1);
	destroy_fractol(EXIT_FAILURE, f);
}
