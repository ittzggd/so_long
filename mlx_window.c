#include"so_long.h"


void	window(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->width * 64, data->height * 64, "so_long_mario!");
	initialize_image(data);
	put_image(data);
	get_starting_position(data);
	load(data);
}

void	load(t_data *data)
{
	mlx_key_hook(data->mlx_win, &key_pressed, data);
	mlx_loop_hook(data->mlx, &put_image, data);
	mlx_loop(data->mlx);
}
