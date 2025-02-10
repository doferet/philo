/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:00:48 by doferet           #+#    #+#             */
/*   Updated: 2025/02/10 18:40:34 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//verifier si un philo est mort, si oui, le programme s'arrete

bool	philo_die(t_philo *philo)
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
			philo[i].is_dead = true;
			i++;
		}
		safe_print("died", philo);
	}	
	return (philo->is_dead);
}
//tmps actuel - tmps dernier repas > tmps mourir alors is dead true