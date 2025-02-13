/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:00:48 by doferet           #+#    #+#             */
/*   Updated: 2025/02/12 11:20:59 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_die(t_philo *philo, t_mutex *mutex)
{
	int	i;

	i = 0;
	if (philo->full)
		return (false);
	if (get_current_time() - philo->time_last_meal > (size_t)philo->time_to_die)
	{
		while (i < philo->nbr_of_philo)
		{
			if (philo->nbr_of_philo == 1)
				break ;
			pthread_mutex_lock(&philo->mutex->dead);
			philo[i].is_dead = true;
			pthread_mutex_unlock(&philo->mutex->dead);
			i++;
		}
		safe_print("died", philo, mutex);
		return (true);
	}	
	return (false);
}
