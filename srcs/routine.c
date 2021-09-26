/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:35:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 17:43:16 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 ** run_routine
 **/
int
	run_routine(t_env *e)
{
	while (e->turn < 200)
	{
		printf("T(%d) %llu \n", e->turn, timestamp());
		usleep(1000000);
		e->turn += 1;
	}
	return (TRUE);
}
