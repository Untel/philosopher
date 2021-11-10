/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:50:26 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/10 17:52:49 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	clean_env(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->idx)
	{
		pthread_mutex_destroy(&(e->mut_forks[i]));
		pthread_mutex_destroy(&(e->philos[i].mut_eat));
	}
	free(e->philos);
	free(e->mut_forks);
	return (TRUE);
}
