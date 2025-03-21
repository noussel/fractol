/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:00:31 by nel-khad          #+#    #+#             */
/*   Updated: 2025/03/03 15:13:15 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_error(void)
{
	ft_putstr_fd("invalid arguments\n", 2);
	ft_putstr_fd("=> ./fractol <mandelbrot>\n", 2);
	ft_putstr_fd("=> ./fractol <julia> <Im> <Re>\n", 2);
	exit(EXIT_FAILURE);
}

int	parcing(int ac, char *av[])
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbort", 11) == 0)
		return (1);
	else if (ac == 2 && ft_strncmp(av[1], "burningship", 12) == 0)
		return (2);
	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		if ((ft_atoi(av[2]) < -1 || ft_atoi(av[2]) > 1) || (ft_atoi(av[3]) < -1
				|| ft_atoi(av[3]) > 1) || ft_is_not_dig(av[2])
			|| ft_is_not_dig(av[3]))
		{
			ft_putstr_fd("<Re> and <Im> invalid", 2);
			exit(1);
		}
		else
			return (3);
	}
	put_error();
	return (-1);
}

double	map_x(int px, t_fifi *data)
{
	return (data->min_real + px * (data->max_real - data->min_real) / WEIDTH);
}

double	map_col(int px, double min_real, double max_real, int size)
{
	return (min_real + px * ((max_real - min_real) / size));
}

double	map_y(int py, t_fifi *data)
{
	return (data->max_img - py * (data->max_img - data->min_img) / HEIGHT);
}
