/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:41:48 by doferet           #+#    #+#             */
/*   Updated: 2025/02/07 15:33:26 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		ft_usleep(1);
	while (philo->is_dead == false)
	{
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
