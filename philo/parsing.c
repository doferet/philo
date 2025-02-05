/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:14:44 by doferet           #+#    #+#             */
/*   Updated: 2025/02/05 18:05:57 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_philo *philo, char **av)
{
	philo->nbr_of_philo = atoi(av[1]);
	philo->time_to_die = atoi(av[2]);
	philo->time_to_eat = atoi(av[3]);
	philo->time_to_sleep = atoi(av[4]);
	if (av[5])
		philo->must_eat = atoi(av[5]);
	else
		philo->must_eat = -1;
}
