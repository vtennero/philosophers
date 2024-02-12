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

int can_continue(t_philo *philo)
{
    int result;

    pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		result = 0;
	else
		result = 1;
    pthread_mutex_unlock(philo->dead_lock);
    return (result);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (can_continue(philo))
	{
        pthread_mutex_lock(philo->write_lock);
        // printf("%ld %d has taken a left fork\n", get_current_time(), philo->id);
        printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
    	printf("philo %d locked left fork number %d\n", philo->id, philo->id);
        pthread_mutex_unlock(philo->write_lock);
    }
}

void take_right_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    int right_fork_number = (philo->id == philo->num_of_philos - 1) ? 0 : philo->id + 1;
	if (can_continue(philo))
	{
        pthread_mutex_lock(philo->write_lock);
        printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
    	printf("philo %d locked right fork number %d\n", philo->id, right_fork_number);
        pthread_mutex_unlock(philo->write_lock);
    }
}

int	philo_is_eating(t_philo *philo)
{
	int result;

	pthread_mutex_lock(philo->write_lock);
	printf("philo_is_eating\n");
	pthread_mutex_unlock(philo->write_lock);

    pthread_mutex_lock(philo->meal_lock);
	if (philo->eating)
		result = 1;
	else
		result = 0;
    pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_lock(philo->write_lock);
	printf("philo_is_eating end\n");
	pthread_mutex_unlock(philo->write_lock);
    return (result);
}

void	unlock_dead_meal(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    pthread_mutex_unlock(philo->meal_lock);
}

void unlock_dead_forks1(void *arg)
{
    t_philo *philo = (t_philo *)arg;
	pthread_mutex_lock(philo->write_lock);
	printf("unlockl dead forks\n");
	pthread_mutex_unlock(philo->write_lock);
	
	if (philo_is_eating(philo))
	{
		pthread_mutex_lock(philo->write_lock);
        printf("%ld %d was eating and died!\n", get_current_time(), philo->id);
        pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	pthread_mutex_lock(philo->write_lock);
	printf("unlockl dead forks end\n");
	pthread_mutex_unlock(philo->write_lock);
}

void unlock_dead_forks(void *arg)
{
    t_philo *philo = (t_philo *)arg;

	pthread_mutex_lock(philo->write_lock);
	printf("unlockl dead forks\n");
	printf("%ld %d was eating and died!\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	printf("unlockl dead forks end\n");
	pthread_mutex_unlock(philo->write_lock);
}

void bethlehem(t_philo *philo)
{

	take_left_fork(philo);
	take_right_fork(philo);
    if (can_continue(philo))
	{
        pthread_mutex_lock(philo->meal_lock);
        philo->last_meal = get_current_time();
        philo->eating = 1;
        pthread_mutex_lock(philo->write_lock);
        printf("%ld %d is eating\n", get_current_time(), philo->id);
        pthread_mutex_unlock(philo->write_lock);
        ft_usleep(philo->time_to_eat);
		philo->meals_eaten += 1;
    	philo->eating = 0;
        pthread_mutex_unlock(philo->meal_lock);
    }
    // Unlock forks and update status
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d bethlehem ends\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);
}

void bethlehem2(t_philo *philo)
{
	// DEBUG
	// pthread_mutex_lock(philo->write_lock);
	// printf("%ld %d bethlehem starts\n", get_current_time(), philo->id);
	// pthread_mutex_unlock(philo->write_lock);
	// DEBUG

    // if (!can_continue(philo)) return;

	pthread_mutex_lock(philo->l_fork);
    // if (!can_continue(philo)) return;

    if (can_continue(philo))
	{
        pthread_mutex_lock(philo->write_lock);
        // printf("%ld %d has taken a left fork\n", get_current_time(), philo->id);
        printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
        pthread_mutex_unlock(philo->write_lock);
    }

	// Take right fork
	pthread_mutex_lock(philo->r_fork);
    // if (!can_continue(philo)) return;

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
		philo->meals_eaten += 1;
    	philo->eating = 0;
    }
    // Unlock forks and update status
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d bethlehem ends\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);
}

void gethsemane(t_philo *philo)
{
	// pthread_mutex_lock(philo->write_lock);
	// printf("%ld %d gethsemane starts\n", get_current_time(), philo->id);
	// pthread_mutex_unlock(philo->write_lock);

    // if (!can_continue(philo)) return;

	// printf("philo %d gethsemane\n", philo->id);
	if (can_continue(philo))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d is sleeping\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	ft_usleep(philo->time_to_sleep);
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d gethsemane ends\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);
}

void mountsinai(t_philo *philo)
{

	print_message("is thinking", philo, philo->id);
	// pthread_mutex_lock(philo->write_lock);
	// printf("%ld %d mountsinai starts\n", get_current_time(), philo->id);
	// pthread_mutex_unlock(philo->write_lock);

    // // if (!can_continue(philo)) return;

	// // printf("philo %d mountsinai\n", philo->id);
	// if (can_continue(philo))
	// {
	// 	pthread_mutex_lock(philo->write_lock);
	// 	printf("%ld %d is thinking\n", get_current_time(), philo->id);
	// 	pthread_mutex_unlock(philo->write_lock);
	// }
	// ft_usleep(1000);
	// pthread_mutex_lock(philo->write_lock);
	// printf("%ld %d mountsinai ends\n", get_current_time(), philo->id);
	// pthread_mutex_unlock(philo->write_lock);
}
