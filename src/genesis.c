/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genesis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:22:56 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/01 14:29:03 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void    init_program(t_program *program, t_philo *philos)
{
	// Initialize mutexes and other shared resources
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	program->dead_flag = 0;

	// Set the program's philosopher pointer to the array
	program->philos = philos;
}

void    init_philosophers(t_program *program, t_philo *philos, char **argv, pthread_mutex_t *forks)
{
	int i;

	i = 0;
		// Initialize philosophers
	for (i = 0; i < atoi_num_only(argv[1]); i++)
	{
		philos[i].id = i;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = 0;
		philos[i].time_to_die = atoi_num_only(argv[2]);
		philos[i].time_to_eat = atoi_num_only(argv[3]);
		philos[i].time_to_sleep = atoi_num_only(argv[4]);
		philos[i].start_time = get_current_time();
		philos[i].num_of_philos = atoi_num_only(argv[1]);
		philos[i].num_times_to_eat = atoi_num_only(argv[5]);
		philos[i].dead = &program->dead_flag;

		// forks
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		// Initialize other fields->->->
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].write_lock = &program->write_lock;
		// Initialize forks (mutexes) here or assign shared forks
	}
}

void    spawn_philos(t_philo *philos, void *(*life)(void *))
{
		for (int i = 0; i < philos[i].num_of_philos; i++) {
		pthread_create(&philos[i].thread, NULL, life, &philos[i]);

	}
		for (int i = 0; i < philos[i].num_of_philos; i++) {
		pthread_join(philos[i].thread, NULL);
	}
}

void	spawn_forks(pthread_mutex_t *forks, int num_forks)
{
	// forks
	for (int i = 0; i < num_forks; i++) {
		pthread_mutex_init(&forks[i], NULL);
	}
}