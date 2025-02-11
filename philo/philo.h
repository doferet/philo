/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:07:02 by doferet           #+#    #+#             */
/*   Updated: 2025/02/11 19:17:40 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 300

typedef struct s_philo
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
	int				philo_id;
	size_t			time_last_meal;
	int				start_simulation;
	int				count_meal;
	bool			full;
	bool			is_dead;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	struct s_mutex	*mutex;
}					t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	msg;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
	t_philo			*philo;
}				t_mutex;

/****** INIT ********/
int					initialization(t_philo *philo, t_mutex *mutex, char **av);

/****** PARSING ********/
void				parse_input(t_philo *philo, char **av);

/****** ROUTINE ********/
void				*routine(void *arg);
void				philo_eat(t_philo *philo, t_mutex *mutex);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);
bool				philo_die(t_philo *philo, t_mutex *mutex);
void				*monitor(void *arg);

/****** RUN ********/
int					philo_run(t_philo *philo);

/****** ERROR ********/
bool				check_error(int ac, char **av);

/****** UTILS ********/
long				ft_atol(char *str);
size_t				get_current_time(void);
int					ft_usleep(size_t milliseconds);
void				safe_print(char *msg, t_philo *philo, t_mutex *mutex);
bool				verif_death_full(t_philo *philo, t_mutex *mutex);
int					ft_isdigit(char *str);

/****** FREE ********/
void				free_philo(t_mutex *mutex);

#endif
