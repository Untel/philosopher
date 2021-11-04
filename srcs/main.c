/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/03 01:07:37 by commetuveux      ###   ########.fr       */
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
	}
	usleep(100);
	i = -1;
	while (++i < e->nb_philo)
	{
		p = &(e->philos[i]);
		if (pthread_create(&(p->tid), NULL, &run_routine, p) != 0)
			return (FALSE);
	}
	i = -1;
	while (++i < e->nb_philo)
	{
		p = &(e->philos[i]);
		pthread_join(p->tid, NULL);
	}
	pthread_join(e->ecm_tid, NULL);
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
	clean_env(&e);
	return (EXIT_SUCCESS);
}
