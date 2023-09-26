/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:03:52 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 19:24:11 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	for_d_and_wkeys(t_data *data, int keycode)
{
	if (keycode == 2)
	{
		data->start_x = data->start_x + 70;
		if (checkwall(data))
			puttherequireonwin(data, "./textures/right0.xpm");
		else
			data->start_x = data->start_x - 70;
	}
	if (keycode == 1)
	{
		data->start_y = data->start_y + 70;
		if (checkwall(data))
			puttherequireonwin(data, "./textures/down0.xpm");
		else
			data->start_y = data->start_y - 70;
	}
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		destroyall(data);
	if (keycode == 13)
	{
		data->start_y = data->start_y - 70;
		if (checkwall(data))
			puttherequireonwin(data, "./textures/up0.xpm");
		else
			data->start_y = data->start_y + 70;
	}
	if (keycode == 0)
	{
		data->start_x = data->start_x - 70;
		if (checkwall(data))
			puttherequireonwin(data, "./textures/left0.xpm");
		else
			data->start_x = data->start_x + 70;
	}
	for_d_and_wkeys(data, keycode);
	return (0);
}

int	line_size(char *arg)
{
	char	*str;
	int		linesize;
	int		fd;

	linesize = 0;
	fd = open(arg, O_RDONLY, 0777);
	str = get_next_line(fd);
	if (str)
		linesize++;
	free(str);
	if (!str)
		errorfunc();
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (str)
			linesize++;
		free(str);
	}
	close (fd);
	return (linesize);
}

int	main(int a, char **arg)
{
	t_data	data;
	int		linesize;

	data.move_count = 0;
	if (a != 2)
		errorfunc();
	linesize = line_size(arg[1]);
	widhight(&data, linesize, arg[1]);
	if (!checkmap(&data))
		errorfunc();
	makeconnection(&data);
	opennewwindow(&data);
	putground(&data);
	putallneeded(&data);
	mlx_hook(data.mlx_window, 2, 0, ft_key_hook, &data);
	mlx_loop(data.mlx_conecction);
}
