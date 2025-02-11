/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:23:16 by doferet           #+#    #+#             */
/*   Updated: 2025/02/11 18:17:43 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo[PHILO_MAX];
	t_mutex	mutex;

	if (check_error(ac, av))
		return (0);
	initialization(philo, &mutex, av);
	free_philo(&mutex);
	return (0);
}
