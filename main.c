/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:58:19 by hejang            #+#    #+#             */
/*   Updated: 2022/05/13 18:58:52 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data)); //이 부분은 initialize 함수로 따로 빼고 내부 멤버까지 초기화 해주기
	if (argc > 1)
	{
		set_struct(data);
		if (!make_map(argv[1], data))
			ft_error(1);
		window(data);
	}
}

void	set_struct(t_data *data)
{
	data->move_cnt = 0;
	data->height = 0;
	data->width = 0;
	data->sp_cnt = 0;
	data->col_cnt = 0;
	data->exit_cnt = 0;
	data->pp_x = 0;
	data->pp_y = 0;
}
