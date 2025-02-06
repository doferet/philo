/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:23:16 by doferet           #+#    #+#             */
/*   Updated: 2025/02/06 10:35:38 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// fonction void *je_mange;
// fonction void *je_pense;
// fonction void *je_dors;
// (dans l ordre)
// a donner a la routine des threads 

/*void *print_message_function(void *ptr)
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
     return(NULL);
}*/
//nubers_of_philosophers = nb de thread
//fonction de creation de threads et tant qu'il 
//n'y a pas le bon nom de thread on continue ?

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac != 5)
		check_error("Wrong input. Try with 5 or 6 arguments.\n"
			"ex: ./philo 5 800 200 200");
	//parse_input(&philo, av);
	initialization(&philo, av);
	return (0);
}

// message a print : 
//      has taken a fork, 
//      is eating, 
//      is thinking, 
//      is spleeping,
//      died,
