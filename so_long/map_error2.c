/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:05:49 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 18:19:16 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	posofstarterror(t_data *data, int *i, int *j)
{
	char	**str;

	str = data->map;
	while (str[*i])
	{
		while (str[*i][*j] && str[*i][*j] != '\n')
		{
			if (str[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		*j = 0;
		(*i)++;
	}
}

int	checkmapsur2(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = (data->win_hight / 70) - 1;
	str = data->map;
	while (str[j][i] && str[j][i] != '\n')
	{
		if (str[j][i++] != '1')
			return (0);
	}
	if (i != data->win_width / 70)
		return (0);
	i = (data->win_width / 70) - 1;
	j = 0;
	while (str[j])
	{
		if (str[j++][i] != '1')
			return (0);
	}
	if (j != data->win_hight / 70)
		return (0);
	return (1);
}

int	checkmapsur1(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = data->map;
	while (str[j][i] && str[j][i] != '\n')
	{
		if (str[j][i++] != '1')
			return (0);
	}
	if (i != data->win_width / 70)
		return (0);
	i = 0;
	while (str[j])
	{
		if (str[j++][i] != '1')
			return (0);
	}
	if (j != data->win_hight / 70)
		return (0);
	if (!checkmapsur2(data))
		return (0);
	return (1);
}

int	checkmap(t_data *data)
{
	if (!checkanythingoutofneeded(data))
		return (0);
	if (!checkrect(data))
		return (0);
	if (!check_c(data))
		return (0);
	if (!check_p(data))
		return (0);
	if (!check_e(data))
		return (0);
	if (!checkmapsur1(data))
		return (0);
	if (!checkreachable(data))
		return (0);
	return (1);
}

int	chfinish(t_data *data)
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
			if (str[i][j] == 'E' && j == (data->start_x / 70) &&
				i == (data->start_y / 70) && data->checkfinish)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
