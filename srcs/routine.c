/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:35:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/03 01:18:26 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	*eat_count_routine(void *addr)
{
	t_env	*env;
	int		i;
	int		eaten;

	env = (t_env *)addr;
	eaten = -1;
	while (++eaten < env->nb_eat && !env->end)
	{
		i = -1;
		while (++i < env->nb_philo)
			pthread_mutex_lock(&env->philos[i].mut_eat);
	}
	if (!env->end)
		print_fatal(env);
	return (NULL);
}

void
	*liveness_routine(void *addr)
{
	t_philo		*p;
	uint64_t	tts;

	p = (t_philo *)addr;
	while (!p->env->end)
	{
		tts = timestamp(p->env);
		if (!p->eating && p->die_at < tts)
		{
			pthread_mutex_lock(&(p->env->mut_end));
			print_status(p, tts, STATUS_DEAD, FALSE);
			pthread_mutex_unlock(&(p->env->mut_end));
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

/**
 ** run_routine
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
	if (pthread_create(&p->liveness_tid, NULL, &liveness_routine, addr) != 0)
		return ((void *)TRUE);
	pthread_detach(p->liveness_tid);
	while (!p->env->end)
	{
		take_fork(p);
		eat(p);
		go_bed(p);
		think(p);
	}
	return (NULL);
}
