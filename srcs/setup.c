/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:45:45 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/30 02:03:47 by adda-sil         ###   ########.fr       */
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
		e->nb_eat = 0;
	e->turn = 0;
	e->end = 0;
	if (TTS_START)
		e->start_tts = real_timestamp();
	else
		e->start_tts = 0;
	return (check_args(e));
}

/**
 ** check_args
 **/
int
	check_args(t_env *e)
{
	if (e->nb_philo < 2)
		return (printf(ERR_PHILO_COUNT) && FALSE);
	if (e->tt_die < 0)
		return (printf(ERR_ARG_NEG, "time_to_die") && FALSE);
	if (e->tt_eat < 0)
		return (printf(ERR_ARG_NEG, "time_to_eat") && FALSE);
	if (e->tt_sleep < 0)
		return (printf(ERR_ARG_NEG, "time_to_sleep") && FALSE);
	if (e->nb_eat < 0)
		return (printf(ERR_ARG_NEG, MUST_EAT) && FALSE);
	return (setup_philos(e));
}

/**
 ** setup_philos
 **/
int
	setup_philos(t_env *e)
{
	int	i;

	e->philos = malloc(sizeof(t_philo) * (e->nb_philo));
	if (!(e->philos))
		return (printf(ERR_INIT_PHILOS) && FALSE);
	e->mut_forks = malloc(sizeof(pthread_mutex_t) * (e->nb_philo));
	if (!(e->mut_forks))
		return (printf(ERR_INIT_FORKS) && FALSE);
	i = e->nb_philo;
	while (--i >= 0)
	{
		e->philos[i] = (t_philo){.id = i, .env = e, .left_fork = i,
			.right_fork = (i + 1) % e->nb_philo, .eat_count = 0,
			.eating = FALSE, .die_at = 0, .last_meal = 0,
		};
		pthread_mutex_init(&e->mut_forks[i], NULL);
		// print_philo(&(e->philos[i]));
	}
	pthread_mutex_init(&e->mut_writer, NULL);
	return (TRUE);
}
