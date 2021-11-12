/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 16:33:23 by commetuveux      ###   ########.fr       */
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
	int			tts;
	t_philo		*philo;

	i = -1;
	tts = timestamp(e);
	while (++i < e->nb_philo)
	{
		philo = &(e->philos[i]);
		pthread_mutex_lock(&philo->mut_eat);
		if (!philo->eating && philo->die_at && philo->die_at < tts)
		{
			pthread_mutex_lock(&(e->mut_end));
			pthread_mutex_lock(&(e->mut_writer));
			e->end = TRUE;
			printf("%d %d %s", tts, philo->id + 1, STATUS_DEAD);
			pthread_mutex_unlock(&(e->mut_writer));
			pthread_mutex_unlock(&(e->mut_end));
			pthread_mutex_unlock(&philo->mut_eat);
			break ;
		}
		pthread_mutex_unlock(&philo->mut_eat);
	}
	usleep(100);
	return (FALSE);
}

void
	release(t_env *e)
{
	int		i;
	t_philo	*p;

	i = -1;
	while (++i < e->nb_philo)
	{
		p = &(e->philos[i]);
		pthread_mutex_unlock(&e->mut_forks[p->id]);
		pthread_mutex_unlock(&p->mut_eat);
		// pthread_mutex_destroy(&e->mut_forks[p->id]);
		// pthread_mutex_destroy(&p->mut_eat);
	}
	pthread_mutex_unlock(&e->mut_writer);
	// pthread_mutex_destroy(&e->mut_writer);
	i = -1;
	while (++i < e->nb_philo)
		pthread_join(e->philos[i].tid, NULL);
	pthread_mutex_unlock(&e->mut_end);
	// pthread_mutex_destroy(&e->mut_end);
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
		should_stop_simulation(&e);
	usleep(100);
	release(&e);
	clean_env(&e);
	return (EXIT_SUCCESS);
}
