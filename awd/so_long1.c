/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:03:52 by amonem            #+#    #+#             */
/*   Updated: 2023/09/25 19:58:15 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_data
{
	char	**map;
	void	*mlx_conecction;
	void	*mlx_window;
	void	*mlx_ground;
	void	*mlx_rock;
	void	*mlx_coin;
	void	*mlx_door;
	void	*mlx_player;
	//void	*mlx_enemy;
	int		start_x;
	int		start_y;
	int		win_width;
	int		win_hight;
	int		checkfinish;
	int		move_count;
}			t_data;

void errorfunc(void)
{
	write(2, "Error\n", 6);
	exit(0);
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
	if (x >= data->win_hight / 70 || y >= data->win_width / 70 || x <= 0 || y <= 0 || (str[x][y] != 'C' && str[x][y] != 'E' && str[x][y] != '0' && str[x][y] != 'P'))
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
			if (str[i][j] == 'E' && j == (data->start_x / 70) && i == (data->start_y / 70) && data->checkfinish)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
// int chenemy(t_data *data)
// {
//     char **str;
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     str = data->map;
//     while (str[i])
//     {
//         while (str[i][j] != '\n' && str[i][j])
//         {
//             if (str[i][j] == 'F' && j == (data->start_x / 70) && i == (data->start_y / 70))
//                 mlx_destroy_window(data->mlx_conecction, data->mlx_window);
//             j++;
//         }
//         j = 0;
//         i++;
//     }
//     return (1);
// }

int	putground(t_data *data)
{
	int	width;
	int	hight;
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->mlx_ground = mlx_xpm_file_to_image (data->mlx_conecction, "gro.xpm", &width, &hight);
	while (y <= data->win_hight)
	{
		while (x <= data->win_width)
		{
			mlx_put_image_to_window (data->mlx_conecction, data->mlx_window, data->mlx_ground, x, y);
			x = x + 70;
		}
		x = 0;
		y = y + 70;
	}
	return (0);
}

int	putrock(t_data *data, int x, int y)
{
	int	width;
	int	hight;

	data->mlx_rock = mlx_xpm_file_to_image(data->mlx_conecction, "rock.xpm", &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction, data->mlx_window, data->mlx_rock, x, y);
	return (0);
}

int	putcoin(t_data *data, int x, int y)
{
	int	width;
	int	hight;

	data->mlx_coin = mlx_xpm_file_to_image(data->mlx_conecction, "coin.xpm", &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction, data->mlx_window, data->mlx_coin, x, y);
	return (0);
}

// int	putenemy(t_data *data, int x, int y)
// {
// 	int	width;
// 	int	hight;

// 	data->mlx_enemy = mlx_xpm_file_to_image(data->mlx_conecction, "enemy.xpm", &width, &hight);
// 	mlx_put_image_to_window(data->mlx_conecction, data->mlx_window, data->mlx_enemy, x, y);
// 	return (0);
// }
int	putplayer(t_data *data, int x, int y, char *str)
{
	int	width;
	int	hight;

	data->mlx_player = mlx_xpm_file_to_image(data->mlx_conecction, str, &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction, data->mlx_window, data->mlx_player, x, y);
	return (0);
}

int	putdoor(t_data *data, int x, int y)
{
	int	width;
	int	hight;

	data->mlx_door = mlx_xpm_file_to_image(data->mlx_conecction, "door.xpm", &width, &hight);
	mlx_put_image_to_window(data->mlx_conecction, data->mlx_window, data->mlx_door, x, y);
	return (0);
}

int	makeconnection(t_data *data)
{
	data->mlx_conecction = mlx_init();
	if (data->mlx_conecction == NULL)
		return (0);
	return (0); ///////////////////////////////
}

int	opennewwindow(t_data *data)
{
	data->mlx_window = mlx_new_window(data->mlx_conecction, data->win_width, data->win_hight, "So_long");
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
//dont forget malloc check //and the size
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

void	putallhelper(t_data *data, char **str, int i, int j)
{
	if (str[i][j] == '1')
		putrock(data, j * 70, i * 70);
	if (str[i][j] == 'P')
	{
		data->start_x = j * 70;
		data->start_y = i * 70;
		putplayer(data, j * 70, i * 70, "down0.xpm");
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
	// if (str[i][j] == 'F')
	// {
	// 	putenemy(data, j * 70, i * 70);
	// }
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
		destroyall(data);
    // chenemy(data);
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
			if (str[i][j] == '1' && j == data->start_x / 70 && i == data->start_y / 70)
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
	mlx_clear_window(data->mlx_conecction, data->mlx_window);
	putground(data);
	putallneeded(data);
	putplayer(data, data->start_x, data->start_y, str);
}

void	for_d_and_wkeys(t_data *data, int keycode)
{
	if (keycode == 2)
	{
		data->start_x = data->start_x + 70;
		if (checkwall(data))
			puttherequireonwin(data, "right0.xpm");
		else
			data->start_x = data->start_x - 70;
	}
	if (keycode == 1)
	{
		data->start_y = data->start_y + 70;
		if (checkwall(data))
			puttherequireonwin(data, "down0.xpm");
		else
			data->start_y = data->start_y - 70;
	}
}

int	ft_key_hook(int keycode, t_data *data)
{

	data->move_count++;
printf("count of steps :%d\n", data->move_count);
	if (keycode == 53)
		destroyall(data);
	if (keycode == 13)
	{
		data->start_y = data->start_y - 70;
		if (checkwall(data))
			puttherequireonwin(data, "up0.xpm");
		else
			data->start_y = data->start_y + 70;
	}
	if (keycode == 0)
	{
		data->start_x = data->start_x - 70;
		if (checkwall(data))
			puttherequireonwin(data, "left0.xpm");
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
