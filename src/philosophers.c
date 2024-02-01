/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:18:28 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/30 11:20:22 by vitenner         ###   ########.fr       */
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

int	ft_usleep(size_t milliseconds)
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

void *philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg; 
    // test_timeod();
    // Philosopher routine implementation
    // Cast arg to t_philo* and use it for philosopher's behavior
	while (!(*philo->dead))
	{
		printf("%ld %d is eating\n", get_current_time(), philo->id);
        philo->eating = 1;
        philo->last_meal = get_current_time();
        ft_usleep(philo->time_to_eat);
        philo->eating = 0;
		printf("%ld %d is sleeping\n", get_current_time(), philo->id);
		ft_usleep(philo->time_to_sleep);
		printf("%ld %d is thinking\n", get_current_time(), philo->id);
		ft_usleep(1000);

	}


    return NULL;
}
size_t get_time_in_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (size_t)((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
int main(int argc, char **argv)
{
	if (!parsing(argc, argv))
		return (0);
	else
		printf("all good\n");

	t_program program;
    t_philo philos[atoi_num_only(argv[1])]; // Declare array of t_philo on the stack
    int i;

    // Initialize mutexes and other shared resources
    pthread_mutex_init(&program.dead_lock, NULL);
    pthread_mutex_init(&program.meal_lock, NULL);
    pthread_mutex_init(&program.write_lock, NULL);
    program.dead_flag = 0;

    // Set the program's philosopher pointer to the array
    program.philos = philos;

    // Initialize philosophers
    for (i = 0; i < atoi_num_only(argv[1]); i++)
	{
        program.philos[i].id = i;
        program.philos[i].eating = 0;
        program.philos[i].meals_eaten = 0;
        program.philos[i].last_meal = 0;
        program.philos[i].time_to_die = atoi_num_only(argv[2]);
        program.philos[i].time_to_eat = atoi_num_only(argv[3]);
        program.philos[i].time_to_sleep = atoi_num_only(argv[4]);
        program.philos[i].start_time = get_current_time();
        program.philos[i].num_of_philos = atoi_num_only(argv[1]);
        program.philos[i].num_times_to_eat = atoi_num_only(argv[5]);
        program.philos[i].dead = &program.dead_flag;
		
        // Initialize other fields...
        program.philos[i].dead_lock = &program.dead_lock;
        program.philos[i].meal_lock = &program.meal_lock;
        program.philos[i].write_lock = &program.write_lock;
        // Initialize forks (mutexes) here or assign shared forks
    }

    // Create philosopher threads
    for (i = 0; i < atoi_num_only(argv[1]); i++) 
	{
        pthread_create(&program.philos[i].thread, NULL, philosopher_routine, &program.philos[i]);
    }
	// print_all_philos(&program);

    // Join philosopher threads
    for (i = 0; i < atoi_num_only(argv[1]); i++) {
        pthread_join(program.philos[i].thread, NULL);
    }
    // Cleanup
    pthread_mutex_destroy(&program.dead_lock);
    pthread_mutex_destroy(&program.meal_lock);
    pthread_mutex_destroy(&program.write_lock);

	return (1);
}
