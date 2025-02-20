#include "fractol.h"


typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *mlx_win;
    t_img img;
} t_mlx_data;

void my_pixel_put(t_img *img, int x, int y, int color)
{
    int offset;
    offset = (img->line_len * y) + (x * (img->b_p_p / 8));
    if(offset % 6 == 0 || offset % 5 == 0)
        *((unsigned int *)(img->img_pxl_ptr + offset)) = color;
    else
        *((unsigned int *)(img->img_pxl_ptr + offset)) = 0xffffff;
}

void color_screen(t_mlx_data *data, int color)
{
    int y = 0;
    int x = 0;
    while(y < 800)
    {
        x = 0;
        while(x < 800)
        {
            my_pixel_put(&data->img, x, y, color);
            x++;
        }
        y++;
    }
}

int press_key(int keysym, t_mlx_data *data)
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
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
    return (0);
}

int main()
{
    t_mlx_data data;

    data.mlx_ptr = mlx_init();//if(!ptr)
    data.mlx_win = mlx_new_window(data.mlx_ptr, 800, 800, "hello prety !");//if(!)

    data.img.img_ptr = mlx_new_image(data.mlx_ptr, 800, 800);
    data.img.img_pxl_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.b_p_p, &data.img.line_len, &data.img.endian);
    // img.img_pixels_ptr = pointer to the first pixel of the window
    mlx_key_hook(data.mlx_win, press_key, &data);
    mlx_loop(data.mlx_ptr);

}

/*#include "fractol.h"

// int malderbort()
// {
//     int j = 0;
//     double tmp;
//     t_complex z;

//     t_complex x;

//     x.real = 0.25;
//     x.i = 0.4;
//     while(j < 10)//i < 50 && (z.i < 2 && z.r < 2)
//     {
//         //z = z^2 + c
//         //initialisation de z.i z.r
//         //Z = (X + Yi)^2 + (X, Yi)
//         //Z = (z.real * z.real) - (z.i * z.i) + (2) * (z.real * z.i)
//         tmp = (z.real * z.real) - (z.i * z.i);
//         z.i = 2 * (z.real * z.i);
//         z.real = tmp;
//         //ading c value
//         z.i += x.i;
//         z.real += x.real;

//         printf("real : %f i : %f \n", z.real, z.i);
//         j++;
//     }

// }

int main(int ac, char *av[])
{
    int funct;
    funct = parcing(ac, av);
    funct = funct;
    
    void *mlx_ptr;//mlx_ptr is the display pointer
	void *mlx_window;

    mlx_ptr = mlx_init();//function create a struct T_XVAR and return its adress (it allocate the pointer)
	if(!mlx_ptr)
		return(1);

	mlx_window = mlx_new_window(mlx_ptr, 600, 600, "noussa");
	if(!mlx_window)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return(1);
	}

    
	mlx_loop(mlx_ptr);


	mlx_destroy_window(mlx_ptr, mlx_window);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
    //creating a window.
    //parcing
    //asc exit

}*/