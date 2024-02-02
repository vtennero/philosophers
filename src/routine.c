/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:51:02 by marvin            #+#    #+#             */
/*   Updated: 2024/02/03 15:51:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void bethlehem(t_philo *philo)
{
	printf("philo %d bethlehem\n", philo->id);

	// take left fork
	pthread_mutex_lock(philo->l_fork);
	if (!(*philo->dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	// take right fork
	pthread_mutex_lock(philo->r_fork);
	if (!(*philo->dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	// meal starts
	philo->last_meal = get_current_time();
	philo->eating = 1;
	if (!(*philo->dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d is eating\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	ft_usleep(philo->time_to_eat);

	// unlock
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);

	// meal ends
	philo->meals_eaten += 1;
	philo->eating = 0;
	printf("philo %d bethlehem ends\n", philo->id);
}

void gethsemane(t_philo *philo)
{
	printf("philo %d gethsemane\n", philo->id);
	if (!(*philo->dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d is sleeping\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	ft_usleep(philo->time_to_sleep);
}

void mountsinai(t_philo *philo)
{
	printf("philo %d mountsinai\n", philo->id);
	if (!(*philo->dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d is thinking\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	ft_usleep(1000);
}