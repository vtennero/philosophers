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

int	death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	peter(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (philosopher_dead(&philos[i], philos[i].time_to_die))
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}



int	main(int argc, char **argv)
{
	t_program			program;
	t_philo				philos[201];
	pthread_mutex_t		forks[201];
	// pthread_t			god_thread;

	if (!revelation(argc, argv))
		return (0);
	print_params(argc, argv);
	init_program(&program, philos);
	spawn_forks(forks, atoi_num_only(argv[1]));
	init_philosophers(&program, philos, argv, forks);
	spawn_philos_and_god(&program, forks);
	// pthread_create(&god_thread, NULL, god, &program);
	// spawn_philos(philos, life);
	// pthread_join(god_thread, NULL);
	
	cleanup(&program, forks, atoi_num_only(argv[1]));
	return (1);
}