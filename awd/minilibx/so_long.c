/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:51:42 by amonem            #+#    #+#             */
/*   Updated: 2023/09/20 19:57:35 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct data
{
    void    *mlx_conecction;
    void    *mlx_window;
    void    *mlx_image;
    int     start_x;
    int     start_y;
}t_data;

void    printsquare(t_data *data, int x, int y, int z, int j)
{
    while (y < z)
    {
        while (x < z)
        {
            mlx_pixel_put(data->mlx_conecction, data->mlx_window, x, y, 123342);
            x++;
        }
        x = j;
        y++;
    }
}
int putmyf(t_data *data)
{    
    int width;
    int hight;

    data->start_x +=40;
    data->mlx_image = mlx_xpm_file_to_image (data->mlx_conecction, "myp.xpm", &width, &hight);
    mlx_put_image_to_window (data->mlx_conecction, data->mlx_window, data->mlx_image, data->start_x, data->start_y);
    return 0;
}

int putmyfdown(t_data *data)
{    
    int width = 100;
    int hight = 100;

    data->start_y +=20;
    data->mlx_image = mlx_xpm_file_to_image (data->mlx_conecction, "myp.xpm", &width, &hight);
    mlx_put_image_to_window (data->mlx_conecction, data->mlx_window, data->mlx_image, data->start_x, data->start_y);
    return 0;
}

int putmy(int keycode, t_data *data)
{
    int width;
    int hight;
    int x =100;
    int y = 100;
    int z = 140;
    static int j = 0;
    
    //while(x < 400)
    //{
    //data->mlx_image = mlx_xpm_file_to_image (data->mlx_conecction, "my.xpm", &width, &hight);
    //mlx_put_image_to_window (data->mlx_conecction, data->mlx_window, data->mlx_image, x, y);
    //x++;
    //z++;
    //mlx_destroy_image (data->mlx_conecction, data->mlx_window);
    if (keycode == 0)
    {
        mlx_clear_window(data->mlx_conecction, data->mlx_window);
        //printsquare(data, x, y, z, x);
        putmyfdown(data);

    }
    if (keycode == 53)
    {
        j += 50;
        //mlx_clear_window(data->mlx_conecction, data->mlx_window);
        printsquare(data, x + j, y+ j, z+ j, x + j);
        putmyf(data);
    }
    //mlx_clear_window(data->mlx_conecction, data->mlx_window);
    //usleep(10000);

    //}
    return 0;
}

int main()
{
    t_data data;
    data.start_x = 100;
    data.start_y = 100;


    data.mlx_conecction = mlx_init();
    if (data.mlx_conecction == NULL)
        return (0);
    data.mlx_window = mlx_new_window(data.mlx_conecction, 500, 500, "so_long");
    if (data.mlx_window == NULL)
    {
        mlx_destroy_window(data.mlx_conecction, data.mlx_window);
        free(data.mlx_conecction);
        return (0);
    }
    mlx_key_hook(data.mlx_window, putmy,  &data);
    mlx_loop(data.mlx_conecction);
}