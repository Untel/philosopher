/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: commetuveux <commetuveux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:54:11 by adda-sil          #+#    #+#             */
/*   Updated: 2021/10/07 00:39:00 by commetuveux      ###   ########.fr       */
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
# include <pthread.h>

/**
 ** Constants
 **/
# define TRUE					1
# define FALSE					0
# define NONE					-1
# define EXIT_FAILURE			1
# define EXIT_SUCCESS			0
# define MS_TO_US				1000

# ifndef TTS_START
#  define TTS_START				0
# endif

# ifndef DELAY_THREAD_CREATION
#  define DELAY_THREAD_CREATION	0
# endif

/**
 ** Errors
 **/
# define ERR_ARGS_COUNT			"Error: args count\n"
# define ERR_ARG_NEG			"Error: argument '%s' can't be negative\n"
# define ERR_MORE_PHILOS		"Error: can't have more than 200 philos\n"
# define ERR_LESS_PHILOS		"Error: can't have less than 2 philos\n"
# define ERR_INIT_PHILOS		"Error: can't init philos\n"
# define ERR_INIT_FORKS			"Error: can't init forks\n"

/**
 ** Status
 **/
# define STATUS_TAKE_FORK		"%llu %d has taken a fork\n"
# define STATUS_THINKING		"%llu %d is thinking\n"
# define STATUS_SLEEPING		"%llu %d is sleeping\n"
# define STATUS_EATING			"%llu %d is eating\n"
# define STATUS_DEAD			"%llu %d died\n"
# define SHOULD_DIE				"%llu %d should die but is eating\n"
# define CUSTOM_STATUS			"%llu %d checkpoint\n"
# define ALL_PHILOS_ATE			"%llu all philos ate\n"
# define HAS_LUNCH				"%llu %d has lunch\n"

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
	uint64_t					last_meal;
	uint64_t					die_at;
	struct s_env				*env;
	pthread_t					tid;
	pthread_t					liveness_tid;
	pthread_mutex_t				mut_eat;
}								t_philo;

typedef struct s_env {
	int							nb_philo;
	int							tt_eat;
	int							tt_die;
	int							tt_sleep;
	int							nb_eat;
	int							turn;
	int							end;
	uint64_t					start_tts;
	t_philo						*philos;
	pthread_mutex_t				mut_writer;
	pthread_mutex_t				mut_end;
	pthread_mutex_t				*mut_forks;
	pthread_t					eat_count_tid;
}								t_env;

/**
 ** Prototypes main.c
 **/
int			main(int argc, char**argv);

/**
 ** Prototypes setup.c
 **/
int			args_are_valids(t_env *e, int argc, char **argv);
int			check_args(t_env *e);
int			setup_philos(t_env *e);

/**
 ** Prototypes routine.c
 **/
void		*run_routine(void *p);
void		*liveness_routine(void *p);
void		*eat_count_routine(void *p);

/**
 ** Prototypes actions.c
 **/
void		take_fork(t_philo *t);
void		eat(t_philo *t);
void		think(t_philo *t);
void		go_bed(t_philo *t);

/**
 ** Prototypes prints.c
 **/
int			print_status(t_philo *p, uint64_t tts, char *txt, int unlock);
int			print_fatal(t_env *e, char *txt);
int			print_death(t_philo *p, char *txt);
int			print_info(t_env *e, char *txt);

/**
 ** Prototypes utils.c
 **/
int			ft_atoi(const char *str);
int			ft_isspace(int c);
int			ft_isdigit(int c);

/**
 ** Prototypes time.c
 **/
uint64_t	real_timestamp(void);
uint64_t	timestamp(t_env *e);
void		sleep_ms(int ms);

/**
 ** Prototypes clean.c
 **/
int			clean_env(t_env *e);

/**
 ** Prototypes debug.c
 **/
int			print_env(t_env *e);
int			print_philo(t_philo *p);
#endif