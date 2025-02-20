/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:55 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/20 22:51:12 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_pixel_put(t_img *img, int x, int y, int color)
{
    int offset;
    
    //img img_pxl_ptr hold a buffer to a structer taht contain img data 
    offset = (img->line_len * y) + (x * (img->b_p_p / 8));
    *((unsigned int *)(img->img_pxl_ptr + offset)) = color;//pxl ptr is pointer to the first ixel in windeow
    // else
    //     *((unsigned int *)(img->img_pxl_ptr + offset)) = 0xffffff;
}
int malderbort(t_fifi *data, int x, int y, int color)
{
    int j = 0;
    t_complex z;
    t_complex c;
    double tmp;
    double min_real = -2, max_real = 2;
    double min_imag = -2, max_imag = 2.5;

    data->max_it = 50;
    c.real = map(x, min_real, max_real, WEIDTH);
    c.i = map(y, min_imag, max_imag, HEIGTH);
    //initialisation de z (0,0)
    z.real = 0;
    z.i = 0;
    while(j < data->max_it)//i < 50 && (z.i < 2 && z.r < 2)
    {
        //z = z^2 + c
        // Compute Z^2 + C
        tmp = z.real * z.real - z.i * z.i + c.real;
        z.i = 2 * z.real * z.i + c.i;
        z.real = tmp;

        if((z.real * z.real) + (z.i * z.i) > 4.0)//|z|  > 2
            break;
        j++;
    }
    if (j >= data->max_it)
        my_pixel_put(&data->img, x, y, color);
    else
        my_pixel_put(&data->img, x, y, map(j, 0xffffff, 0x000000, data->max_it));
    return(0);

}


void color_screen(t_fifi *data, int color)
{
    int y = 0;
    int x = 0;
    while(y < HEIGTH)
    {
        x = 0;
        while(x < WEIDTH)
        {
            malderbort(data, x, y, color);
            x++;
        }
        y++;
    }
}

int press_mouse(int ButtonPress, t_fifi *data)
{
    
}
//keysym??
int press_key(int keysym, t_fifi *data)
{
    if(keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    else if (keysym == XK_r)
    {
        color_screen(data, 0xff0000);
    }
    else if(keysym == XK_g)
    {
        color_screen(data, 0x00ff00);
    }
    else if (keysym == XK_b)
    {
        color_screen(data, 0x0000ff);
    }
    else if (keysym == XK_plus)
    {
        data->max_it += 10;
    }
    else if (keysym == XK_minus)
    {
        data->max_it -= 10;
    }
    else if (keysym == XK_Left)
    {
        data->shift_x += 0.5;
    }
    else if (keysym == XK_Right)
    {
        data->shift_x -= 0.5;
    }
    else if (keysym == XK_Up)
    {
        data->shift_y += 0.5;
    }
    else if (keysym == XK_Down)
    {
        data->shift_x -= 0.5;
    }
    
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
    return (0);
}
void hooks_init(t_fifi *data)
{
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
    mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, press_mouse, data);
    mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, press_x, data);

}

// double map_x(double px)
// {
//     return (-2 + px * ())
// }

int main(int ac, char *av[])
{
    
    int funct;
    funct = parcing(ac, av);
    funct = funct;
    t_fifi data;
    
    data.mlx_ptr = mlx_init();//function create a struct T_XVAR and return its adress (it allocate the pointer)
	if(!data.mlx_ptr)
		return(1);

	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 600, "noussa");
    //mlx_win pointer ??
    
	if(!data.mlx_win)
	{
        mlx_destroy_window(data.mlx_ptr, data.mlx_win);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return(1);
	}

    data.img.img_ptr = mlx_new_image(data.mlx_ptr, 800, 800);
    data.img.img_pxl_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.b_p_p, &data.img.line_len, &data.img.endian);
    // img.img_pixels_ptr = pointer to the first pixel of the window
    
    
    
    mlx_key_hook(data.mlx_win, press_key, &data);
    mlx_key_hook(data.mlx_win, press_mouse, &data);
    
	mlx_loop(data.mlx_ptr);


	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
    //creating a window.
    //parcing
    //asc exit

}
