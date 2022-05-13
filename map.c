/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:46:18 by hejang            #+#    #+#             */
/*   Updated: 2022/05/13 19:03:13 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	make_map(char *argv, t_data *d_struct)
{
	if (!check_file(argv))
		return (FALSE);
	read_map_file(argv, d_struct);
	if (!is_square(d_struct))
		return (FALSE);
	if (!check_wall(d_struct))
		return (FALSE);
	return (TRUE);
}

int	check_file(char *file)
{
	if (!file)
		return (FALSE);
	while (*file != '\0')
	{
		if (*file == '.')
			break ;
		file++;
	}
	if (*file == '\0')
		return (FALSE);
	if (!ft_strncmp(file, ".ber", 4))
		return (FALSE);
	return (TRUE);
}

void	read_map_file(char *str, t_data *d)
{
	char	*s;
	char	*buf;
	char	*ptr;
	int		fd;
	int		read_len;

	fd = open(str, O_RDONLY);//아니면 fd 를 0으로 놓고 바로 받기?? 
	if (fd < 0)
		ft_error(1);
	s = strdup("");
	read_len = 1;
	buf = malloc(sizeof(char) * 2); //할당 안 해주고 size 아니까 배열로 해도 될 듯;
	while (read_len > 0)
	{
		read_len = read(fd, buf, 1);
		buf[1] = '\0';
		ptr = ft_strjoin(s, buf);//strjoin을 
		free(s);
		s = ptr;
	}
	if (!check_elements(s, d))
	{
		close(fd);
		free(s);
		free(buf);
		ft_error(2);
	}
	d->map = ft_split(s, 10);
	close(fd);
	free(s);
	free(buf);
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
		if (*s == '0' || *s == '1' || *s == 'C' || *s == 'E' || *s == 'P' || *s == '\n')
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
	if (data->sp_cnt == 0 || data->sp_cnt > 1 || data->exit_cnt == 0)
		return (FALSE);
	return (TRUE);
}
