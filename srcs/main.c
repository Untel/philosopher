/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/02 22:45:14 by commetuveux      ###   ########.fr       */
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
		if (pthread_create(&(e->ecm_tid), NULL, &eat_count_routine, e) != 0)
			return (FALSE);
		pthread_join(e->ecm_tid, NULL);
	}
	usleep(100);
	i = -1;
	while (++i < e->nb_philo)
	{
		p = &(e->philos[i]);
		if (pthread_create(&(p->tid), NULL, &run_routine, p) != 0)
			return (FALSE);
		pthread_join(p->tid, NULL);
	}
	return (TRUE);
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
	pthread_mutex_lock(&(e.mut_end));
	pthread_mutex_unlock(&(e.mut_end));
	clean_env(&e);
	return (EXIT_SUCCESS);
}
