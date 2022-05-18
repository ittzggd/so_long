/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:40:41 by hejang            #+#    #+#             */
/*   Updated: 2022/05/18 11:53:27 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include "./libft/libft.h"

void	ft_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
/*	if (errno == 1)
		write(1, "can't read map file\n", 21);
	if (errno == 2)
		write(1, "check map format\n", 17);*/
	exit(1);
}
