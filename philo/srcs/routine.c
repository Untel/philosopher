/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:35:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 16:40:51 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 ** run_routine
 **	if (pthread_create(&p->liveness_tid, NULL, &liveness_routine, addr) != 0)
 **		return ((void *)TRUE);
 **	pthread_detach(p->liveness_tid);
 **/
void
	*run_routine(void *addr)
{
	t_philo	*p;

	p = (t_philo *)addr;
	if (DELAY_THREAD_CREATION)
		sleep_ms(p->id * DELAY_THREAD_CREATION);
	pthread_mutex_lock(&(p->mut_eat));
	p->last_meal = timestamp(p->env);
	p->die_at = p->last_meal + p->env->tt_die;
	pthread_mutex_unlock(&(p->mut_eat));
	while (TRUE)
	{
		pthread_mutex_lock(&(p->env->mut_end));
		if (p->env->end)
		{
			pthread_mutex_unlock(&(p->env->mut_end));
			return ((void *)0);
		}
		pthread_mutex_unlock(&(p->env->mut_end));
		if (!(take_fork(p)
				&& eat(p)
				&& go_bed(p)
				&& think(p)))
			return ((void *)0);
	}
	return ((void *)0);
}
