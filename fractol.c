/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:55 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/26 21:47:20 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fifi *data, int x, int y, int color)
{
	int			j;
	t_complex	z;
	t_complex	c;
	double		tmp;

	j = 0;
	c.real = data->j_x;
	c.i = data->j_y;
	z.real = (map_x(x, data) * data->zoom) + data->shift_x;
	z.i = (map_y(y, data) * data->zoom) + data->shift_y;
	while (j < data->max_it) // i < 50 && (z.i < 2 && z.r < 2)
	{
		tmp = z.real * z.real - z.i * z.i + c.real;
		z.i = 2 * z.real * z.i + c.i;
		z.real = tmp;
		if ((z.real * z.real) + (z.i * z.i) > 4.0) //|z|  > 2
			break ;
		j++;
	}
	if (j == data->max_it)
		my_pixel_put(&data->img, x, y, color);
	else
		my_pixel_put(&data->img, x, y, map_col(j, 0xffffff, 0x000000,
				data->max_it));
	return ;
}

int	malderbort(t_fifi *data, int x, int y, int color)
{
	int			j;
	t_complex	z;
	t_complex	c;
	double		tmp;

	j = 0;
	c.real = (map_x(x, data) * data->zoom) + data->shift_x;
	c.i = (map_y(y, data) * data->zoom) + data->shift_y;
	z.real = 0;
	z.i = 0;
	while (j < data->max_it) // i < 50 && (z.i < 2 && z.r < 2)
	{
		tmp = z.real * z.real - z.i * z.i + c.real;
		z.i = 2 * z.real * z.i + c.i;
		z.real = tmp;
		if ((z.real * z.real) + (z.i * z.i) > 4.0) //|z|  > 2
			break ;
		j++;
	}
	if (j == data->max_it)
		my_pixel_put(&data->img, x, y, color);
	else
		my_pixel_put(&data->img, x, y, map_col(j, 0x000000, 0xffffff,
				data->max_it));
	return (0);
}

void	hooks_init(t_fifi *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
	mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, press_mouse, data);
	mlx_hook(data->mlx_win, 17, 0, press_x, data);//17 0
}

int	main(int ac, char *av[])
{
	t_fifi	data;

	reset(&data);
	data.func = parcing(ac, av);
	if (data.func == 3)
	{
		data.j_x = ft_atoi(av[2]);
		data.j_y = ft_atoi(av[3]);
	}
	data_init(&data);
	hooks_init(&data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
