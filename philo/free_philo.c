/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:31:16 by doferet           #+#    #+#             */
/*   Updated: 2025/02/10 18:31:49 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo)
{
	// pthread_mutex_destroy(philo->left_fork);
	// pthread_mutex_destroy(&philo->right_fork);
	pthread_mutex_destroy(&philo->msg);
	pthread_mutex_destroy(&philo->dead);
	free(philo->left_fork);
	free(philo);
}
