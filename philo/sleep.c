/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:54 by doferet           #+#    #+#             */
/*   Updated: 2025/02/11 15:17:53 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	if (verif_death_full(philo, philo->mutex))
		return ;
	safe_print("is sleeping", philo, philo->mutex);
	ft_usleep(philo->time_to_sleep);
}
