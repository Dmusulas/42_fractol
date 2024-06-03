/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:45:11 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/03 21:50:00 by dmusulas         ###   ########.fr       */
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
	{
		free(formatted_set);
		help_msg(fract, ERR_ARGS);
	}
	free(formatted_set);
}

/*
 * @brief This function converts from string representation of HEX to int
 *
 * @param str String to convert to int
 * @return integer
 */
unsigned int	hex_to_int(const char *hexStr)
{
	const char		*p;
	unsigned int	result;

	p = hexStr;
	result = 0;
	if (*p == '#')
		p++;
	while (*p)
	{
		result *= 16;
		if (*p >= '0' && *p <= '9')
			result += *p - '0';
		else if (*p >= 'a' && *p <= 'f')
			result += *p - 'a' + 10;
		else if (*p >= 'A' && *p <= 'F')
			result += *p - 'A' + 10;
		else
			return (0);
		p++;
	}
	return (result);
}

double	ft_stod(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			fraction *= 0.1;
			result += (*str++ - '0') * fraction;
		}
	}
	return (sign * result);
}

t_fractol	*init_fractol(char *argv[])
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	get_fractal_set(argv[1], f);
	if (f->set == 0 && argv[2])
		f->color = hex_to_int(argv[2]);
	else if (f->set == 1 && argv[4])
		f->color = hex_to_int(argv[4]);
	else
		f->color = 0xab44e3;
	f->zoom = 200;
	f->offset_x = -1.21;
	f->offset_y = -1.21;
	if (f->set == 1 && argv[2] && argv[3])
	{
		f->cx = ft_stod(argv[2]);
		f->cy = ft_stod(argv[3]);
	}
	return (f);
}
