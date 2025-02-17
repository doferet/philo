/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:27:13 by doferet           #+#    #+#             */
/*   Updated: 2025/02/17 13:01:23 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	write_error(const char *error)
{
	printf("%s\n", error);
	return (0);
}

static bool	verif_minmax(char **av)
{
	if (ft_atol(av[2]) >= 2147483647 || ft_atol(av[2]) <= -2147483648
		|| ft_atol(av[3]) >= 2147483647 || ft_atol(av[3]) <= -2147483648
		|| ft_atol(av[4]) >= 2147483647 || ft_atol(av[4]) <= -2147483648
		|| (ft_atol(av[5]) && ft_atol(av[5]) >= 2147483647)
		|| ft_atol(av[5]) <= -2147483648)
	{
		write_error("Wrong input. Try with 5 or 6 arguments.\n"
			"ex: ./philo 5 800 200 200");
		return (true);
	}
	return (false);
}

bool	check_error(int ac, char **av)
{
	if (ac == 1 || ac < 5 || ac > 6)
	{
		write_error("Wrong input. Try with 5 or 6 arguments.\n"
			"ex: ./philo 5 800 200 200");
		return (true);
	}
	if (verif_minmax(av))
		return (true);
	if (ft_atol(av[1]) > PHILO_MAX || ft_atol(av[1]) <= 0 || !ft_isdigit(av[1])
		|| ft_atol(av[2]) <= 0 || !ft_isdigit(av[2])
		|| ft_atol(av[3]) <= 0 || !ft_isdigit(av[3])
		|| ft_atol(av[4]) <= 0 || !ft_isdigit(av[4]))
	{
		write_error("Wrong input. Try with ex: ./philo 5 800 200 200");
		return (true);
	}
	if (av[5])
	{
		if (ft_atol(av[5]) <= 0 || !ft_isdigit(av[5]))
		{
			write_error("Wrong input. Try with ex: ./philo 5 800 200 200");
			return (true);
		}
	}
	return (false);
}
