/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:07:02 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 18:23:44 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_fork
{
	int	taken;
	int	used;
	pthread_mutex_t fork;
}	t_fork;

typedef struct s_philo
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
	int				philo_id;
	long			last_meal;
	long			count_meal;
	int				end_simulation;
	t_fork			*right_fork;
	t_fork			*left_fork;
}			t_philo;

/****** UTILS ********/
long	ft_atol(char *str);


/******* INIT ********/
int	initialization(t_philo *philo);

/******* ERROR *********/
int    check_error(const char *error);

#endif