/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:41:48 by doferet           #+#    #+#             */
/*   Updated: 2025/02/26 12:08:44 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo, 1);
	while (!verif_death_full(philo, philo->mutex))
	{
		if (verif_death_full(philo, philo->mutex) == true)
			return (NULL);
		philo_eat(philo, philo->mutex);
		if (verif_death_full(philo, philo->mutex) == true)
			return (NULL);
		philo_sleep(philo);
		if (verif_death_full(philo, philo->mutex) == true)
			return (NULL);
		philo_think(philo);
	}
	return (NULL);
}
