#ifndef FTRACTOL_H
#define FTRACTOL_H

# include "libft/libft.h"
# include <stdio.h>
# include <mlx.h>
#include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

#define WEIDTH 800
#define HEIGTH 800

typedef struct s_complex
{
    double real;//X
    double   i;//Y
}   t_complex;


typedef struct s_img
{
    void *img_ptr;
    char *img_pxl_ptr;
    int b_p_p;
    int endian;
    int line_len;
} t_img;

typedef struct s_fifi
{
    void *mlx_ptr;
    void *mlx_win;
    t_img img;
    int max_it;
    double shift_x;
    double shift_y;
}t_fifi;

void put_error();
int parcing(int ac, char *av[]);
double map(int px, double min_real, double max_real, int size);
// double map_y(int py, double min_imag, double max_imag);
// typedef struct s_data
// {
//     void *img;
//     void *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
// }   t_data;

// // typedef struct s_mlx_data
// {
//     void	*mlx_ptr;
//     void	*win_ptr;
//     int     color;
// }               t_mlx_data;



#endif