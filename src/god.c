/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:55:40 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/16 10:57:45 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!death(philo))
	{
		bethlehem(philo);
		gethsemane(philo);
		mountsinai(philo);
	}
	return (arg);
}

int	cana(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*god(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
		if (peter(philos) == 1 || cana(philos) == 1)
			break ;
	return (arg);
}
