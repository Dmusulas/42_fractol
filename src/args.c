/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:45:11 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/02 17:45:11 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	get_fractal_set(char *set, t_fractol *fract)
{
	char	*formatted_set;

	if (!set || set[0] == '\0')
		help_msg(fract, ERR_ARGS);
	formatted_set = ft_strtrim(set, " ");
	if (!ft_strncmp(formatted_set, "mandelbrot", ft_strlen("mandelbrot")))
		fract->set = 0;
	else if (!ft_strncmp(formatted_set, "julia", ft_strlen("julia")))
		fract->set = 1;
	else
		help_msg(fract, ERR_ARGS);
}

t_fractol	*init_fractol(char *argv[])
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	get_fractal_set(argv[1], f);
	f->color = 0xFCBE11;
	f->zoom = 200;
	f->offset_x = -1.21;
	f->offset_y = -1.21;
	return (f);
}
