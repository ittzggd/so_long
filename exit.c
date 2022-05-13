/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:57:58 by hejang            #+#    #+#             */
/*   Updated: 2022/05/13 18:58:12 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	is_success(t_data *data)
{
	char	*tmp;
	char	*str;
	int		mv_cnt;

	mv_cnt = data->move_cnt;
	str = "It's a rich man's world!\n";
	if (data->col_cnt == 0)
	{
		tmp = ft_itoa(mv_cnt);
		write(1, "total movement : ", 18);
		write(1, tmp, ft_strlen(tmp));
		write(1, "\n", 1);
		write(1, "It's a rich man's world!\n", 25);
		free(tmp);
		exit(0);
	}
	return (FALSE);
}
