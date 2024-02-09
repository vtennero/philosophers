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

int can_continue(t_philo *philo) {
    int result;
    pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		result = 0;
	else
		result = 1;
    pthread_mutex_unlock(philo->dead_lock);
    return result;
}

void bethlehem(t_philo *philo)
{
    if (!can_continue(philo)) return;

    pthread_mutex_lock(philo->l_fork);
    if (!can_continue(philo)) return;

    if (can_continue(philo))
	{
        pthread_mutex_lock(philo->write_lock);
        printf("%ld %d has taken a left fork\n", get_current_time(), philo->id);
        pthread_mutex_unlock(philo->write_lock);
    }

    // Take right fork
    pthread_mutex_lock(philo->r_fork);
    if (!can_continue(philo)) return;

    if (can_continue(philo))
	{
        pthread_mutex_lock(philo->write_lock);
        printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
        pthread_mutex_unlock(philo->write_lock);
    }
    // Meal starts
    if (can_continue(philo))
	{
        philo->last_meal = get_current_time();
        philo->eating = 1;
        pthread_mutex_lock(philo->write_lock);
        printf("%ld %d is eating\n", get_current_time(), philo->id);
        pthread_mutex_unlock(philo->write_lock);
        ft_usleep(philo->time_to_eat);
    }

    // Unlock forks and update status
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
    philo->meals_eaten += 1;
    philo->eating = 0;
}

// v1 bethelhem - doesnt handle dead flag properly

void bethlehem1(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	int is_dead = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	// pthread_mutex_lock(philo->write_lock);
	// printf("philo %d bethlehem deadflag? %d\n", philo->id, *philo->dead);
	// pthread_mutex_unlock(philo->write_lock);

	// take left fork
	pthread_mutex_lock(philo->l_fork);
	if (!(is_dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	// take right fork
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->dead_lock);
	is_dead = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	if (!(is_dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	// meal starts
	philo->last_meal = get_current_time();
	philo->eating = 1;
	pthread_mutex_lock(philo->dead_lock);
	is_dead = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	if (!(is_dead))
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
	// }
	// printf("philo %d bethlehem ends\n", philo->id);
}

void gethsemane(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	int is_dead = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	// printf("philo %d gethsemane\n", philo->id);
	if (!(is_dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d is sleeping\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	ft_usleep(philo->time_to_sleep);
}

void mountsinai(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	int is_dead = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	// printf("philo %d mountsinai\n", philo->id);
	if (!(is_dead))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d is thinking\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	ft_usleep(1000);
}