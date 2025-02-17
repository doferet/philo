/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:09 by doferet           #+#    #+#             */
/*   Updated: 2025/02/17 15:33:12 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

bool	verif_death_full(t_philo *philo, t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->dead);
	if (philo[0].is_dead == true)
		return (pthread_mutex_unlock(&mutex->dead), true);
	pthread_mutex_unlock(&mutex->dead);
	pthread_mutex_lock(&mutex->meal);
	if (philo->full == true)
		return (pthread_mutex_unlock(&mutex->meal), true);
	pthread_mutex_unlock(&mutex->meal);
	return (false);
}

int	ft_isdigit(char *str)
{
	int		i;
	bool	check;

	i = 0;
	check = true;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			check = false;
		i++;
	}
	return (check);
}
