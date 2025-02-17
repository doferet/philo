/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:00:20 by doferet           #+#    #+#             */
/*   Updated: 2025/02/17 15:19:34 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo, t_mutex *mutex)
{
	pthread_mutex_lock(philo->left_fork);
	if (verif_death_full(philo, mutex) == true)
		return (pthread_mutex_unlock(philo->left_fork), (void) NULL);
	safe_print("has taken a fork", philo, mutex);
	pthread_mutex_lock(&philo->right_fork);
	if (verif_death_full(philo, mutex) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return (pthread_mutex_unlock(philo->left_fork), (void) NULL);
	}
	safe_print("has taken a fork", philo, mutex);
	if (verif_death_full(philo, mutex) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return (pthread_mutex_unlock(philo->left_fork), (void) NULL);
	}
	safe_print("is eating", philo, mutex);
	philo->count_meal++;
	philo->time_last_meal = get_current_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
