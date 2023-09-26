/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:04:16 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 18:17:59 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errorfunc(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	checkanythingoutofneeded(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] != 'E' && str[i][j]
			!= 'P' && str[i][j] != '1' && str[i][j]
			!= '0' && str[i][j] != 'C')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	valuesback(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'W')
				str[i][j] = 'C';
			if (str[i][j] == 'Q')
				str[i][j] = 'E';
			if (str[i][j] == '2')
				str[i][j] = '0';
			if (str[i][j] == '3')
				str[i][j] = 'P';
			j++;
		}
		j = 0;
		i++;
	}
}

int	checkifanycenonreach(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'C' || str[i][j] == 'E')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	chloopforrechable(t_data *data, int x, int y)
{
	char	**str;

	str = data->map;
	if (x >= data->win_hight / 70 || y >= data->win_width / 70
		|| x <= 0 || y <= 0 || (str[x][y] != 'C' && str[x][y]
		!= 'E' && str[x][y] != '0' && str[x][y] != 'P'))
		return ;
	if (str[x][y] == 'C')
		str[x][y] = 'W';
	if (str[x][y] == 'E')
		str[x][y] = 'Q';
	if (str[x][y] == '0')
		str[x][y] = '2';
	if (str[x][y] == 'P')
		str[x][y] = '3';
	chloopforrechable(data, x, y + 1);
	chloopforrechable(data, x, y - 1);
	chloopforrechable(data, x - 1, y);
	chloopforrechable(data, x + 1, y);
	return ;
}
