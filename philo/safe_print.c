/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:04:52 by doferet           #+#    #+#             */
/*   Updated: 2025/02/17 13:22:59 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_print(char *msg, t_philo *philo, t_mutex *mutex)
{
	int	time;

	pthread_mutex_lock(&mutex->msg);
	time = get_current_time() - philo->start_simulation;
	if (philo->full)
		return ;
	printf("%d %d %s\n", time, philo->philo_id, msg);
	pthread_mutex_unlock(&mutex->msg);
}
