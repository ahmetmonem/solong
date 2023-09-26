/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:09:24 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 19:23:49 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmovecount(t_data *data)
{
	data->move_count++;
	ft_printf("%d. step\n", data->move_count);
}

void	putallhelper(t_data *data, char **str, int i, int j)
{
	if (str[i][j] == '1')
		putrock(data, j * 70, i * 70);
	if (str[i][j] == 'P')
	{
		data->start_x = j * 70;
		data->start_y = i * 70;
		putplayer(data, j * 70, i * 70, "./textures/down0.xpm");
		str[i][j] = '0';
	}
	if (str[i][j] == 'E')
		putdoor(data, j * 70, i * 70);
	if (str[i][j] == 'C')
	{
		if (i == data->start_y / 70 && j == data->start_x / 70)
			str[i][j] = '0';
		else
		{
			putcoin(data, j * 70, i * 70);
			data->checkfinish = 0;
		}
	}
}

int	putallneeded(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	data->checkfinish = 1;
	j = 0;
	i = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] != '\n' && str[i][j])
		{
			putallhelper(data, str, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (!chfinish(data))
	{
		write(1, "congratulations you won !!!\n", 28);
		destroyall(data);
	}
	return (0);
}

int	checkwall(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] != '\n' && str[i][j])
		{
			if (str[i][j] == '1' &&
				j == data->start_x / 70 && i == data->start_y / 70)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	puttherequireonwin(t_data *data, char *str)
{
	printmovecount(data);
	mlx_clear_window(data->mlx_conecction, data->mlx_window);
	putground(data);
	putallneeded(data);
	putplayer(data, data->start_x, data->start_y, str);
}
