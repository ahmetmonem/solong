/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:03:52 by amonem            #+#    #+#             */
/*   Updated: 2023/09/21 21:10:03 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct data
{
    char    **map;
    void    *mlx_conecction;
    void    *mlx_window;
    void    *mlx_image;
    int     start_x;
    int     start_y;
    int     win_width;
    int     win_hight;
}           t_data;

int putground(t_data *data)
{    
    int width;
    int hight;

    data->mlx_image = mlx_xpm_file_to_image (data->mlx_conecction, "gro.xpm", &width, &hight);
    mlx_put_image_to_window (data->mlx_conecction, data->mlx_window, data->mlx_image, 0, 0);
    return 0;
}

int putcoin(t_data *data)
{    
    int width;
    int hight;

    data->mlx_image = mlx_xpm_file_to_image (data->mlx_conecction, "coins.xpm", &width, &hight);
    mlx_put_image_to_window (data->mlx_conecction, data->mlx_window, data->mlx_image, 0, 0);
    return 0;
}

int putrock(t_data *data)
{    
    int width;
    int hight;

    data->mlx_image = mlx_xpm_file_to_image (data->mlx_conecction, "rock.xpm", &width, &hight);
    mlx_put_image_to_window (data->mlx_conecction, data->mlx_window, data->mlx_image, 140, 140);
    return 0;
}

int makeconnection(t_data *data)
{
    data->mlx_conecction = mlx_init();
    if (data->mlx_conecction == NULL)
        return (0);
    return (0);
}

int opennewwindow(t_data *data)
{
    data->mlx_window = mlx_new_window(data->mlx_conecction, data->win_width, data->win_hight, "So_long");
    if (data->mlx_window == NULL)
    {
        free(data->mlx_conecction);
        return (0);
    }
    return (0);
}

void    widhight(t_data *data)
{
    int fd;
    char **str;
    
    data->win_hight = 0;
    str = (char **)malloc(8*20);
    //dont forget malloc check 
    fd = open("map_files/map_1.ber", O_RDONLY, 0777);
    *str = get_next_line(fd);
    data->win_hight++;
    data->map = str;
    data->win_width = ft_strlen(*str) - 1;
    str++;
    while (1)
    {
        *str = get_next_line(fd);
        if (!(*str))
            break;
        data->win_hight++;
        str++;
    }
    str = NULL;
    data->win_hight *= 70;
    data->win_width *= 70;
}

int main()
{
    t_data data;
    widhight(&data);
    makeconnection(&data);
    opennewwindow(&data);
    putground(&data);
    putcoin(&data);
    putrock(&data);
    mlx_loop(data.mlx_conecction);
}