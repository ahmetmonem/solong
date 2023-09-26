/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:12:56 by amonem            #+#    #+#             */
/*   Updated: 2023/09/26 18:25:06 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "stdlib.h"
# include "unistd.h"
# include "fcntl.h"
# include "./get_next_line/get_next_line.h"
# include "./minilibx/mlx.h"
# include "./ft_printf/ft_printf.h"

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
	int		start_x;
	int		start_y;
	int		win_width;
	int		win_hight;
	int		checkfinish;
	int		move_count;
}			t_data;

void	errorfunc(void);
void	destroyall(t_data *data);
int		checkanythingoutofneeded(t_data *data);
void	valuesback(t_data *data);
int		checkifanycenonreach(t_data *data);
void	chloopforrechable(t_data *data, int x, int y);
void	posofstarterror(t_data *data, int *i, int *j);
int		checkreachable(t_data *data);
int		checkrect(t_data *data);
int		check_c(t_data *data);
int		check_p(t_data *data);
int		check_e(t_data *data);
int		checkmapsur2(t_data *data);
int		checkmapsur1(t_data *data);
int		checkmap(t_data *data);
int		chfinish(t_data *data);
int		putground(t_data *data);
int		putrock(t_data *data, int x, int y);
int		putcoin(t_data *data, int x, int y);
int		putplayer(t_data *data, int x, int y, char *str);
int		putdoor(t_data *data, int x, int y);
int		makeconnection(t_data *data);
int		opennewwindow(t_data *data);
int		widhight(t_data *data, int linesize, char *arg);
void	putallhelper(t_data *data, char **str, int i, int j);
int		putallneeded(t_data *data);
int		checkwall(t_data *data);
void	puttherequireonwin(t_data *data, char *str);
int		ft_key_hook(int keycode, t_data *data);
int		line_size(char *arg);
void	for_d_and_wkeys(t_data *data, int keycode);

#endif