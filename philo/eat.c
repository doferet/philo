/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:00:20 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 18:24:45 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// faire une fonction ou les philo paires mange et les impaires attendent
// utiliser mutex lock et unlock pour bloquer ou liberer les fourchettes
// si les philo ne mangent pas, et qu ils ont deja dormi, ils pensent

void    philo_eat(t_philo *philo)
{
    si tous les philos sont en vie alors // if (is_alive(philo->nbr_of_philo) == 0)
    {
        un philo prend une fourchette
        pthread_mutex_lock
        printf(philo "has taken a fork");
    }
}