/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:04:52 by doferet           #+#    #+#             */
/*   Updated: 2025/02/07 15:42:18 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_print(char *msg, t_philo *philo)
{
	int	time;

	time = get_current_time() - philo->start_simulation;
	pthread_mutex_lock(&philo->msg);
	printf("%d %d %s\n", time, philo->philo_id, msg);
	pthread_mutex_unlock(&philo->msg);
}
