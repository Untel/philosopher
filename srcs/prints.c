/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:01:10 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/30 01:50:25 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	print_status(t_philo *p, uint64_t tts, char *txt, int unlock)
{
	pthread_mutex_lock(&(p->env->mut_writer));
	if (p->env->end)
		return (FALSE);
	printf(txt, tts, p->id + 1);
	if (unlock)
		pthread_mutex_unlock(&(p->env->mut_writer));
	return (TRUE);
}

int
	print_info(t_env *e, char *txt)
{
	pthread_mutex_lock(&(e->mut_writer));
	printf(txt, timestamp(e));
	pthread_mutex_unlock(&(e->mut_writer));
	return (TRUE);
}

int
	print_death(t_philo *p, char *txt)
{
	pthread_mutex_lock(&(p->env->mut_writer));
	printf(txt, timestamp(p->env), p->id + 1);
	return (TRUE);
}

int
	print_fatal(t_env *e, char *txt)
{
	pthread_mutex_lock(&(e->mut_writer));
	printf(txt, timestamp(e));
	return (TRUE);
}
