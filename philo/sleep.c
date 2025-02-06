/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:54 by doferet           #+#    #+#             */
/*   Updated: 2025/02/06 12:00:06 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//une fois que les philo ont mangé et qu'ils ont posé leurs fouchettes 
//ils dorment

void    philo_sleep(t_philo *philo)
{
	//si on est pas arrivé au temps pour dormir on dort ?
	//When they sleep we need to make them sleep the length of the input
	//using our ft_usleep and then print the message “X is sleeping”
    printf("%d\n is sleeping", philo->nbr_of_philo);
}