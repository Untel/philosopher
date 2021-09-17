/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/17 23:29:39 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 ** args_are_valids
 **/
int
	args_are_valids(t_data *d, int argc, char **argv)
{
	(void) argv;
	if (argc < 5 || argc > 6)
		return (printf(ERR_ARGS_COUNT) && FALSE);
	d->nb_philo = ft_atoi(argv[1]);
	d->tt_eat = ft_atoi(argv[2]);
	d->tt_die = ft_atoi(argv[3]);
	d->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->nb_eat = ft_atoi(argv[5]);
	else
		d->nb_eat = NONE;
	return (TRUE);
}

/**
 **	Main
 **/
int
	main(int argc, char **argv)
{
	t_data	d;

	if (!args_are_valids(&d, argc, argv))
		return (EXIT_FAILURE);
	print_data(&d);
	return (EXIT_SUCCESS);
}
