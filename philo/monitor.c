/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:00:02 by doferet           #+#    #+#             */
/*   Updated: 2025/02/25 15:08:42 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_full(t_philo *philo, t_mutex *mutex)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < philo->nbr_of_philo)
	{
		pthread_mutex_lock(&mutex->meal);
		if (philo->count_meal >= philo->must_eat + 1)
			count++;
		pthread_mutex_unlock(&mutex->meal);
		i++;
	}
	i = -1;
	if (count == philo->nbr_of_philo)
	{
		while (++i < philo->nbr_of_philo)
		{
			pthread_mutex_lock(&mutex->meal);
			philo[i].full = true;
			pthread_mutex_unlock(&mutex->meal);
		}
		return (true);
	}
	return (false);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo_die(philo, philo->mutex) == true)
			break ;
		if (philo->must_eat != -1)
		{
			if (philo_full(philo, philo->mutex) == true)
				break ;
		}
	}
	return (NULL);
}
