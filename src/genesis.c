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

void	init_program(t_program *program, t_philo *philos)
{
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	program->dead_flag = 0;
	program->philos = philos;
}

static void	init_philosophers(t_program *p, t_philo *philos, char **argv)
{
	int	i;

	i = 0;
	while (i < atoi_num_only(argv[1]))
	{
		philos[i].id = i;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].num_of_philos = atoi_num_only(argv[1]);
		philos[i].time_to_die = atoi_num_only(argv[2]);
		philos[i].time_to_eat = atoi_num_only(argv[3]);
		philos[i].time_to_sleep = atoi_num_only(argv[4]);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = philos[i].start_time;
		philos[i].num_times_to_eat = -1;
		if (argv[5])
			philos[i].num_times_to_eat = atoi_num_only(argv[5]);
		philos[i].dead = &p->dead_flag;
		i++;
	}
}

static void	init_forks(t_program *p, t_philo *philos, pthread_mutex_t *f)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philos)
	{
		philos[i].l_fork = &f[i];
		if (i == 0)
			philos[i].r_fork = &f[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &f[i - 1];
		philos[i].dead_lock = &p->dead_lock;
		philos[i].meal_lock = &p->meal_lock;
		philos[i].write_lock = &p->write_lock;
		i++;
	}
}

void	init_pf(t_program *p, t_philo *phil, char **a, pthread_mutex_t *f)
{
	init_philosophers(p, phil, a);
	init_forks(p, phil, f);
}

int	spawn_philos_and_god(t_program *program, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	god_thread;

	i = 0;
	if (pthread_create(&god_thread, NULL, &god, program->philos) != 0)
		cleanup(program, forks, program->philos[0].num_of_philos);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, \
		&life, &program->philos[i]) != 0)
			cleanup(program, forks, program->philos[0].num_of_philos);
		i++;
	}
	if (pthread_join(god_thread, NULL) != 0)
		cleanup(program, forks, program->philos[0].num_of_philos);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			cleanup(program, forks, program->philos[0].num_of_philos);
		i++;
	}
	return (0);
}
