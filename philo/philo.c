/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:23:16 by doferet           #+#    #+#             */
/*   Updated: 2025/02/10 18:36:18 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac > 6)
		check_error("Wrong input. Try with 5 or 6 arguments.\n"
			"ex: ./philo 5 800 200 200");
	initialization(&philo, av);
	//free_philo(&philo);
	return (0);
}
