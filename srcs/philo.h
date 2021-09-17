/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:54:11 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/17 23:40:24 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
 ** Includes
 **/
# include <stdio.h>

/**
 ** Constants
 **/
# define TRUE					1
# define FALSE					0
# define NONE					-1
# define EXIT_FAILURE			1
# define EXIT_SUCCESS			0

/**
 ** Texts
 **/
# define ERR_ARGS_COUNT			"Error: args count"
# define STATUS_TAKE_FORK		"%d %d has taken a fork"
# define STATUS_THINKING		"%d %d is thinking"
# define STATUS_SLEEPING		"%d %d is sleeping"
# define STATUS_EATING			"%d %d is eating"
# define STATUS_DEAD			"%d %d died"

/**
 ** Structs
 **/
typedef struct s_data {
	int							nb_philo;
	int							tt_eat;
	int							tt_die;
	int							tt_sleep;
	int							nb_eat;
}								t_data;

/**
 ** Prototypes main.c
 **/
int								main(int argc, char**argv);

/**
 ** Prototypes utils.c
 **/
int								t_atoi(const char *str);
void							print_data(t_data *d);
#endif