/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:01:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/03 01:18:38 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	print_status(t_philo *p, int tts, char *txt, int unlock)
{
	char	_tts[5000];
	char	_id[5000];
	int		ttslen;
	int		idlen;

	pthread_mutex_lock(&(p->env->mut_writer));
	if (p->env->end) {
		pthread_mutex_unlock(&(p->env->mut_writer));
		return (FALSE);
	}
	p->env->end = !unlock;
	ttslen = ft_itoa(_tts, tts, "0123456789", 10);
	idlen = ft_itoa(_id, p->id + 1, "0123456789", 10);
	write(1, &(_tts[4096 - ttslen]), ttslen);
	write(1, " ", 1);
	write(1, &(_id[4096 - idlen]), idlen);
	write(1, " ", 1);
	write(1, txt, ft_strlen(txt));
	pthread_mutex_unlock(&(p->env->mut_writer));
	return (TRUE);
}

int
	print_fatal(t_env *e)
{
	pthread_mutex_lock(&(e->mut_writer));
	e->end = TRUE;
	write(1, "all philos ate\n", 16);
	// printf("%d all philos ate %d times\n", timestamp(e), e->nb_eat);
	pthread_mutex_unlock(&(e->mut_writer));
	return (TRUE);
}
