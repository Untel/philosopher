/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:20:41 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 22:31:46 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	print_status(t_philo *p, char *txt)
{
	pthread_mutex_lock(&(p->env->mut_writer));
	printf(txt, timestamp(), p->id);
	pthread_mutex_unlock(&(p->env->mut_writer));
}

void
	take_fork(t_philo *p)
{
	pthread_mutex_lock(&p->env->mut_forks[p->left_fork]);
	print_status(p, STATUS_TAKE_FORK);
	pthread_mutex_lock(&p->env->mut_forks[p->right_fork]);
	print_status(p, STATUS_TAKE_FORK);
}

void
	eat(t_philo *p)
{
	print_status(p, STATUS_EATING);
	p->eating = TRUE;
	sleep_ms(p->env->tt_eat);
	p->eating = FALSE;
	p->eat_count += 1;
	p->last_meal = timestamp();
	p->die_at = p->last_meal + p->env->tt_die;
	// print_status(p, CUSTOM_STATUS);
}

void
	think(t_philo *p)
{
	print_status(p, STATUS_THINKING);
}

void
	go_bed(t_philo *p)
{
	print_status(p, STATUS_SLEEPING);
	pthread_mutex_unlock(&(p->env->mut_forks[p->left_fork]));
	pthread_mutex_unlock(&(p->env->mut_forks[p->right_fork]));
	sleep_ms(p->env->tt_sleep);
}
