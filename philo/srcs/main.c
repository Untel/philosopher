/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/10 18:13:41 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 **	create_threads
 **
 ** if (e->nb_eat > 0)
 ** {
 ** 	if (pthread_create(&(e->ecm_tid), NULL, &eat_count_routine, e) != 0)
 ** 		return (FALSE);
 ** 	pthread_detach(e->ecm_tid);
 ** }
 ** usleep(100);
 **/
int
	create_threads(t_env *e)
{
	int			i;
	t_philo		*p;

	i = -1;
	while (++i < e->nb_philo)
	{
		p = &(e->philos[i]);
		if (pthread_create(&(p->tid), NULL, &run_routine, p) != 0)
			return (printf(ERR_INIT_THREAD) && FALSE);
	}
	return (TRUE);
}

/**
 **	should_stop_simulation
 **/
int
	should_stop_simulation(t_env *e)
{
	int			i;
	uint64_t	tts;
	t_philo		*philo;
	int			should_stop;

	i = -1;
	tts = timestamp(e);
	should_stop = e->nb_eat > 0;
	while (++i < e->nb_philo)
	{
		philo = &(e->philos[i]);
		should_stop &= (philo->eat_count >= e->nb_eat);
		pthread_mutex_lock(&philo->mut_eat);
		if (!philo->eating && philo->die_at && philo->die_at < tts)
		{
			pthread_mutex_unlock(&philo->mut_eat);
			return (print_status(philo, tts, STATUS_DEAD, FALSE) && TRUE);
		}
		pthread_mutex_unlock(&philo->mut_eat);
	}
	if (should_stop)
		return (print_fatal(e, ALL_PHILOS_ATE) || TRUE);
	usleep(100);
	return (FALSE);
}

/**
 **	Main
 **/
int
	main(int argc, char **argv)
{
	t_env	e;

	if (!args_are_valids(&e, argc, argv))
		return (EXIT_FAILURE);
	if (!setup_philos(&e))
		return (clean_env(&e) && EXIT_FAILURE);
	if (!create_threads(&e))
		return (clean_env(&e) && EXIT_FAILURE);
	while (!e.end)
		e.end = should_stop_simulation(&e);
	while (--e.nb_philo > -1)
		pthread_join(e.philos[e.nb_philo].tid, NULL);
	clean_env(&e);
	return (EXIT_SUCCESS);
}
