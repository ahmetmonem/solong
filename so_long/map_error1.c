/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:05:29 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 18:18:25 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkreachable(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	posofstarterror(data, &i, &j);
	chloopforrechable(data, i, j);
	if (!checkifanycenonreach(data))
		return (0);
	valuesback(data);
	return (1);
}

int	checkrect(t_data *data)
{
	char	**str;
	int		i;
	int		j;
	int		check;

	check = data->win_width / 70;
	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] && str[i][j] != '\n')
		{
			j++;
		}
		if (j != check)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	check_c(t_data *data)
{
	char	**str;
	int		i;
	int		j;
	int		check;

	check = 0;
	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'C')
				check++;
			j++;
		}
		j = 0;
		i++;
	}
	if (check < 1)
		return (0);
	return (1);
}

int	check_p(t_data *data)
{
	char	**str;
	int		i;
	int		j;
	int		check;

	check = 0;
	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'P')
				check++;
			j++;
		}
		j = 0;
		i++;
	}
	if (check != 1)
		return (0);
	return (1);
}

int	check_e(t_data *data)
{
	char	**str;
	int		i;
	int		j;
	int		check;

	check = 0;
	i = 0;
	j = 0;
	str = data->map;
	while (str[i])
	{
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'E')
				check++;
			j++;
		}
		j = 0;
		i++;
	}
	if (check != 1)
		return (0);
	return (1);
}
