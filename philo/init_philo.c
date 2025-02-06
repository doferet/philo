/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:33:39 by doferet           #+#    #+#             */
/*   Updated: 2025/02/06 18:09:26 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//dans ce fichier, je dois creer mes PHILO donc les THREAD
//initialisation des variables

void	monitor(t_philo *philo)
{
	while(1)
	{
		if (philo_die(philo) == true || philo->full)
			break;
	}
}

int	philo_run(t_philo *philo)
{
	int	i;

	i = 0;
	monitor(philo);
	while (i < philo[0].nbr_of_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo[0].nbr_of_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (0);
}

int	initialization(t_philo *philo, char **av)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * ft_atol(av[1]));
	while (i < ft_atol(av[1]))
	{
		parse_input(&philo[i], av);
		philo[i].full = false;
		philo[i].is_dead = false;
		philo[i].time_last_meal = get_current_time();
		philo[i].start_simulation = get_current_time();
		philo[i].count_meal = 0;
		philo[i].philo_id = i + 1;
		if (i < philo[0].nbr_of_philo - 1)
			philo[i].left_fork = &philo[i + 1].right_fork;
		else
			philo[i].left_fork = &philo[0].right_fork;
		if (pthread_mutex_init(&philo[i].right_fork, NULL) != 0)
			return (false);
		if (pthread_mutex_init(&philo[i].msg, NULL) != 0)
			return (false);
		i++;
	}
	philo_run(philo);
	return (true);
}

