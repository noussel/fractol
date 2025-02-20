#include "fractol.h"

// int main()
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	t_data	img;
// 	int offset;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "noussayba");
	
// 	img.img = mlx_new_image(mlx_ptr, 600, 600);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

// 	mlx_loop(mlx_ptr);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	free(win_ptr);
// 	mlx_destroy_image(mlx_ptr, img.img);
// 	mlx_destroy_display(mlx_ptr);
// 	free(mlx_ptr);
// }

// int handle_input(int keysym, t_mlx_data *data)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		printf("hi its weeeeeeeeeeeeeeee : %d\n", keysym);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 		exit(EXIT_FAILURE);
// 	}
// 	printf("salaaaaaaaaaaaaaaaam : %d\n",keysym);
// 	return (EXIT_SUCCESS);
// }

// int main()
// {
// 	t_mlx_data data;

// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (EXIT_FAILURE);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 600, "Nouss");
// 	if (!data.win_ptr)
// 	{
// 		mlx_destroy_display(data.mlx_ptr);
// 		free(data.mlx_ptr);
// 		return (EXIT_FAILURE);
// 	}
// 	mlx_key_hook(data.win_ptr, handle_input, &data);
// 	mlx_loop(data.mlx_ptr);
// }

// int	f(int keysym, t_data *data)
// {
// 	printf("Pressed %d\n", keysym);
// 	sleep(1);
// 	return (1);
// }
// int change_color(t_mlx_data *data)
// {
// 	sleep(1);
// 	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, data->color, "hello dedicas l nouss ghita hanane!");
// 	if (data->color == 0xFF0000)
// 		data->color = 0x00FF00;
// 	else if (data->color == 0x00FF00)
// 		data->color = 0x0000FF;
// 	else if (data->color == 0x0000FF)
// 		data->color = 0xFFFFFF;
// 	else
// 		data->color = 0xFF0000;
// 	return (0);
// }

// int main()
// {
// 	t_mlx_data data;

// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (EXIT_FAILURE);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 600, "Nouss");
// 	if (!data.win_ptr)
// 	{
// 		mlx_destroy_display(data.mlx_ptr);
// 		free(data.mlx_ptr);
// 		return (EXIT_FAILURE);
// 	}
// 	data.color = 0xFF0000;
// 	mlx_key_hook(data.win_ptr, f, &data);
// 	mlx_loop_hook(data.mlx_ptr, change_color, &data);
// 	mlx_loop(data.mlx_ptr);
// }




int main()
{
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
}