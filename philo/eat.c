/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:00:20 by doferet           #+#    #+#             */
/*   Updated: 2025/02/25 12:50:36 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo, t_mutex *mutex)
{
	if (philo->philo_id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		safe_print("has taken a fork", philo, mutex);
		pthread_mutex_lock(&philo->right_fork);
		safe_print("has taken a fork", philo, mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork);
		safe_print("has taken a fork", philo, mutex);
		pthread_mutex_lock(philo->left_fork);
		safe_print("has taken a fork", philo, mutex);
	}
	pthread_mutex_lock(&mutex->meal);
	philo->time_last_meal = get_current_time();
	pthread_mutex_unlock(&mutex->meal);
	safe_print("is eating", philo, mutex);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(&mutex->meal);
	philo->count_meal++;
	pthread_mutex_unlock(&mutex->meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}
