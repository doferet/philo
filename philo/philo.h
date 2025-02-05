/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:07:02 by doferet           #+#    #+#             */
/*   Updated: 2025/02/05 18:13:30 by doferet          ###   ########.fr       */
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

typedef struct s_philo
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
	int				philo_id;
	size_t			time_last_meal;
	bool			full;
	bool			is_dead;
	pthread_t		thread_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

/****** INIT ********/
int					initialization(t_philo *philo, char **av);

/****** PARSING ********/
void				parse_input(t_philo *philo, char **av);

/****** ROUTINE ********/
void				*routine(void *arg);

/****** ERROR ********/
int					check_error(const char *error);

/****** UTILS ********/
long				ft_atol(char *str);
size_t				get_current_time(void);
int					ft_usleep(size_t milliseconds);

#endif
