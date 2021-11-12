/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:01:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/11 18:51:58 by commetuveux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	print_status(t_philo *p, char *txt)
{
	char	_tts[5000];
	char	_id[5000];
	int		ttslen;
	int		idlen;

	pthread_mutex_lock(&(p->env->mut_end));
	if (p->env->end)
		return (pthread_mutex_unlock(&(p->env->mut_end)) == 0 && FALSE);
	pthread_mutex_lock(&(p->env->mut_writer));
	ttslen = ft_itoa(_tts, timestamp(p->env), "0123456789", 10);
	idlen = ft_itoa(_id, p->id + 1, "0123456789", 10);
	write(1, &(_tts[4096 - ttslen]), ttslen);
	write(1, " ", 1);
	write(1, &(_id[4096 - idlen]), idlen);
	write(1, " ", 1);
	write(1, txt, ft_strlen(txt));
	pthread_mutex_unlock(&(p->env->mut_writer));
	pthread_mutex_unlock(&(p->env->mut_end));
	return (TRUE);
}

int
	print_fatal(t_env *e, char *txt)
{
	pthread_mutex_lock(&(e->mut_writer));
	write(1, txt, ft_strlen(txt));
	return (TRUE);
}
