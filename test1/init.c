/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:39:16 by nel-khad          #+#    #+#             */
/*   Updated: 2025/03/03 00:36:16 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(t_fifi *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}

void	data_init(t_fifi *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx_ptr, 600, 600, "noussa");
	if (!data->mlx_win)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, 800, 800);
	if (!data->img.img_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	color_screen(data, 0x000000);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
}

void	color_screen(t_fifi *data, int color)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WEIDTH)
		{
			if (data->func == 1)
				malderbort(data, x, y, color);
			else if (data->func == 3)
				julia(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_is_not_dig(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '.' && *s != '-')
			return (1);
		s++;
	}
	return (0);
}
