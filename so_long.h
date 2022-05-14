/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:46:35 by hejang            #+#    #+#             */
/*   Updated: 2022/05/14 14:19:09 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TRUE 1
# define FALSE 0

# include<stdlib.h>
# include<unistd.h>
# include<string.h>
# include<fcntl.h>
# include<mlx.h>
# include"./libft/libft.h"

typedef struct s_img
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
	void	*mlx;
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
void		put_image_to_window(t_data *data, char c, int x, int y)
void		initialize_image(t_data *data);
int			put_background(t_data *data);
void		load(t_data *data);
int			key_pressed(int keycode, t_data *data);
void		move_a(t_data *data);
void		move_w(t_data *data);
void		move_s(t_data *data);
void		move_d(t_data *data);
void		get_starting_position(t_data *data);
int			check_available(t_data *data, char key);
int			is_success(t_data *data);
void		set_struct(t_data *data);
void		ft_error(int errno);

#endif
