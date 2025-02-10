/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:41:48 by doferet           #+#    #+#             */
/*   Updated: 2025/02/10 15:26:47 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		ft_usleep(1);
	if (philo->nbr_of_philo == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		safe_print("has taken a fork", philo);
		ft_usleep(philo->time_to_die);
		safe_print("died", philo);
		pthread_mutex_unlock(&philo->right_fork);
		return (NULL);
	}
	while (!safe_death(philo))
	{
		if (philo->full)
			break ;
		if (safe_death(philo) == true)
			return (NULL);
		philo_eat(philo);
		if (safe_death(philo) == true)
			return (NULL);
		philo_sleep(philo);
		if (safe_death(philo) == true)
			return (NULL);
		philo_think(philo);
	}
	return (NULL);
}
