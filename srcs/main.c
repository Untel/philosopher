/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 22:13:13 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 **	create_threads
 **/
int
	create_threads(t_env *e)
{
	int			i;
	t_philo		*p;

	i = -1;
	while (++i < e->nb_philo)
	{
		p = &(e->philos[i]);
		// printf("Philo %d ref is %p\n", p->id, p);
		// printf("Creating philo %d tread\n\n", i);
		// print_philo(p);
		if (pthread_create(&(p->tid), NULL, &run_routine, (void *)p) != 0)
			return (FALSE);
		pthread_detach(p->tid);
		sleep_ms(100);
	}
	return (TRUE);
}

/**
 **	Main
 **/
int
	main(int argc, char **argv)
{
	t_env	e;

	if (!args_are_valids(&e, argc, argv))
		return (EXIT_FAILURE);
	print_env(&e);
	printf("\n\n\n\nSTART ROUTINE\n\n\n\n");
	create_threads(&e);
	while (!e.end);
	clean_env(&e);
	return (EXIT_SUCCESS);
}
