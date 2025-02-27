/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:42:47 by doferet           #+#    #+#             */
/*   Updated: 2025/02/27 14:26:20 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	if (verif_death_full(philo, philo->mutex))
		return ;
	if (philo->time_to_die != philo->time_to_eat + philo->time_to_sleep)
		usleep(500);
	safe_print("is thinking", philo, philo->mutex);
}
