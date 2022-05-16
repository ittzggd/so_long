/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:57:58 by hejang            #+#    #+#             */
/*   Updated: 2022/05/16 12:51:20 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	is_success(t_data *data)
{
	char	*tmp;
	int		mv_cnt;

	mv_cnt = data->move_cnt;
	if (data->col_cnt == 0)
	{
		tmp = ft_itoa(mv_cnt);
		write(1, "total movement : ", 18);
		write(1, tmp, ft_strlen(tmp));
		write(1, "\n", 1);
		write(1, "It's a rich man's world!\n", 25);
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(tmp);
		exit(0);
	}
	return (FALSE);
}
