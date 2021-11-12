/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:21:59 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 16:05:46 by commetuveux      ###   ########.fr       */
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
	sleep_ms(int ms)
{
	uint64_t	t;

	t = real_timestamp() + ms;
	while (real_timestamp() < t)
		usleep((useconds_t) ms);
}
