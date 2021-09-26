/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:54:11 by adda-sil          #+#    #+#             */
/*   Updated: 2021/09/26 17:43:35 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
 ** Includes
 **/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
# define ERR_ARGS_COUNT			"Error: args count\n"
# define STATUS_TAKE_FORK		"%llu %d has taken a fork\n"
# define STATUS_THINKING		"%llu %d is thinking\n"
# define STATUS_SLEEPING		"%llu %d is sleeping\n"
# define STATUS_EATING			"%llu %d is eating\n"
# define STATUS_DEAD			"%llu %d died\n"

/**
 ** Structs
 **/
typedef struct s_env {
	int							nb_philo;
	int							tt_eat;
	int							tt_die;
	int							tt_sleep;
	int							nb_eat;
	int							turn;
}								t_env;

typedef struct s_philo {
	int							nb_philo;
	t_env						env;
}								t_philo;

/**
 ** Prototypes main.c
 **/
int								main(int argc, char**argv);

/**
 ** Prototypes routine.c
 **/
int								run_routine(t_env *e);

/**
 ** Prototypes utils.c
 **/
int								ft_atoi(const char *str);
void							print_env(t_env *e);
uint64_t						timestamp(void);
#endif