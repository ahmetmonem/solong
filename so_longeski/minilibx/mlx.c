#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct param
{
    void    *mlx_conecction;
    void    *mlx_window;
}t_param;

int my_key_callback(int keycode, t_param *param)
{
    int     x = 100;
    int     y = 100;
    int     z = 200;
    printf("%d\n", keycode);
    if (keycode == 53)
            mlx_string_put(param->mlx_conecction,param->mlx_window, 200, 200, 73824, "");
    if (keycode == 13)
    {
    while (y < 500)
    {
        while (y < z)
        {
            x = 100;
            while (x < 500)
            {
                mlx_pixel_put(param->mlx_conecction, param->mlx_window, x, y, 200);
                x++;
            }
            y++;
        }
    z+=100;
    y = z - 100;
    }

    }
    return (0);
}

int main()
{
    t_param param;
    int     x = 100;
    int     y = 100;
    int     z = 200;

    param.mlx_conecction = mlx_init();
    if (param.mlx_conecction == NULL)
        return (0);
    param.mlx_window = mlx_new_window(param.mlx_conecction, 1000, 1000, "lets");
    while (y < 1000)
    {
        while (y < z)
        {
            x = 100;
            while (x < 500)
            {
                mlx_pixel_put(param.mlx_conecction, param.mlx_window, x, y, 23874423);
                x++;
            }
            y++;
        }
    z+=100;
    y = z - 100;
    }
    //mlx_key_hook(param.mlx_conecction, my_key_callback, &param);
    if (param.mlx_window == NULL)
    {
        mlx_destroy_window(param.mlx_conecction, param.mlx_window);
        free(param.mlx_conecction);
        return (0);
    }

mlx_key_hook(param.mlx_window, my_key_callback, &param);

    mlx_loop(param.mlx_conecction);
}