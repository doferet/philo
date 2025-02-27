/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:00:48 by doferet           #+#    #+#             */
/*   Updated: 2025/02/27 12:38:08 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	safe_condition(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->meal);
	if (get_current_time() - philo->time_last_meal > (size_t)philo->time_to_die)
		return (pthread_mutex_unlock(&philo->mutex->meal), true);
	return (pthread_mutex_unlock(&philo->mutex->meal), false);
}

bool	philo_die(t_philo *philo, t_mutex *mutex)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	pthread_mutex_lock(&philo->mutex->meal);
	if (philo->full)
		return (pthread_mutex_unlock(&philo->mutex->meal), false);
	pthread_mutex_unlock(&philo->mutex->meal);
	while (++j < philo->nbr_of_philo)
	{
		if (safe_condition(philo) == true)
		{
			while (++i < philo->nbr_of_philo)
			{
				if (philo->nbr_of_philo == 1)
					break ;
				pthread_mutex_lock(&mutex->dead);
				philo[i].is_dead = true;
				pthread_mutex_unlock(&mutex->dead);
			}
			return (safe_print("died", &philo[j], mutex), true);
		}
	}
	return (false);
}
