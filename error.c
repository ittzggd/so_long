/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:40:41 by hejang            #+#    #+#             */
/*   Updated: 2022/05/14 21:56:35 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include "./libft/libft.h"

void	ft_error(int errno)
{
	write(2, "Error\n", 6);
	if (errno == 1)
		write(1, "can't readgit  map file\n", 30);
	if (errno == 2)
		write(1, "check map format\n", 17);
	exit(1);
}
