/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:46:18 by hejang            #+#    #+#             */
/*   Updated: 2022/05/18 11:55:01 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	make_map(char *argv, t_data *d_struct)
{
	check_file(argv);
	read_map_file(argv, d_struct);
	is_square(d_struct);
	check_wall(d_struct);
}

void	check_file(char *file)
{
	if (!file)
		ft_error("no file");
	while (*file != '\0')
	{
		if (*file == '.')
			break ;
		file++;
	}
	if (*file == '\0')
		ft_error("file extension");
	if (!ft_strncmp(file, ".ber", 5))
		ft_error("file extension");
}

void	read_map_file(char *file, t_data *d)
{
	int		fd;
	char	*s;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("open failed");
	s = get_next_c(fd);
	if (!s)
	{
		close(fd);
		ft_error("file is empty");
	}
	close(fd);
	if (!check_elements(s, d))
	{
		free(s);
		ft_error("The map must be composed of only 5 possible characters");
	}
	d->map = ft_split(s, 10);
	free(s);
}

char	*get_next_c(int fd)
{
	char	*buf;
	char	*s;
	char	*ptr;
	int		read_len;

	s = ft_strdup("");
	read_len = 1;
	buf = malloc(sizeof(char) * 2);
	if (!buf)
		return (NULL);
	while (read_len > 0)
	{
		read_len = read(fd, buf, 1);
		buf[1] = '\0';
		ptr = ft_strjoin(s, buf);
		free(s);
		s = ptr;
	}
	free(buf);
	return (s);
}

int	check_elements(char *s, t_data *data)
{
	if (!s)
		return (FALSE);
	data->sp_cnt = 0;
	data->col_cnt = 0;
	data->exit_cnt = 0;
	while (*s != '\0')
	{
		if (*s == '0' || *s == '1' || *s == 'C'
			|| *s == 'E' || *s == 'P' || *s == '\n')
		{
			if (*s == 'P')
				data->sp_cnt++;
			else if (*s == 'C')
				data->col_cnt++;
			else if (*s == 'E')
				data->exit_cnt++;
		}
		else
			return (FALSE);
		s++;
	}
	if (data->sp_cnt == 0 || data->sp_cnt > 1 || data->exit_cnt == 0
		|| data->col_cnt == 0)
		return (FALSE);
	return (TRUE);
}
