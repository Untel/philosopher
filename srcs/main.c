/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:53:20 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/17 22:25:08 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	args_are_valids(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	return (TRUE);
}

int
	main(int argc, char **argv)
{
	if (!args_are_valids(argc, argv))
		return (EXIT_FAILURE);
	printf("Yo les potes");
}
