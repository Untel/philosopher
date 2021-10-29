/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:20:41 by adda-sil          #+#    #+#             */
/*   Updated: 2021/10/29 19:49:43 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	take_fork(t_philo *p)
{
	int			first_fork;
	int			next_fork;
	int			tts;

	if (p->id % 2 == 0)
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
	print_status(p, tts, STATUS_TAKE_FORK, TRUE);
	pthread_mutex_lock(&p->env->mut_forks[next_fork]);
	tts = timestamp(p->env);
	print_status(p, tts, STATUS_TAKE_FORK, TRUE);
}

void
	eat(t_philo *p)
{
	int		tts;

	p->eating = TRUE;
	tts = timestamp(p->env);
	print_status(p, tts, STATUS_EATING, TRUE);
	sleep_ms(p->env->tt_eat);
	p->last_meal = timestamp(p->env);
	p->die_at = p->last_meal + p->env->tt_die;
	p->eating = FALSE;
	pthread_mutex_unlock(&p->mut_eat);
}

void
	think(t_philo *p)
{
	int		tts;

	tts = timestamp(p->env);
	print_status(p, tts, STATUS_THINKING, TRUE);
}

void
	go_bed(t_philo *p)
{
	print_status(p, p->last_meal, STATUS_SLEEPING, TRUE);
	pthread_mutex_unlock(&(p->env->mut_forks[p->left_fork]));
	pthread_mutex_unlock(&(p->env->mut_forks[p->right_fork]));
	sleep_ms(p->env->tt_sleep);
}
