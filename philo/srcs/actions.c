/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:20:41 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/10 18:21:22 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	take_fork(t_philo *p)
{
	int			first_fork;
	int			next_fork;
	int			tts;

	if (p->id % 2 == 1)
	{
		first_fork = p->left_fork;
		next_fork = p->right_fork;
	}
	else
	{
		first_fork = p->right_fork;
		next_fork = p->left_fork;
	}
	pthread_mutex_lock(&p->env->mut_forks[first_fork]);
	tts = timestamp(p->env);
	if (!print_status(p, tts, STATUS_TAKE_FORK, TRUE))
		return (FALSE);
	pthread_mutex_lock(&p->env->mut_forks[next_fork]);
	tts = timestamp(p->env);
	return (print_status(p, tts, STATUS_TAKE_FORK, TRUE));
}

int
	eat(t_philo *p)
{
	pthread_mutex_lock(&p->mut_eat);
	p->eating = TRUE;
	p->last_meal = timestamp(p->env);
	pthread_mutex_unlock(&p->mut_eat);
	if (!print_status(p, p->last_meal, STATUS_EATING, TRUE))
		return (FALSE);
	sleep_ms(p->env->tt_eat);
	pthread_mutex_lock(&p->mut_eat);
	p->eat_count += 1;
	p->die_at = p->last_meal + p->env->tt_die;
	p->eating = FALSE;
	pthread_mutex_unlock(&p->mut_eat);
	return (TRUE);
}

int
	think(t_philo *p)
{
	int		tts;

	tts = timestamp(p->env);
	return (print_status(p, tts, STATUS_THINKING, TRUE));
}

int
	go_bed(t_philo *p)
{
	print_status(p, timestamp(p->env), STATUS_SLEEPING, TRUE);
	pthread_mutex_unlock(&(p->env->mut_forks[p->left_fork]));
	pthread_mutex_unlock(&(p->env->mut_forks[p->right_fork]));
	sleep_ms(p->env->tt_sleep);
	return (TRUE);
}
