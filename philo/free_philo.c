/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:31:16 by doferet           #+#    #+#             */
/*   Updated: 2025/02/11 16:04:36 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_mutex *mutex)
{
	pthread_mutex_destroy(&mutex->dead);
	pthread_mutex_destroy(&mutex->meal);
	pthread_mutex_destroy(&mutex->msg);
}
