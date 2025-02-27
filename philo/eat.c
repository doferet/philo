/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:00:20 by doferet           #+#    #+#             */
/*   Updated: 2025/02/26 12:08:28 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_even_and_odd(t_philo *philo, t_mutex *mutex)
{
	if (philo->philo_id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		if (verif_death_full(philo, philo->mutex) == true)
			return (pthread_mutex_unlock(philo->left_fork), (void) NULL);
		safe_print("has taken a fork", philo, mutex);
		pthread_mutex_lock(&philo->right_fork);
		if (verif_death_full(philo, philo->mutex) == true)
			return (pthread_mutex_unlock(philo->left_fork),
				pthread_mutex_unlock(&philo->right_fork), (void) NULL);
		safe_print("has taken a fork", philo, mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork);
		if (verif_death_full(philo, philo->mutex) == true)
			return (pthread_mutex_unlock(&philo->right_fork), (void) NULL);
		safe_print("has taken a fork", philo, mutex);
		pthread_mutex_lock(philo->left_fork);
		if (verif_death_full(philo, philo->mutex) == true)
			return (pthread_mutex_unlock(philo->left_fork),
				pthread_mutex_unlock(&philo->right_fork), (void) NULL);
		safe_print("has taken a fork", philo, mutex);
	}
}

void	philo_eat(t_philo *philo, t_mutex *mutex)
{
	philo_even_and_odd(philo, mutex);
	pthread_mutex_lock(&mutex->meal);
	philo->time_last_meal = get_current_time();
	pthread_mutex_unlock(&mutex->meal);
	if (verif_death_full(philo, philo->mutex) == true)
		return ;
	safe_print("is eating", philo, mutex);
	ft_usleep(philo, philo->time_to_eat);
	pthread_mutex_lock(&mutex->meal);
	philo->count_meal++;
	pthread_mutex_unlock(&mutex->meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}
