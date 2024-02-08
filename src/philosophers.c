/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:18:28 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/01 14:57:40 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void death(t_philo *philo)
{
	// Calculate the time since the last meal
	size_t time_since_last_meal = get_current_time() - philo->last_meal;

	// Check if the philosopher has died
	if (time_since_last_meal > philo->time_to_die)
	{
		pthread_mutex_lock(philo->dead_lock);
		*(philo->dead) = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_lock(philo->write_lock);
		printf("💀 %ld %d died\n", get_current_time(), philo->id);
		// printf("💀 %ld %d died\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
}

void *life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!(*philo->dead))
	{
		printf("philo %d cycle philo->dead: %d\n", philo->id, *philo->dead);
		death(philo);
		bethlehem(philo);
		gethsemane(philo);
		mountsinai(philo);
		printf("philo %d cycle philo->dead: %d end of while loop\n", philo->id, *philo->dead);
	}
	printf("one philo is dead\n");
	return (NULL);
}

void *god(void *arg)
{
	t_program *program = (t_program *)arg;
	size_t current_time;

	while (!program->dead_flag)
	{

		for (int i = 0; i < program->philos[0].num_of_philos; i++)
		{
			pthread_mutex_lock(&program->philos[i].write_lock); // Corrected
			current_time = get_current_time();
			if (program->philos[i].eating == 0 && (current_time - program->philos[i].last_meal > program->philos[i].time_to_die))
			{
				printf("💀 %ld %d died\n", get_current_time(), program->philos[i].id);
				pthread_mutex_unlock(&program->philos[i].write_lock); // Corrected
				pthread_mutex_lock(&program->dead_lock);
				program->dead_flag = 1;
				pthread_mutex_unlock(&program->dead_lock);
				break;
			}
			pthread_mutex_unlock(&program->philos[i].write_lock); // Corrected
		}
		ft_usleep(10);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_program program;
	t_philo philos[201];
	pthread_mutex_t forks[201];
	pthread_mutex_t god_thread;

	if (!revelation(argc, argv))
		return (0);
	init_program(&program, philos);
	spawn_forks(forks, atoi_num_only(argv[1]));
	init_philosophers(&program, philos, argv, forks);
	pthread_create(&god_thread, NULL, god, &program);
	spawn_philos(philos, life);
	pthread_join(god_thread, NULL);
	cleanup(&program, forks, atoi_num_only(argv[1]));
	return (1);
}