/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:35:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 21:39:27 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	*drop_forks(t_philo *p)
{
	if (p->mflag & LFORK)
	{
		pthread_mutex_unlock(&p->env->mut_forks[p->left_fork]);
		p->mflag &= RELEASE_LFORK;
	}
	if (p->mflag & RFORK)
	{
		pthread_mutex_unlock(&p->env->mut_forks[p->right_fork]);
		p->mflag &= RELEASE_RFORK;
	}
	return (NULL);
}

/**
 ** run_routine
 **	if (pthread_create(&p->liveness_tid, NULL, &liveness_routine, addr) != 0)
 **		return ((void *)TRUE);
 **	pthread_detach(p->liveness_tid);
 **/
void
	*run_routine(t_philo *p)
{
	pthread_mutex_lock(&p->env->mut_init);
	pthread_mutex_unlock(&p->env->mut_init);
	if (DELAY_THREAD_CREATION && p->id % 2)
		sleep_ms(DELAY_THREAD_CREATION, p->env);
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
			return (drop_forks(p));
		}
		pthread_mutex_unlock(&(p->env->mut_end));
		if (!(take_fork(p)
				&& eat(p)
				&& go_bed(p)
				&& think(p)))
			return (drop_forks(p));
	}
	return (drop_forks(p));
}
