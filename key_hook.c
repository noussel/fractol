#include "fractol.h"

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *mlx_win;
} t_mlx_data;


void color_screen(t_mlx_data *data, int color)
{

}

int press_key(int keysym, t_mlx_data *data)
{
    if(keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->mlx_win);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    else if (keysym == XK_g)
    {
        color_screen(data, encode_rgb(255, 0, 0));
    }
    else if(keysym == XK_g)
    {
        color_screen(data, encode_rgb(0, 0xff, 0));
    }
    else if (keysym == XK_b)
    {
        color_screen(data, encode_rgb(0, 0, 0xff));
    }
    printf("The %d key has been pressed\n\n", keysym);

    return (0);
}

int main()
{
    t_mlx_data data;

    data.mlx_ptr = mlx_init();//if(!ptr)
    data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 600, "hello prety !");//if(!)

    mlx_key_hook(data.mlx_win, press_key, &data);
    mlx_loop(data.mlx_ptr);

}