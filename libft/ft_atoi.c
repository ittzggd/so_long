/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:39:34 by hejang            #+#    #+#             */
/*   Updated: 2022/05/13 16:40:05 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"../so_long.h"

int	ft_atoi(const char *str)
{
	long long int	n;
	int				negative;

	n = 0;
	negative = 1;
	if (*str == '-')
		negative = negative * (-1);
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		ft_error(0);
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	if ((n * negative) > INT_MAX)
		ft_error(0);
	else if ((n * negative) < INT_MIN)
		ft_error(0);
	if ((*str <= '0' || *str >= '9') && *str != '\0')
		ft_error(0);
	return ((n * negative));
}
