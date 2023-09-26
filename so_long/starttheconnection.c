/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starttheconnection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:09:17 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 18:42:17 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	makeconnection(t_data *data)
{
	data->mlx_conecction = mlx_init();
	if (data->mlx_conecction == NULL)
		return (0);
	return (0);
}

int	opennewwindow(t_data *data)
{
	data->mlx_window = mlx_new_window(data->mlx_conecction,
			data->win_width, data->win_hight, "So_long");
	if (data->mlx_window == NULL)
	{
		free(data->mlx_conecction);
		return (0);
	}
	return (0);
}

int	widhight(t_data *data, int linesize, char *arg)
{
	int		fd;
	char	**str;

	data->win_hight = 0;
	str = (char **)malloc(sizeof(char *) * linesize);
	if (!str)
		return (0);
	fd = open(arg, O_RDONLY, 0777);
	*str = get_next_line(fd);
	data->win_hight = linesize;
	data->map = str;
	data->win_width = ft_strlen(*str) - 1;
	str++;
	while (1)
	{
		*str = get_next_line(fd);
		if (!(*str))
			break ;
		str++;
	}
	str = NULL;
	data->win_hight *= 70;
	data->win_width *= 70;
	return (0);
}

void	destroyall(t_data *data)
{
	char	**str;
	int		i;

	i = 0;
	str = data->map;
	mlx_destroy_window(data->mlx_conecction, data->mlx_window);
	free(data->mlx_conecction);
	exit(0);
}
