/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:54 by doferet           #+#    #+#             */
/*   Updated: 2025/02/06 17:27:36 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//une fois que les philo ont mangé et qu'ils ont posé leurs fouchettes 
//ils dorment

void    philo_sleep(t_philo *philo)
{
    safe_print("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}