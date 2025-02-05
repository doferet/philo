/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:33:39 by doferet           #+#    #+#             */
/*   Updated: 2025/02/05 18:12:16 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//dans ce fichier, je dois creer mes PHILO donc les THREAD
//initialisation des variables

int	philo_run(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nbr_of_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, philo);
		//pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < philo->nbr_of_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	//pthread_join(philo[i].thread_id, NULL);
	return (0);
}

int	initialization(t_philo *philo, char **av)
{
	int	i;
	t_philo *data;
	(void)av;

	i = 0;
	data = malloc(sizeof(t_philo) * philo->nbr_of_philo);
	while (i < philo->nbr_of_philo)
	{
		//parse_input(&philo[i], av);
		data[i].full = false;
		data[i].is_dead = false;
		data[i].time_last_meal = get_current_time();
		data[i].philo_id = i + 1;
		if (i < philo->nbr_of_philo - 1)
			data[i].left_fork = &data[i + 1].right_fork;
		else
			data[i].left_fork = &data[0].right_fork;
		pthread_mutex_init(&philo[i].right_fork, NULL);
		//	return (false);
		i++;
	}
	philo_run(philo);
	return (true);
}

