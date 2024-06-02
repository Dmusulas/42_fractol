/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:56:28 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/02 17:38:10 by dmusulas         ###   ########.fr       */
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
void	error(void)
{
	perror(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	destroy_fractol(int exit_status, t_fractol *f)
{
	if (!f)
		exit(exit_status);
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
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
	ft_putendl_fd("\t1. mandelbrot", 1);
	ft_putendl_fd("\t2. julia", 1);
	destroy_fractol(EXIT_FAILURE, f);
}
