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

# include "philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int		ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void    test_timeod(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("Seconds since Epoch: %ld\n", tv.tv_sec);
	printf("Microseconds: %ld\n", tv.tv_usec);
}

void    bethlehem(t_philo *philo)
{
	// take left fork
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);

	// take right fork
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);

	// meal starts
	philo->last_meal = get_current_time();
	philo->eating = 1;
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d is eating\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	ft_usleep(philo->time_to_eat);

	// unlock
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);

	// meal ends
	philo->meals_eaten += 1;
	philo->eating = 0;
}

void    gethsemane(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d is sleeping\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	ft_usleep(philo->time_to_sleep);
}

void    mountsinai(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_current_time(), philo->id);
	ft_usleep(1000);
}

void	death(t_philo *philo)
{
	int	sentence;

	sentence = get_current_time() - philo->last_meal - philo->time_to_die;
	if (sentence < 0)
	{
		pthread_mutex_lock(philo->dead_lock);
		*(philo->dead) = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_lock(philo->write_lock);
		printf("💀 %ld %d died\n", get_current_time(), philo->id);
		// printf("%ld %d died\n", get_current_time(), philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
}

void *life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!(*philo->dead))
	{
		death(philo);
		bethlehem(philo);
		gethsemane(philo);
		mountsinai(philo);
	}
	return (NULL);
}

size_t get_time_in_ms() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (size_t)((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[201];
	pthread_mutex_t	forks[201];


	if (!revelation(argc, argv))
		return (0);
	init_program(&program, philos);
	spawn_forks(forks, atoi_num_only(argv[1]));
	init_philosophers(&program, philos, argv, forks);
	spawn_philos(philos, life);
	cleanup(&program, forks, atoi_num_only(argv[1]));
	return (1);
}