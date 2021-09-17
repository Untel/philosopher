/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:54:11 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/17 22:24:20 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>

# define TRUE					1
# define FALSE					0
# define EXIT_FAILURE			FALSE

typedef struct s_data {
	int							nb_philo;
	int							tt_eat;
	int							tt_sleep;
	int							nb_eat;
}								t_data;

#endif