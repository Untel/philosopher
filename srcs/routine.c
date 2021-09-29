/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:35:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 22:26:21 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 ** run_routine
 **/
void
	*run_routine(void *addr)
{
	t_philo	*p;

	p = (t_philo *)addr;
	// printf("=> Philo %d ref is %p\n", p->id, p);
	p->last_meal = timestamp();
	p->die_at = p->last_meal + p->env->tt_die;
	while (1)
	{
		// printf("END OF DAY Philo %d ref is %p\n\n\n\n", p->id, p);
		
		take_fork(p);
		eat(p);
		go_bed(p);
		think(p);
	}
	return (NULL);
}
