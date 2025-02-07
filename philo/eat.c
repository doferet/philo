/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:00:20 by doferet           #+#    #+#             */
/*   Updated: 2025/02/07 18:32:22 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_full(t_philo *philo)
{
	int	i;
	int	finish;

	i = 0;
	finish = 0;
	if (philo->count_meal >= philo->must_eat)
	{
		while (i < philo->nbr_of_philo)
		{
			finish++;
			pthread_mutex_lock(&philo->dead);
			philo[i].full = true;
			pthread_mutex_unlock(&philo->dead);
			i++;
			if (finish == philo->nbr_of_philo)
				break ;
		}
			//philo->full = true;
	}
	return (philo->full);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (safe_death(philo) == true)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	safe_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->right_fork);
	if (safe_death(philo) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return (pthread_mutex_unlock(philo->left_fork), (void) NULL);
	}
	safe_print("has taken a fork", philo);
	if (safe_death(philo) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return (pthread_mutex_unlock(philo->left_fork), (void) NULL);
	}
	safe_print("is eating", philo);
	philo->count_meal++;
	philo->time_last_meal = get_current_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
