/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:55 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/21 14:20:47 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error(t_fifi *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
    mlx_destroy_window(data->mlx_ptr, data->mlx_win);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
}

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

    c.real = map_x(x, data) + data->shift_x;
    c.i = map_y(y, data) + data->shift_y;
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
    if (j == data->max_it)
        my_pixel_put(&data->img, x, y, color);
    else
        my_pixel_put(&data->img, x, y, map_col(j, 0xffffff, 0x000000, data->max_it));
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
    // mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
}

int press_mouse(int button)
{
    printf("%d", button);
    return 0;
}
int press_x(t_fifi *data)
{
    error(data);
    return (0);
}

//keysym??
int press_key(int keysym, t_fifi *data)
{
    if(keysym == XK_Escape)
    {
        error(data);
    }
    else if(keysym == XK_r)
    {
        // reset
        data->min_real = -2;
        data->max_real = 2;
        data->min_img = -2, 
        data->max_img = 2.5;
        data->shift_x = 0;
        data->shift_y = 0;
        data->max_it = 50;
        
    }
    else if (keysym == XK_p)
    {
        color_screen(data, 0xff0000);
        return 0;
    }
    else if(keysym == XK_g)
    {
        color_screen(data, 0x00ff00);
    }
    else if (keysym == XK_b)
    {
        color_screen(data, 0x0000ff);
    }
    else if (keysym == XK_plus || keysym == XK_KP_Add)
    {
        data->max_it += 10;
    }
    else if (keysym == XK_minus)
    {
        data->max_it -= 10;
    }
    else if (keysym == XK_Left)
    {
        data->shift_x -= 0.5;
    }
    else if (keysym == XK_Right)
    {
        data->shift_x += 0.5;
    }
    else if (keysym == XK_Up)
    {
        data->shift_y += 0.5;
    }
    else if (keysym == XK_Down)
    {
        data->shift_y -= 0.5;
    }
    mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
    data->img.img_ptr = mlx_new_image(data->mlx_ptr, 800, 800);
    data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.b_p_p, &data->img.line_len, &data->img.endian);
    color_screen(data, 0x000000);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
    return (0);
}
void hooks_init(t_fifi *data)
{
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
    mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, press_mouse, data);
    mlx_hook(data->mlx_win, 17, 0, press_x, data);

}


int main(int ac, char *av[])
{
    
    int funct;
    t_fifi data;
    data.min_real = -2,
    data.max_real = 2;
    data.min_img = -2, 
    data.max_img = 1.5;
    data.max_it = 50;
    
    funct = parcing(ac, av);
    funct = funct;
    
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
    color_screen(&data, 0x000000);
    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.img_ptr, 0, 0);
    
    hooks_init(&data);
    // mlx_key_hook(data.mlx_win, press_key, &data);
    // mlx_key_hook(data.mlx_win, press_mouse, &data);
    
	mlx_loop(data.mlx_ptr);


	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
    //creating a window.
    //parcing
    //asc exit

}
