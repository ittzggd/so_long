#include "so_long.h"

void	get_starting_position(t_data *data)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = data->map;
	i = 0;
	while(tmp[i])
	{
		j = 0;
		while(tmp[i][j])
		{
			if(tmp[i][j] == 'P')
			{
				data->pp_y = i;
				data->pp_x = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	check_available(t_data *data, char key)
{
	int		x;
	int		y;
	char	**tmp;

	tmp = data->map;
	x = data->pp_x;
	y = data->pp_y;
	if(key == 'A')
		x = data->pp_x - 1;
	if(key == 'W')
		y = data->pp_y - 1;
	if(key == 'D')
		x = data->pp_x + 1;
	if(key == 'S')
		y = data->pp_y + 1;
	if(tmp[y][x] == 'C' || tmp[y][x] == '0' || tmp[y][x] == 'E')
		return (TRUE);
	return (FALSE);
}
