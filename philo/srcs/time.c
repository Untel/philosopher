/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:21:59 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 21:39:35 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t
	real_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int
	timestamp(t_env *e)
{
	return (real_timestamp() - e->start_tts);
}

void
	sleep_ms(int ms, t_env *e)
{
	uint64_t	t;
	int			ret;

	t = real_timestamp() + ms;
	while (real_timestamp() < t)
	{
		pthread_mutex_lock(&e->mut_end);
		ret = e->end;
		pthread_mutex_unlock(&e->mut_end);
		if (ret)
			break ;
		usleep(150);
	}
}
