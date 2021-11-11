/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:35:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/11 17:28:28 by commetuveux      ###   ########.fr       */
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
	p->last_meal = timestamp(p->env);
	p->die_at = p->last_meal + p->env->tt_die;
	while (!p->env->end
		&& take_fork(p)
		&& eat(p)
		&& go_bed(p)
		&& think(p))
		;
	// printf("End philo %d\n", p->id);
	return (NULL);
}
