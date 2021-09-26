/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:22:52 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 17:42:07 by adda-sil         ###   ########.fr       */
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
	unsigned int	i;
	unsigned int	count;
	int				sign;

	i = 0;
	count = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
	{
		count = count * 10 + (str[i++] - '0');
	}
	return (count * sign);
}

uint64_t
	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void
	print_env(t_env *d)
{
	printf("-------------------------------------------------------\n");
	printf("Args: nb_philo (%d) | tt_eat (%d)", d->nb_philo, d->tt_eat);
	printf("| tt_die (%d) | tt_sleep (%d)", d->tt_die, d->tt_sleep);
	printf("| nb_eat (%d)\n", d->nb_eat);
	printf("-------------------------------------------------------\n");
}
