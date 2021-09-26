/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:45:45 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 18:18:14 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 ** args_are_valids
 **/
int
	args_are_valids(t_env *e, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf(ERR_ARGS_COUNT) && FALSE);
	e->nb_philo = ft_atoi(argv[1]);
	e->tt_eat = ft_atoi(argv[2]);
	e->tt_die = ft_atoi(argv[3]);
	e->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		e->nb_eat = ft_atoi(argv[5]);
	else
		e->nb_eat = NONE;
	e->turn = 0;
	return (check_args(e));
}

/**
 ** args_are_valids
 **/
int
	check_args(t_env *e)
{
	if (e->nb_philo < 2)
		return (printf(ERR_PHILO_COUNT) && FALSE);
	return (TRUE);
}

/**
 ** setup_philos
 **/
int
	setup_philos(t_env *e)
{
	int	i;

	e->philos = malloc(sizeof(t_philo) * (e->nb_philo + 1));
	if (!(e->philos))
		return (printf(ERR_INIT_PHILOS) && FALSE);
	i = -1;
	while (++i < e->nb_philo)
	{
		e->philos[i] = (t_philo){.id = i, .env = e, .left_fork = i,
			.right_fork = (i + 1 % e->nb_philo), .eat_count = 0,
		};
	}
	return (TRUE);
}
