/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:47:36 by hejang            #+#    #+#             */
/*   Updated: 2022/05/18 11:53:41 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 0)
		move_a(data);
	else if (keycode == 1)
		move_s(data);
	else if (keycode == 2)
		move_d(data);
	else if (keycode == 13)
		move_w(data);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	return (1);
}

void	move_a(t_data *data)
{
	char	**tmp;

	tmp = data->map;
	if (!check_available(data, 'A'))
		return ;
	if (tmp[data->pp_y][data->pp_x - 1] == 'C')
		data->col_cnt--;
	else if (tmp[data->pp_y][data->pp_x - 1] == 'E')
	{
		if (!is_success(data))
			return ;
	}
	data->pp_x--;
	data->map[data->pp_y][data->pp_x] = 'P';
	data->map[data->pp_y][data->pp_x + 1] = '0';
	data->move_cnt++;
	write(1, "movement : ", 12);
	printf("%d\n", data->move_cnt);
}

void	move_w(t_data *data)
{
	char	**tmp;

	tmp = data->map;
	if (!check_available(data, 'W'))
		return ;
	if (tmp[data->pp_y - 1][data->pp_x] == 'C')
		data->col_cnt--;
	else if (tmp[data->pp_y - 1][data->pp_x] == 'E')
	{
		if (!is_success(data))
			return ;
	}
	data->pp_y--;
	data->map[data->pp_y][data->pp_x] = 'P';
	data->map[data->pp_y + 1][data->pp_x] = '0';
	data->move_cnt++;
	write(1, "movement : ", 12);
	printf("%d\n", data->move_cnt);
}

void	move_s(t_data *data)
{
	char	**tmp;

	tmp = data->map;
	if (!check_available(data, 'S'))
		return ;
	if (tmp[data->pp_y + 1][data->pp_x] == 'C')
		data->col_cnt--;
	else if (tmp[data->pp_y + 1][data->pp_x] == 'E')
	{
		if (!is_success(data))
			return ;
	}
	data->pp_y++;
	data->map[data->pp_y][data->pp_x] = 'P';
	data->map[data->pp_y - 1][data->pp_x] = '0';
	data->move_cnt++;
	write(1, "movement : ", 12);
	printf("%d\n", data->move_cnt);
}

void	move_d(t_data *data)
{
	char	**tmp;

	tmp = data->map;
	if (!check_available(data, 'D'))
		return ;
	if (tmp[data->pp_y][data->pp_x + 1] == 'C')
		data->col_cnt--;
	else if (tmp[data->pp_y][data->pp_x + 1] == 'E')
	{
		if (!is_success(data))
			return ;
	}
	data->pp_x++;
	data->map[data->pp_y][data->pp_x] = 'P';
	data->map[data->pp_y][data->pp_x - 1] = '0';
	data->move_cnt++;
	write(1, "movement : ", 12);
	printf("%d\n", data->move_cnt);
}
