/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:33:39 by doferet           #+#    #+#             */
/*   Updated: 2024/09/04 16:09:55 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//dans ce fichier, je dois creer mes PHILO donc les THREAD
//initialisation des variables

int initialization(t_philo *philo, int ac, char **av)
{
    if (ac < 5)
    {
        printf("Error: too few arguments. Try with 5 or 6");
        return (0);
    }
    philo->nbr_of_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
    philo->must_eat = -1;
}
