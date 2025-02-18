/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:00:02 by doferet           #+#    #+#             */
/*   Updated: 2025/02/18 14:51:40 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_full(t_philo *philo, t_mutex *mutex)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (philo->must_eat == -1)
		return (false);
	while (i < philo->nbr_of_philo)
	{
		if (philo->count_meal >= philo->must_eat + 1)
			count++;
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
		if (philo_die(philo, philo->mutex) == true
			|| philo_full(philo, philo->mutex))
			break ;
		if (philo->must_eat)
			ft_usleep(1);
	}
	return (NULL);
}
