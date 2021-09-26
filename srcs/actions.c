/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:20:41 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 19:38:21 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	take_fork(t_philo *p)
{
	pthread_mutex_lock(&p->env->mut_forks[p->left_fork]);
	printf(STATUS_TAKE_FORK, timestamp(), p->id);
	pthread_mutex_lock(&p->env->mut_forks[p->right_fork]);
	printf(STATUS_TAKE_FORK, timestamp(), p->id);
}

void
	eat(t_philo *p)
{
	printf(STATUS_EATING, timestamp(), p->id);
	usleep(p->env->tt_eat * 1000);
}

void
	think(t_philo *p)
{
	printf(STATUS_THINKING, timestamp(), p->id);
}

void
	go_bed(t_philo *p)
{
	pthread_mutex_unlock(&p->env->mut_forks[p->right_fork]);
	pthread_mutex_unlock(&p->env->mut_forks[p->left_fork]);
	printf(STATUS_SLEEPING, timestamp(), p->id);
	usleep(p->env->tt_sleep * 1000);
}
