/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:22:52 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 21:39:37 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	ft_isspace(int c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

int
	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int
	ft_atoi(const char *str)
{
	int			i;
	int			count;
	int			sign;

	i = 0;
	count = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
		count = count * 10 + (str[i++] - '0');
	return (count * sign);
}

int
	ft_itoa(char *buff, int value, char *base, int base_size)
{
	int		i;

	i = 0;
	buff[4095 - i++] = base[value % base_size];
	value /= base_size;
	while (value > 0)
	{
		buff[4095 - i++] = base[value % base_size];
		value /= base_size;
	}
	return (i);
}

int
	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
