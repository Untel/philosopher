/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/30 01:59:09 by adda-sil         ###   ########.fr       */
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
		should_stop &= (philo->eat_count > e->nb_eat);
		if (!philo->eating && philo->die_at && philo->die_at < tts)
			return (print_status(philo, STATUS_DEAD, FALSE) || TRUE);
	}
	if (should_stop)
		return (print_fatal(e, ALL_PHILOS_ATE) || TRUE);
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
	create_threads(&e);
	while (!e.end)
		e.end = should_stop_simulation(&e);
	clean_env(&e);
	return (EXIT_SUCCESS);
}
