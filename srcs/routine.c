/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:35:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 20:33:49 by adda-sil         ###   ########.fr       */
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

	printf("In hilo thread %d\n\n", p->id);
	print_philo(p);
	while (!p->env->end)
	{
		eat(p);
		go_bed(p);
		think(p);
	}
	return (NULL);
}
