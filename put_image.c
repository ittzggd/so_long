/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:47:08 by hejang            #+#    #+#             */
/*   Updated: 2022/05/14 18:51:24 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	put_image(t_data *data)
{
	int		x;
	int		y;
	char	**tmp;

	if (!data)
		return (0);
	put_background(data);
	y = 0;
	tmp = data->map;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			put_image_to_window(data, tmp[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (1);
}

void	put_image_to_window(t_data *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->img.player, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.item, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->img.background, x, y);
}

int	put_background(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			mlx_put_image_to_window(data->mlx,
				data->mlx_win, data->img.background, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (1);
}

void	initialize_image(t_data *data)
{
	int	width;
	int	height;

	data->img.background = mlx_xpm_file_to_image(data->mlx,
			"../image/AnyConv.com__bluue.xpm", &width, &height);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"../image/AnyConv.com__real_mario.xpm", &width, &height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx,
			"../image/AnyConv.com__exit.xpm", &width, &height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
			"../image/AnyConv.com__wall.xpm", &width, &height);
	data->img.item = mlx_xpm_file_to_image(data->mlx,
			"../image/AnyConv.com__coin.xpm", &width, &height);
}
