/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/10/21 17:56:27 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 **	create_threads
 **/
int
	create_threads(t_env *e)
{
	int			i;
	t_philo		*p;

	if (e->nb_eat > 0)
	{
		if (pthread_create(&(e->eat_count_tid), NULL, &eat_count_routine, (void *)e) != 0)
			return (FALSE);
		pthread_detach(e->eat_count_tid);
	}
	i = -1;
	while (++i < e->nb_philo)
	{
		p = &(e->philos[i]);
		if (pthread_create(&(p->tid), NULL, &run_routine, (void *)p) != 0)
			return (FALSE);
		pthread_detach(p->tid);
		if (DELAY_THREAD_CREATION > 0)
			sleep_ms(DELAY_THREAD_CREATION);
	}
	return (TRUE);
}
/*
** int
** 	should_stop_simulation(t_env *e)
** {
** 	int			i;
** 	uint64_t	tts;
** 	t_philo		*philo;
** 	int			should_stop;
** 
** 	i = -1;
** 	tts = timestamp(e);
** 	should_stop = e->nb_eat > 0;
** 	while (++i < e->nb_philo)
** 	{
** 		philo = &(e->philos[i]);
** 		should_stop &= (philo->eat_count > e->nb_eat);
** 		if (!philo->eating && philo->die_at && philo->die_at < tts)
** 			return (print_status(philo, tts, STATUS_DEAD, FALSE) || TRUE);
** 	}
** 	if (should_stop)
** 		return (print_fatal(e, ALL_PHILOS_ATE) || TRUE);
** 	return (FALSE);
** }
*/

/**
 **	Main
 **/
int
	main(int argc, char **argv)
{
	t_env	e;

	if (!args_are_valids(&e, argc, argv))
		return (EXIT_FAILURE);
	print_env(&e);
	create_threads(&e);
	pthread_mutex_lock(&e.mut_end);
	pthread_mutex_unlock(&e.mut_end);
	clean_env(&e);
	return (EXIT_SUCCESS);
}
