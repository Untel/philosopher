/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 17:43:01 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 ** args_are_valids
 **/
int
	args_are_valids(t_env *e, int argc, char **argv)
{
	(void) argv;
	if (argc < 5 || argc > 6)
		return (printf(ERR_ARGS_COUNT) && FALSE);
	e->nb_philo = ft_atoi(argv[1]);
	e->tt_eat = ft_atoi(argv[2]);
	e->tt_die = ft_atoi(argv[3]);
	e->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		e->nb_eat = ft_atoi(argv[5]);
	else
		e->nb_eat = NONE;
	e->turn = 0;
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
	run_routine(&e);
	return (EXIT_SUCCESS);
}
