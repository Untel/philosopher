/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:12:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 22:01:13 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	print_env(t_env *d)
{
	printf("-------------------------------------------------------\n");
	printf("Args: nb_philo (%d) | tt_eat (%d)", d->nb_philo, d->tt_eat);
	printf("| tt_die (%d) | tt_sleep (%d)", d->tt_die, d->tt_sleep);
	printf("| nb_eat (%d)\n", d->nb_eat);
	printf("-------------------------------------------------------\n");
}

void
	print_philo(t_philo *t)
{
	printf("-------------------------------------------------------\n");
	printf("Philo id %d\n", t->id);
	printf("lf %d | rf %d\n", t->left_fork, t->right_fork);
	printf("Last meal (%d): %llu | die at %llu\n", t->eating, t->last_meal, t->die_at);
	printf("-------------------------------------------------------\n");
}
