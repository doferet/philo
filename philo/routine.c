/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:41:48 by doferet           #+#    #+#             */
/*   Updated: 2025/02/06 17:57:37 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//eat, sleep, think

// faire des boucles dans des boucles pour que ca fonctionne
// boucle manger = s'il y a des fourchettes de dispo je les prends
//ensuite je les lache des que j'ai fini
// boucle dormir = une fois que j'ai fini de manger
//je dors le temps indique, verifier le temps de mourir
// boucle penser = si je viens de me reveiller
//et qu'il n'y a aucune fourchette de dispo, je pense
// tant que les philos sont pas morts on continue
// si un philo meurt, fin de la simulation


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
	{
		//printf("ID PHILO : %d\n", philo->philo_id);
		ft_usleep(200);
	}
	while (philo->is_dead == false)
	{
		if (philo->is_dead == true)
			return (NULL);
		philo_eat(philo);
		if (philo->is_dead == true)
			return (NULL);
		philo_sleep(philo);
		if (philo->is_dead == true)
			return (NULL);
		philo_think(philo);
	}
	return (NULL);
}
