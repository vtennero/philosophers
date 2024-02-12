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

#include "philosophers.h"

void init_program(t_program *program, t_philo *philos)
{
	// Initialize mutexes and other shared resources
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	program->dead_flag = 0;

	// Set the program's philosopher pointer to the array
	program->philos = philos;
}

void init_philosophers(t_program *program, t_philo *philos, char **argv, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	// Initialize philosophers
	for (i = 0; i < atoi_num_only(argv[1]); i++)
	{
		philos[i].id = i;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].time_to_die = atoi_num_only(argv[2]);
		philos[i].time_to_eat = atoi_num_only(argv[3]);
		philos[i].time_to_sleep = atoi_num_only(argv[4]);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = philos[i].start_time;
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

void spawn_philos(t_philo *philos, void *(*life)(void *))
{
	int i;

	i = 0;
	while (i < philos[i].num_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, life, &philos[i]);
		i++;
	}
	i = 0;
	while (i < philos[i].num_of_philos)
	{
		// pthread_mutex_lock(philos->write_lock);
		// printf("%ld spawn_philos: pthread_join(philos[%d].thread, NULL);\n", get_current_time(), i);
		// pthread_mutex_unlock(philos->write_lock);
		pthread_join(philos[i].thread, NULL);
		i++;
		// pthread_mutex_lock(philos->write_lock);
		// printf("%ld spawn_philos: pthread_join end of loop\n", get_current_time());
		// pthread_mutex_unlock(philos->write_lock);
	}
	// pthread_mutex_lock(philos->write_lock);
	// printf("%ld spawn_philos END %d\n", get_current_time(), philos->id);
	// pthread_mutex_unlock(philos->write_lock);
}

void	*life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (philo->id % 2 == 0)
	// 	ft_usleep(1);
	while (!death(philo))
	{
		bethlehem(philo);
		gethsemane(philo);
		mountsinai(philo);
	}
	return (arg);
}

void	*god(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
		if (peter(philos) == 1)
		// if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (arg);
}

int		spawn_philos_and_god(t_program *program, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	god_thread;

	(void)forks;

	i = 0;
	pthread_create(&god_thread, NULL, &god, program->philos);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_create(&program->philos[i].thread, NULL, &life, &program->philos[i]);
		i++;
	}
	pthread_join(god_thread, NULL);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
	return (0);
}

void spawn_forks(pthread_mutex_t *forks, int num_forks)
{
	int i;

	i = 0;
	while (i < num_forks)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}