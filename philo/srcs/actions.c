/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:20:41 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 16:35:21 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	take_fork(t_philo *p)
{
	int			first_fork;
	int			next_fork;

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
	if (!print_status(p, STATUS_TAKE_FORK))
		return (FALSE);
	pthread_mutex_lock(&p->env->mut_forks[next_fork]);
	return (print_status(p, STATUS_TAKE_FORK));
}

int
	eat(t_philo *p)
{
	pthread_mutex_lock(&p->mut_eat);
	p->eating = TRUE;
	p->last_meal = timestamp(p->env);
	pthread_mutex_unlock(&p->mut_eat);
	if (!print_status(p, STATUS_EATING))
		return (FALSE);
	sleep_ms(p->env->tt_eat);
	pthread_mutex_lock(&p->mut_eat);
	p->eat_count += 1;
	pthread_mutex_lock(&p->env->mut_end);
	p->env->all_has_eat += (p->eat_count == p->env->nb_eat);
	if (p->env->all_has_eat == p->env->nb_philo)
	{
		p->env->end = TRUE;
		pthread_mutex_unlock(&p->mut_eat);
		pthread_mutex_unlock(&p->env->mut_end);
		return (FALSE);
	}
	pthread_mutex_unlock(&p->env->mut_end);
	p->die_at = p->last_meal + p->env->tt_die;
	p->eating = FALSE;
	pthread_mutex_unlock(&p->mut_eat);
	return (TRUE);
}

int
	think(t_philo *p)
{
	return (print_status(p, STATUS_THINKING));
}

int
	go_bed(t_philo *p)
{
	print_status(p, STATUS_SLEEPING);
	pthread_mutex_unlock(&(p->env->mut_forks[p->left_fork]));
	pthread_mutex_unlock(&(p->env->mut_forks[p->right_fork]));
	sleep_ms(p->env->tt_sleep);
	return (TRUE);
}
