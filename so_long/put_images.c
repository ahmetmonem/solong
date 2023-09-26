/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:08:20 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 18:30:35 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	putrock(t_data *data, int x, int y)
{
	int	width;
	int	hight;

	data->mlx_rock = mlx_xpm_file_to_image(data->mlx_conecction,
			"./textures/rock.xpm", &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction,
		data->mlx_window, data->mlx_rock, x, y);
	return (0);
}

int	putcoin(t_data *data, int x, int y)
{
	int	width;
	int	hight;

	data->mlx_coin = mlx_xpm_file_to_image(data->mlx_conecction,
			"./textures/coin.xpm", &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction,
		data->mlx_window, data->mlx_coin, x, y);
	return (0);
}

int	putplayer(t_data *data, int x, int y, char *str)
{
	int	width;
	int	hight;

	data->mlx_player = mlx_xpm_file_to_image(data->mlx_conecction,
			str, &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction,
		data->mlx_window, data->mlx_player, x, y);
	return (0);
}

int	putdoor(t_data *data, int x, int y)
{
	int	width;
	int	hight;

	data->mlx_door = mlx_xpm_file_to_image(data->mlx_conecction,
			"./textures/door.xpm", &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction,
		data->mlx_window, data->mlx_door, x, y);
	return (0);
}

int	putground(t_data *data)
{
	int	width;
	int	hight;
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->mlx_ground = mlx_xpm_file_to_image (data->mlx_conecction,
			"./textures/gro.xpm", &width, &hight);
	while (y <= data->win_hight)
	{
		while (x <= data->win_width)
		{
			mlx_put_image_to_window (data->mlx_conecction,
				data->mlx_window, data->mlx_ground, x, y);
			x = x + 70;
		}
		x = 0;
		y = y + 70;
	}
	return (0);
}
