/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:54:11 by adda-sil          #+#    #+#             */
/*   Updated: 2021/11/15 08:41:43 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
 ** Includes
 **/
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

/**
 ** Constants
 **/
# define TRUE					1
# define FALSE					0
# define NONE					-1
# define EXIT_FAILURE			1
# define EXIT_SUCCESS			0
# define MS_TO_US				1000
# define LFORK					0b10
# define RFORK					0b01
# define RELEASE_LFORK			0b01
# define RELEASE_RFORK			0b10

# ifndef TTS_START
#  define TTS_START				0
# endif

# ifndef DELAY_THREAD_CREATION
#  define DELAY_THREAD_CREATION	0
# endif

# ifndef USE_PRINTF
#  define USE_PRINTF			0
# endif

/**
 ** Errors
 **/
# define ERR_ARGS_COUNT			"Error: args count\n"
# define ERR_ARG_NEG			"Error: argument '%s' can't be negative\n"
# define ERR_MORE_PHILOS		"Error: can't have more than 200 philos\n"
# define ERR_LESS_PHILOS		"Error: can't have less than 1 philos\n"
# define ERR_INIT_PHILOS		"Error: can't init philos\n"
# define ERR_INIT_FORKS			"Error: can't init forks\n"
# define ERR_INIT_MUTEX			"Error: can't init mutex\n"
# define ERR_INIT_THREAD		"Error: can't init thread\n"

/**
 ** Status
 **/
# define STATUS_TAKE_FORK		"has taken a fork\n"
# define STATUS_THINKING		"is thinking\n"
# define STATUS_SLEEPING		"is sleeping\n"
# define STATUS_EATING			"is eating\n"
# define STATUS_DEAD			"died\n"
# define ALL_PHILOS_ATE			"all philos ate\n"

/**
 ** Texts
 **/
# define MUST_EAT				"number_of_times_each_philosopher_must_eat"

/**
 ** Structs
 **/

typedef struct s_philo {
	int							id;
	int							left_fork;
	int							right_fork;
	int							eating;
	int							eat_count;
	int							last_meal;
	int							die_at;
	struct s_env				*env;
	pthread_t					tid;
	pthread_mutex_t				mut_eat;
	char						mflag;
}								t_philo;

typedef struct s_env {
	int							all_has_eat;
	int							nb_philo;
	int							tt_eat;
	int							tt_die;
	int							tt_sleep;
	int							nb_eat;
	int							end;
	int							idx;
	int							start_tts;
	t_philo						*philos;
	pthread_mutex_t				mut_writer;
	pthread_mutex_t				mut_end;
	pthread_mutex_t				*mut_forks;
	pthread_mutex_t				mut_init;
}								t_env;

typedef void					*(*t_routine)(void *);

/**
 ** Prototypes main.c
 **/
int			main(int argc, char**argv);
void		release(t_env *e);
int			should_stop_simulation(t_env *e);
int			create_threads(t_env *e);

/**
 ** Prototypes setup.c
 **/
int			args_are_valids(t_env *e, int argc, char **argv);
int			check_args(t_env *e);
int			setup_philos(t_env *e);

/**
 ** Prototypes routine.c
 **/
void		*run_routine(t_philo *p);

/**
 ** Prototypes actions.c
 **/
int			take_fork(t_philo *t);
int			eat(t_philo *t);
int			think(t_philo *t);
int			go_bed(t_philo *t);
void		*drop_forks(t_philo *p);

/**
 ** Prototypes prints.c
 **/
int			print_status(t_philo *p, char *txt);
int			print_fatal(t_env *e, char *txt);

/**
 ** Prototypes utils.c
 **/
int			ft_atoi(const char *str);
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_itoa(char *buff, int value, char *base, int base_size);
int			ft_strlen(char *str);

/**
 ** Prototypes time.c
 **/
uint64_t	real_timestamp(void);
int			timestamp(t_env *e);
void		sleep_ms(int ms, t_env *e);

/**
 ** Prototypes clean.c
 **/
int			clean_env(t_env *e);

#endif
