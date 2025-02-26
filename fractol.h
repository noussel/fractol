

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
#define ZOOM_FACTOR 0.9
#define MOVE_FACTOR 0.1

#define WIDTH 800
#define HEIGHT 800

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
    double min_real;
    double max_real;
    double min_img;
    double max_img;
    double shift_x;
    double shift_y;
    double j_x;
    double j_y;
    double zoom;
    int func;

}t_fifi;

void put_error();
int parcing(int ac, char *av[]);
double map_x(int px ,t_fifi *data);
double map_y(int py, t_fifi *data);
double map_col(int px, double min_real, double max_real, int size);
int press_x(t_fifi *data);
void wich_key(int keysym, int *color, t_fifi *data);
void reset(t_fifi *data);
int press_key(int keysym, t_fifi *data);
void error(t_fifi *data);
void my_pixel_put(t_img *img, int x, int y, int color);
void data_init(t_fifi *data);
int press_mouse(int button, int x, int y, t_fifi *data);
void color_screen(t_fifi *data, int color);
int malderbort(t_fifi *data, int x, int y, int color);
void julia(t_fifi *data, int x, int y, int color);
#endif