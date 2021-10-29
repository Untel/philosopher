/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:01:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/10/29 18:18:10 by adda-sil         ###   ########.fr       */
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
	if (p->env->end)
		return (FALSE);
	ttslen = ft_itoa(_tts, tts, "0123456789", 10);
	idlen = ft_itoa(_id, p->id + 1, "0123456789", 10);
	write(0, &(_tts[4096 - ttslen]), ttslen);
	write(0, " ", 1);
	write(0, &(_id[4096 - idlen]), idlen);
	write(0, " ", 1);
	write(0, txt, ft_strlen(txt));
	if (unlock)
		pthread_mutex_unlock(&(p->env->mut_writer));
	return (TRUE);
}

int
	print_fatal(t_env *e, char *txt)
{
	pthread_mutex_lock(&(e->mut_writer));
	write(0, txt, ft_strlen(txt));
	return (TRUE);
}
