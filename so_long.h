#ifndef SO_LONG_H
# define SO_LONG_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<mlx.h>
#include"./libft/libft.h"

typedef	struct s_img
{
	void	*item;
	void	*player;
	void	*exit;
	void	*wall;
	void	*background;
}	t_img;

typedef struct s_data
{
	char	**map;
	int		height;
	int		width;
	int		sp_cnt;
	int		col_cnt;
	int		exit_cnt;
	void 	*mlx;
	void	*mlx_win;
	int		move_cnt;
	int		pp_x;
	int		pp_y;
	t_img	img;
}	t_data;

int			make_map(char *argv, t_data *d_struct);
int			check_file(char *file);
void		read_map_file(char *str, t_data *d);
int			check_elements(char *s, t_data *data);
int			is_square(t_data *data);
int			check_wall(t_data *data);
void		window(t_data *data);
int			put_image(t_data *data);
void		initialize_image(t_data *data);
int			put_background(t_data *data);
void		load(t_data *data);
int			key_pressed(int keycode, t_data *data);
void		move_A(t_data *data);
void		move_W(t_data *data);
void		move_S(t_data *data);
void		move_D(t_data *data);
void		get_starting_position(t_data *data);
int			check_available(t_data *data, char key);
int			is_success(t_data *data);
void		set_struct(t_data *data);
void		ft_error();

#define TRUE 1
#define FALSE 0

# endif
