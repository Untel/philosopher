/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:45:45 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/10 18:13:07 by commetuveux      ###   ########.fr       */
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
	e->tt_die = ft_atoi(argv[2]);
	e->tt_eat = ft_atoi(argv[3]);
	e->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		e->nb_eat = ft_atoi(argv[5]);
	else
		e->nb_eat = 0;
	e->end = FALSE;
	if (TTS_START)
		e->start_tts = real_timestamp();
	else
		e->start_tts = 0;
	e->philos = NULL;
	e->mut_forks = NULL;
	e->idx = 0;
	return (check_args(e));
}

/**
 ** check_args
 **/
int
	check_args(t_env *e)
{
	if (e->nb_philo < 1)
		return (printf(ERR_LESS_PHILOS) && FALSE);
	if (e->nb_philo > 200)
		return (printf(ERR_MORE_PHILOS) && FALSE);
	if (e->tt_die < 0)
		return (printf(ERR_ARG_NEG, "time_to_die") && FALSE);
	if (e->tt_eat < 0)
		return (printf(ERR_ARG_NEG, "time_to_eat") && FALSE);
	if (e->tt_sleep < 0)
		return (printf(ERR_ARG_NEG, "time_to_sleep") && FALSE);
	if (e->nb_eat < 0)
		return (printf(ERR_ARG_NEG, MUST_EAT) && FALSE);
	return (TRUE);
}

/**
 ** setup_philos
 **/
int
	setup_philos(t_env *e)
{
	e->philos = malloc(sizeof(t_philo) * (e->nb_philo));
	if (!(e->philos))
		return (printf(ERR_INIT_PHILOS) && FALSE);
	e->mut_forks = malloc(sizeof(pthread_mutex_t) * (e->nb_philo));
	if (!(e->mut_forks))
		return (clean_env(e) && printf(ERR_INIT_FORKS) && FALSE);
	while (e->idx < e->nb_philo)
	{
		e->philos[e->idx] = (t_philo){.id = e->idx, .env = e,
			.left_fork = e->idx, .right_fork = (e->idx + 1) % e->nb_philo,
			.eating = FALSE, .die_at = 0, .last_meal = 0, .eat_count = 0,
		};
		if (pthread_mutex_init(&e->mut_forks[e->idx], NULL) != 0)
			return (printf(ERR_INIT_MUTEX) && FALSE);
		if (pthread_mutex_init(&e->philos[e->idx].mut_eat, NULL) != 0)
			return (printf(ERR_INIT_MUTEX) && FALSE);
		e->idx++;
	}
	if (pthread_mutex_init(&e->mut_writer, NULL) != 0)
		return (printf(ERR_INIT_MUTEX) && FALSE);
	if (pthread_mutex_init(&e->mut_end, NULL) != 0)
		return (printf(ERR_INIT_MUTEX) && FALSE);
	return (TRUE);
}
