/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:33:39 by doferet           #+#    #+#             */
/*   Updated: 2025/02/26 12:08:35 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	one_philo(t_philo *philo)
{
	if (philo->nbr_of_philo == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		safe_print("has taken a fork", philo, philo->mutex);
		ft_usleep(philo, philo->time_to_die);
		safe_print("died", philo, philo->mutex);
		pthread_mutex_unlock(&philo->right_fork);
		return (0);
	}
	return (1);
}

int	philo_run(t_philo *philo)
{
	int			i;
	pthread_t	supervisor;

	i = 0;
	if (pthread_create(&supervisor, NULL, &monitor, &philo->nbr_of_philo) != 0)
		return (1);
	while (i < philo->nbr_of_philo)
	{
		if (pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	if (pthread_join(supervisor, NULL) != 0)
		return (1);
	while (i < philo->nbr_of_philo)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	initialization(t_philo *philo, t_mutex *mutex, char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atol(av[1]))
	{
		parse_input(&philo[i], av);
		philo[i].full = false;
		philo[i].is_dead = false;
		philo[i].time_last_meal = get_current_time();
		philo[i].start_simulation = get_current_time();
		philo[i].count_meal = 0;
		philo[i].mutex = mutex;
		philo[i].philo_id = i + 1;
		if (i < philo[0].nbr_of_philo - 1)
			philo[i].left_fork = &philo[i + 1].right_fork;
		else
			philo[i].left_fork = &philo[0].right_fork;
		pthread_mutex_init(&philo[i].right_fork, NULL);
	}
	pthread_mutex_init(&mutex->msg, NULL);
	pthread_mutex_init(&mutex->dead, NULL);
	pthread_mutex_init(&mutex->meal, NULL);
	if (!one_philo(philo))
		return (1);
	return (philo_run(philo), true);
}
