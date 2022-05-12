/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:46:49 by hejang            #+#    #+#             */
/*   Updated: 2022/05/12 10:46:50 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	is_square(t_data	*map_data)
{
	int		i;
	int		len;
	int		height;
	int		width;
	char	**tmp;

	i = 1;
	tmp = map_data->map;
	len = strlen(tmp[0]);
	while(tmp[i + 1])
	{
		if(len != strlen(tmp[i])) //작업 반복됨;
			return (FALSE);
		i++;
	}
	map_data->height = i + 1;
	map_data->width = len;
	return(TRUE);
}

int	check_wall(t_data *map_data)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = map_data->map;
	while(tmp[i] != NULL)
	{
		j = 0;
		if(	i == 0 || i == map_data->height - 1)
			while(tmp[i][j])
			{
				if(tmp[i][j] != '1')
					return (FALSE);
				j++;
			}
		if(tmp[i][0] != '1' || tmp[i][map_data->width - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
