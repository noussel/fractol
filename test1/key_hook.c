/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:41:01 by nel-khad          #+#    #+#             */
/*   Updated: 2025/03/02 17:55:00 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	press_x(t_fifi *data)
{
	error(data);
	return (0);
}

void	wich_key(int keysym, int *color, t_fifi *data)
{
	if (keysym == XK_p)
		*color = 0xf4c2c2;
	else if (keysym == XK_g)
		*color = 0x00ff00;
	else if (keysym == XK_b)
		*color = 0x000000;
	else if (keysym == XK_KP_Add)
		data->max_it += 10;
	else if (keysym == XK_minus)
		data->max_it -= 10;
	else if (keysym == XK_Left)
		data->shift_x -= data->zoom;
	else if (keysym == XK_Right)
		data->shift_x += data->zoom;
	else if (keysym == XK_Up)
		data->shift_y += data->zoom;
	else if (keysym == XK_Down)
		data->shift_y -= data->zoom;
}

void	reset(t_fifi *data)
{
	data->min_real = -1.5;
	data->max_real = 2.5;
	data->min_img = -3;
	data->max_img = 2;
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 1;
	data->max_it = 50;
}

int	press_key(int keysym, t_fifi *data)
{
	int	color;

	color = 0x000000;
	if (keysym == XK_Escape)
	{
		error(data);
	}
	else if (keysym == XK_r)
	{
		reset(data);
	}
	else
	{
		wich_key(keysym, &color, data);
	}
	color_screen(data, color);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	return (0);
}

int	press_mouse(int button, int x, int y, t_fifi *data)
{
	printf("Mouse: %d at (%d, %d)\n", button, x, y);
	if (button == Button5)
	{
		data->zoom = data->zoom * 0.95;
	}
	else if (button == Button4)
	{
		data->zoom = data->zoom * 1.05;
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WEIDTH, HEIGTH);
	if (!data->img.img_ptr)
	{
		printf("ERROR: mlx_new_image failed\n");
		return (0);
	}
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	color_screen(data, 0x000000);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	return (0);
}
